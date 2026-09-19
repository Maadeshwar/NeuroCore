`default_nettype none

module dma_controller (
    input  wire clk,
    input  wire rst_n,

    // CPU Configuration Interface (MMIO)
    input  wire        cfg_req,
    input  wire        cfg_we,
    input  wire [3:0]  cfg_be,
    input  wire [7:0]  cfg_addr, // simplified offset
    input  wire [31:0] cfg_wdata,
    output reg  [31:0] cfg_rdata,
    output wire        cfg_done, // ack

    // DMA Master Read Interface (to Data RAM)
    output reg         dma_rd_req,
    output reg  [31:0] dma_rd_addr,
    input  wire        dma_rd_gnt,
    input  wire        dma_rd_valid,
    input  wire [31:0] dma_rd_data,

    // DMA Master Write Interface (to Accelerator SRAMs)
    output reg         dma_wr_req,
    output reg  [31:0] dma_wr_addr,
    output reg  [31:0] dma_wr_data,
    input  wire        dma_wr_gnt,
    
    // Status
    output wire        dma_busy,
    output reg         dma_done_irq
);

    // Registers
    reg [31:0] src_addr;
    reg [31:0] dst_addr;
    reg [31:0] transfer_len; // in 32-bit words
    reg        start;

    assign cfg_done = cfg_req; // 0-wait state config

    // Config logic
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            src_addr <= 0;
            dst_addr <= 0;
            transfer_len <= 0;
            start <= 0;
            cfg_rdata <= 0;
        end else begin
            start <= 0; // pulse
            if (cfg_req) begin
                if (cfg_we) begin
                    case (cfg_addr[7:2])
                        6'h0: src_addr <= cfg_wdata;
                        6'h1: dst_addr <= cfg_wdata;
                        6'h2: transfer_len <= cfg_wdata;
                        6'h3: start <= cfg_wdata[0];
                    endcase
                end else begin
                    case (cfg_addr[7:2])
                        6'h0: cfg_rdata <= src_addr;
                        6'h1: cfg_rdata <= dst_addr;
                        6'h2: cfg_rdata <= transfer_len;
                        6'h3: cfg_rdata <= {31'b0, dma_busy};
                        default: cfg_rdata <= 0;
                    endcase
                end
            end
        end
    end

    // DMA FSM
    localparam S_IDLE  = 2'd0;
    localparam S_READ  = 2'd1;
    localparam S_WRITE = 2'd2;

    reg [1:0] state, next_state;
    reg [31:0] words_left;
    
    assign dma_busy = (state != S_IDLE);

    // Stage 1: Sequential State Update
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= S_IDLE;
        end else begin
            state <= next_state;
        end
    end

    // Stage 2: Combinational Next-State Logic
    always @(*) begin
        next_state = state;
        case (state)
            S_IDLE: begin
                if (start && transfer_len > 0) next_state = S_READ;
            end
            S_READ: begin
                if (dma_rd_valid) next_state = S_WRITE;
            end
            S_WRITE: begin
                if (dma_wr_gnt) begin
                    if (words_left == 1) next_state = S_IDLE;
                    else next_state = S_READ;
                end
            end
            default: next_state = S_IDLE;
        endcase
    end

    // Stage 3: Sequential Output Logic
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dma_rd_req <= 0;
            dma_wr_req <= 0;
            dma_done_irq <= 0;
            words_left <= 0;
            dma_rd_addr <= 0;
            dma_wr_addr <= 0;
            dma_wr_data <= 0;
        end else begin
            dma_done_irq <= 0;
            
            case (state)
                S_IDLE: begin
                    if (start && transfer_len > 0) begin
                        words_left <= transfer_len;
                        dma_rd_addr <= src_addr;
                        dma_wr_addr <= dst_addr;
                        dma_rd_req <= 1;
                    end
                end
                
                S_READ: begin
                    if (dma_rd_gnt) dma_rd_req <= 0; // Clear request once granted
                    if (dma_rd_valid) begin
                        dma_wr_data <= dma_rd_data;
                        dma_wr_req <= 1;
                    end
                end
                
                S_WRITE: begin
                    if (dma_wr_gnt) begin
                        dma_wr_req <= 0;
                        words_left <= words_left - 1;
                        dma_rd_addr <= dma_rd_addr + 4;
                        dma_wr_addr <= dma_wr_addr + 4;
                        
                        if (words_left == 1) begin
                            dma_done_irq <= 1;
                        end else begin
                            dma_rd_req <= 1;
                        end
                    end
                end
            endcase
        end
    end

endmodule
