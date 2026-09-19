module mock_cpu (
    input clk,
    input rst_n,
    output reg data_req,
    input  wire data_gnt,
    input  wire data_rvalid,
    output reg data_we,
    output reg [3:0] data_be,
    output reg [31:0] data_addr,
    output reg [31:0] data_wdata,
    input  wire [31:0] data_rdata
);

    reg [7:0] state;
    reg [7:0] wait_cnt;
    
    // DMA addresses
    localparam DMA_SRC = 32'h60000000;
    localparam DMA_DST = 32'h60000004;
    localparam DMA_LEN = 32'h60000008;
    localparam DMA_START = 32'h6000000C;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= 0;
            wait_cnt <= 0;
            data_req <= 0;
            data_we <= 0;
            data_be <= 4'b1111;
        end else begin
            if (data_req && data_gnt) begin
                data_req <= 0; // single cycle pulse for this simple mock
                if (!data_we) state <= state + 1; // Wait for read in next block?
            end
            
            if (data_req == 0 && wait_cnt == 0) begin
                case (state)
                    // Init Weights (1 word at 10000000 = 0x01010101)
                    0: begin data_addr <= 32'h10000000; data_wdata <= 32'h01010101; data_req <= 1; data_we <= 1; state <= 1; end
                    
                    // Init Acts (1 word at 10000200 = 0x01010101)
                    1: begin data_addr <= 32'h10000200; data_wdata <= 32'h01010101; data_req <= 1; data_we <= 1; state <= 2; end
                    
                    // Trigger DMA for Weights (Source: 0x10000000, Dest: 0x30000000, Len: 1)
                    2: begin data_addr <= DMA_SRC; data_wdata <= 32'h10000000; data_req <= 1; data_we <= 1; state <= 3; end
                    3: begin data_addr <= DMA_DST; data_wdata <= 32'h30000000; data_req <= 1; data_we <= 1; state <= 4; end
                    4: begin data_addr <= DMA_LEN; data_wdata <= 32'd1;        data_req <= 1; data_we <= 1; state <= 5; end
                    5: begin data_addr <= DMA_START; data_wdata <= 32'd1;      data_req <= 1; data_we <= 1; wait_cnt <= 100; state <= 6; end
                    
                    // Trigger DMA for Acts (Source: 0x10000200, Dest: 0x20000000, Len: 1)
                    6: begin data_addr <= DMA_SRC; data_wdata <= 32'h10000200; data_req <= 1; data_we <= 1; state <= 7; end
                    7: begin data_addr <= DMA_DST; data_wdata <= 32'h20000000; data_req <= 1; data_we <= 1; state <= 8; end
                    8: begin data_addr <= DMA_LEN; data_wdata <= 32'd1;        data_req <= 1; data_we <= 1; state <= 9; end
                    9: begin data_addr <= DMA_START; data_wdata <= 32'd1;      data_req <= 1; data_we <= 1; wait_cnt <= 100; state <= 10; end

                    // Send NPU Commands
                    // OP_LOAD_WEIGHTS (1), payload = 1
                    10: begin data_addr <= 32'hA0000000; data_wdata <= {4'd1, 28'd1}; data_req <= 1; data_we <= 1; state <= 11; end
                    // OP_SET_TILER (3), payload = 0
                    11: begin data_addr <= 32'hA0000000; data_wdata <= {4'd3, 28'd0}; data_req <= 1; data_we <= 1; state <= 12; end
                    // OP_RUN_MAC (2), payload = 1, finish_pass=1 (bit 26)
                    12: begin data_addr <= 32'hA0000000; data_wdata <= {4'd2, 1'b0, 1'b1, 26'd1}; data_req <= 1; data_we <= 1; wait_cnt <= 500; state <= 13; end

                    // Read OBUF[0] (0x40000000)
                    13: begin data_addr <= 32'h40000000; data_req <= 1; data_we <= 0; end
                    
                    // Verify output
                    14: begin
                        $display("NPU OBUF Output: %x", data_rdata);
                        // 1 * 1 = 1 per MAC. If it reads 1 or greater, math works
                        if (data_rdata != 0) begin 
                            // Pass
                            data_addr <= 32'h90000000; data_wdata <= 32'h00000001; data_req <= 1; data_we <= 1; state <= 15;
                        end else begin
                            // Fail
                            data_addr <= 32'h90000000; data_wdata <= 32'hDEADBEEF; data_req <= 1; data_we <= 1; state <= 15;
                        end
                    end
                    
                    15: begin
                        // Done
                    end
                endcase
            end
            
            if (wait_cnt > 0) wait_cnt <= wait_cnt - 1;
            
            if (data_rvalid && state == 13) begin
                state <= 14;
            end
        end
    end
endmodule
