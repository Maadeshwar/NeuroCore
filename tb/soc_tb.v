`timescale 1ns/1ps

module soc_tb;

    reg clk;
    reg rst_n;
    
    // SPI Dummy Signals
    wire spi_sclk;
    wire spi_mosi;
    wire spi_miso = 1'b0;
    wire spi_cs_n;

    // Instantiate the SoC Top
    soc_top dut (
        .clk(clk),
        .rst_n(rst_n),
        .spi_sclk(spi_sclk),
        .spi_mosi(spi_mosi),
        .spi_miso(spi_miso),
        .spi_cs_n(spi_cs_n)
    );

    // Clock Generation
    always #5 clk = ~clk;

    // Magic Address Monitor
    always @(posedge clk) begin
        if (dut.bus_req && dut.bus_we && dut.bus_addr == 32'h90000000) begin
            if (dut.bus_wdata == 32'h00000001) begin
                $display("\n========================================");
                $display(" SUCCESS: Full SoC Verification Passed! ");
                $display(" Firmware executed flawlessly.");
                $display("========================================\n");
                $finish;
            end else if (dut.bus_wdata == 32'hDEADBEEF) begin
                $display("\n========================================");
                $display(" FAILURE: Hardware Math Mismatch!       ");
                $display("========================================\n");
                $finish;
            end
        end
    end

    // Timeout Monitor
    initial begin
        #500000; // 500us timeout
        $display("\n========================================");
        $display(" TIMEOUT: Firmware did not complete.    ");
        $display("========================================\n");
        $finish;
    end

    initial begin
        $dumpfile("soc_tb.vcd");
        $dumpvars(0, soc_tb);

        clk = 0;
        rst_n = 0;
        
        $display("Initializing NeuroCore-SoC Testbench...");
        
        // Load Firmware into IMEM
        // Note: Requires compiled firmware.hex from firmware.c
        $readmemh("firmware.hex", dut.instr_ram);
        
        #100;
        rst_n = 1;
        
        $display("Reset released. Executing Firmware...");
    end

endmodule
