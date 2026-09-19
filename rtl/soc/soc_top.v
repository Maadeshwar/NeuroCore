`default_nettype none

module soc_top (
    input  wire clk,
    input  wire        rst_n,
    
    // SPI Physical Pins
    output wire        spi_sclk,
    output wire        spi_mosi,
    input  wire        spi_miso,
    output wire        spi_cs_n
);

    // --------------------------------------------------------
    // Memory Map:
    // 0x0000_0000 - 0x0000_FFFF : Instruction RAM (64KB)
    // 0x0001_0000 - 0x0001_FFFF : Data RAM (64KB)
    // 0x1000_0000 - 0x1000_0FFF : NPU Command FIFO
    // 0x2000_0000 - 0x2000_3FFF : NPU IBUF
    // 0x3000_0000 - 0x3000_3FFF : NPU WBUF
    // 0x4000_0000 - 0x4000_3FFF : NPU OBUF
    // 0x5000_0000 - 0x5000_000F : NPU Config (quant_shift, relu_en)
    // 0x6000_0000 - 0x6000_001F : DMA Controller Config
    // 0x7000_0000 - 0x7000_3FFF : NPU PBUF (Biases)
    // 0x8000_0000 - 0x8000_000F : High-Speed SPI Master
    // 0xA000_0000 - 0xA000_000F : NPU Command FIFO
    // --------------------------------------------------------

    // Ibex Signals
    wire        instr_req, instr_gnt, instr_rvalid;
    wire [31:0] instr_addr, instr_rdata;
    wire        data_req, data_gnt, data_rvalid, data_we;
    wire [3:0]  data_be;
    wire [31:0] data_addr, data_wdata, data_rdata;
    
    // Interrupts
    wire dma_done_irq;
    wire npu_ready; // From Accelerator
    
    // We will route npu_ready (inverted, so it interrupts when going high/done) 
    // and dma_done_irq to Ibex fast interrupts.
    wire [14:0] irq_fast = {13'b0, npu_ready, dma_done_irq};

    ibex_core #(
        .Rv32e(0),
        .Rv32m(ibex_pkg::RV32MFast),
        .PMPEnable(0)
    ) cpu_core (
        .clk_i(clk), .rst_ni(rst_n), .test_en_i(1'b0), .scan_rst_ni(1'b1), .ram_cfg_i('0),
        .hart_id_i(32'b0), .boot_addr_i(32'h0000_0000),

        .instr_req_o(instr_req), .instr_gnt_i(instr_gnt), .instr_rvalid_i(instr_rvalid),
        .instr_addr_o(instr_addr), .instr_rdata_i(instr_rdata), .instr_err_i(1'b0),

        .data_req_o(data_req), .data_gnt_i(data_gnt), .data_rvalid_i(data_rvalid),
        .data_we_o(data_we), .data_be_o(data_be), .data_addr_o(data_addr),
        .data_wdata_o(data_wdata), .data_rdata_i(data_rdata), .data_err_i(1'b0),

        .irq_software_i(1'b0), .irq_timer_i(1'b0), .irq_external_i(1'b0),
        .irq_fast_i(irq_fast), .irq_nm_i(1'b0),
        
        .fetch_enable_i(1'b1), .core_sleep_o()
    );

    // --------------------------------------------------------
    // True Harvard Memories
    // --------------------------------------------------------
    reg [31:0] instr_ram [0:16383];
    reg [31:0] data_ram  [0:16383];
    
    // Instruction Fetch
    assign instr_gnt = instr_req;
    reg instr_rvalid_reg;
    reg [31:0] instr_rdata_reg;
    always @(posedge clk) begin
        if (!rst_n) instr_rvalid_reg <= 0;
        else begin
            instr_rvalid_reg <= instr_req;
            if (instr_req) instr_rdata_reg <= instr_ram[instr_addr[15:2]];
        end
    end
    assign instr_rvalid = instr_rvalid_reg;
    assign instr_rdata = instr_rdata_reg;

    // --------------------------------------------------------
    // DMA Controller
    // --------------------------------------------------------
    wire dma_rd_req, dma_rd_gnt, dma_rd_valid;
    wire [31:0] dma_rd_addr, dma_rd_data;
    wire dma_wr_req, dma_wr_gnt;
    wire [31:0] dma_wr_addr, dma_wr_data;
    wire dma_busy;
    
    wire is_cpu_dma_cfg = (data_addr[31:28] == 4'h6);
    wire dma_cfg_req = data_req && is_cpu_dma_cfg;
    wire [31:0] dma_cfg_rdata;
    wire dma_cfg_done;

    dma_controller i_dma (
        .clk(clk), .rst_n(rst_n),
        .cfg_req(dma_cfg_req), .cfg_we(data_we), .cfg_be(data_be),
        .cfg_addr(data_addr[7:0]), .cfg_wdata(data_wdata), .cfg_rdata(dma_cfg_rdata), .cfg_done(dma_cfg_done),
        
        .dma_rd_req(dma_rd_req), .dma_rd_addr(dma_rd_addr), .dma_rd_gnt(dma_rd_gnt),
        .dma_rd_valid(dma_rd_valid), .dma_rd_data(dma_rd_data),
        
        .dma_wr_req(dma_wr_req), .dma_wr_addr(dma_wr_addr), .dma_wr_data(dma_wr_data),
        .dma_wr_gnt(dma_wr_gnt), .dma_busy(dma_busy), .dma_done_irq(dma_done_irq)
    );

    // --------------------------------------------------------
    // Bus Arbiter (CPU vs DMA)
    // --------------------------------------------------------
    // DMA has priority over Data RAM and Accelerator peripherals
    
    wire bus_req   = dma_busy ? (dma_rd_req | dma_wr_req) : data_req;
    wire bus_we    = dma_busy ? dma_wr_req : data_we;
    wire [31:0] bus_addr = dma_busy ? (dma_rd_req ? dma_rd_addr : dma_wr_addr) : data_addr;
    wire [31:0] bus_wdata = dma_busy ? dma_wr_data : data_wdata;
    
    // Grants
    assign dma_rd_gnt = dma_rd_req; // simplified 0-wait
    assign dma_wr_gnt = dma_wr_req;
    assign data_gnt = !dma_busy && data_req; // CPU stalls if DMA is busy

    // Address Decoding
    wire is_dram  = (bus_addr[31:28] == 4'h1);
    wire is_fifo  = (bus_addr[31:28] == 4'hA);
    wire is_ibuf  = (bus_addr[31:28] == 4'h2);
    wire is_wbuf  = (bus_addr[31:28] == 4'h3);
    wire is_obuf  = (bus_addr[31:28] == 4'h4);
    wire is_cfg   = (bus_addr[31:28] == 4'h5);
    wire is_dma   = (bus_addr[31:28] == 4'h6);
    wire is_pbuf  = (bus_addr[31:28] == 4'h7);
    wire is_spi   = (bus_addr[31:28] == 4'h8);

    // Data RAM Access
    reg dram_rvalid_reg;
    reg [31:0] dram_rdata_reg;
    always @(posedge clk) begin
        if (!rst_n) dram_rvalid_reg <= 0;
        else begin
            dram_rvalid_reg <= bus_req && is_dram && !bus_we;
            if (bus_req && is_dram) begin
                if (bus_we) begin
                    // Simplified byte enables (CPU only, DMA writes 32-bit)
                    if (!dma_busy) begin
                        if (data_be[0]) data_ram[bus_addr[15:2]][7:0]   <= bus_wdata[7:0];
                        if (data_be[1]) data_ram[bus_addr[15:2]][15:8]  <= bus_wdata[15:8];
                        if (data_be[2]) data_ram[bus_addr[15:2]][23:16] <= bus_wdata[23:16];
                        if (data_be[3]) data_ram[bus_addr[15:2]][31:24] <= bus_wdata[31:24];
                    end else begin
                        data_ram[bus_addr[15:2]] <= bus_wdata;
                    end
                end else begin
                    dram_rdata_reg <= data_ram[bus_addr[15:2]];
                end
            end
        end
    end
    assign dma_rd_valid = dram_rvalid_reg && dma_busy;
    assign dma_rd_data  = dram_rdata_reg;

    // NPU Config Access
    reg [4:0] quant_shift;
    reg relu_en, pool_en;
    always @(posedge clk) begin
        if (!rst_n) begin quant_shift <= 0; relu_en <= 0; pool_en <= 0; end
        else if (bus_req && is_cfg && bus_we) begin
            quant_shift <= bus_wdata[4:0];
            relu_en <= bus_wdata[5];
            pool_en <= bus_wdata[6];
        end
    end

    // CPU Read Mux and Valid
    reg cpu_accel_rvalid_reg;
    always @(posedge clk) begin
        if (!rst_n) cpu_accel_rvalid_reg <= 0;
        else cpu_accel_rvalid_reg <= data_req && !dma_busy && !data_we && !is_dram;
    end
    
    wire [127:0] obuf_rd_data;
    wire [31:0]  spi_rdata;
    
    assign data_rvalid = dma_cfg_done || (data_req && !dma_busy && is_dram ? dram_rvalid_reg : cpu_accel_rvalid_reg);
    assign data_rdata = is_cpu_dma_cfg ? dma_cfg_rdata :
                        (is_dram ? dram_rdata_reg : 
                        (is_obuf ? obuf_rd_data[31:0] : 
                        (is_spi ? spi_rdata : 32'h0)));

    // --------------------------------------------------------
    // Accelerator Top Instantiation
    // --------------------------------------------------------
    wire cmd_push = bus_req && bus_we && is_fifo; // 0xA000_0000
    wire ibuf_we  = bus_req && bus_we && is_ibuf;
    wire wbuf_we  = bus_req && bus_we && is_wbuf;
    wire pbuf_we  = bus_req && bus_we && is_pbuf;
    
    wire cmd_full;
    
    accelerator_top #(
        .N(16), .DATA_WIDTH(8), .ACC_WIDTH(32)
    ) i_accelerator (
        .clk(clk), .rst_n(rst_n),
        .cmd_in(bus_wdata), .cmd_push(cmd_push), .cmd_full(cmd_full),
        
        .ibuf_wr_addr(bus_addr[13:4]), .ibuf_wr_data({96'b0, bus_wdata}), .ibuf_we(ibuf_we),
        .wbuf_wr_addr(bus_addr[13:4]), .wbuf_wr_data({96'b0, bus_wdata}), .wbuf_we(wbuf_we),
        .obuf_rd_addr(bus_addr[13:4]), .obuf_rd_data(obuf_rd_data),
        
        .pbuf_wr_addr(bus_addr[13:4]), .pbuf_wr_data({480'b0, bus_wdata}), .pbuf_we(pbuf_we),
        
        .quant_shift(quant_shift), .relu_en(relu_en), .pool_en(pool_en)
    );
    
    // --------------------------------------------------------
    // SPI Master Instantiation
    // --------------------------------------------------------
    spi_master i_spi (
        .clk(clk), .rst_n(rst_n),
        .bus_req(bus_req && is_spi),
        .bus_we(bus_we),
        .bus_addr(bus_addr[3:0]),
        .bus_wdata(bus_wdata),
        .bus_rdata(spi_rdata),
        .spi_sclk(spi_sclk),
        .spi_mosi(spi_mosi),
        .spi_miso(spi_miso),
        .spi_cs_n(spi_cs_n)
    );
    
    // We need to extract npu_ready from accelerator_top to drive the interrupt.
    // In Verilog, we can use hierarchical referencing for quick prototyping, 
    // or add it to the port list. Let's assume accelerator_top exposes it or we hierarchical ref it:
    assign npu_ready = i_accelerator.i_controller.npu_ready;

endmodule
