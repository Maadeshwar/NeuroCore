`default_nettype none

module skew_buffer #(
    parameter N = 16,
    parameter DATA_WIDTH = 8
)(
    input  wire                   clk,
    input  wire                   rst_n,
    input  wire                   en,
    input  wire [N*DATA_WIDTH-1:0] data_in,
    output wire [N*DATA_WIDTH-1:0] data_out
);
    
    genvar i, j;
    generate
        for (i = 0; i < N; i = i + 1) begin : skew_row
            if (i == 0) begin
                assign data_out[DATA_WIDTH-1:0] = data_in[DATA_WIDTH-1:0];
            end else begin
                // Need i registers for row i
                wire [DATA_WIDTH-1:0] delay_line [0:i];
                assign delay_line[0] = data_in[i*DATA_WIDTH +: DATA_WIDTH];
                
                for (j = 0; j < i; j = j + 1) begin : dff
                    reg [DATA_WIDTH-1:0] q;
                    always @(posedge clk or negedge rst_n) begin
                        if (!rst_n) q <= 0;
                        else if (en) q <= delay_line[j];
                    end
                    assign delay_line[j+1] = q;
                end
                assign data_out[i*DATA_WIDTH +: DATA_WIDTH] = delay_line[i];
            end
        end
    endgenerate

endmodule

module unskew_buffer #(
    parameter N = 16,
    parameter DATA_WIDTH = 32
)(
    input  wire                   clk,
    input  wire                   rst_n,
    input  wire                   en,
    input  wire [N*DATA_WIDTH-1:0] data_in,
    output wire [N*DATA_WIDTH-1:0] data_out,
    output wire                   valid_out
);

    // Unskewing means delaying row i by (N-1 - i) cycles
    // So that all elements of a column arrive at the same time.
    
    // We will generate valid_out based on en delayed by (2N-1) (N for array + N-1 for unskew)
    reg [2*N-1:0] valid_shift;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) valid_shift <= 0;
        else if (en) valid_shift <= {valid_shift[2*N-2:0], 1'b1};
        else valid_shift <= {valid_shift[2*N-2:0], 1'b0};
    end
    assign valid_out = valid_shift[2*N-2];

    genvar i, j;
    generate
        for (i = 0; i < N; i = i + 1) begin : unskew_row
            localparam DELAY = N - 1 - i;
            if (DELAY == 0) begin
                assign data_out[i*DATA_WIDTH +: DATA_WIDTH] = data_in[i*DATA_WIDTH +: DATA_WIDTH];
            end else begin
                wire [DATA_WIDTH-1:0] delay_line [0:DELAY];
                assign delay_line[0] = data_in[i*DATA_WIDTH +: DATA_WIDTH];
                
                for (j = 0; j < DELAY; j = j + 1) begin : dff
                    reg [DATA_WIDTH-1:0] q;
                    always @(posedge clk or negedge rst_n) begin
                        if (!rst_n) q <= 0;
                        else if (en || valid_shift != 0) q <= delay_line[j];
                    end
                    assign delay_line[j+1] = q;
                end
                assign data_out[i*DATA_WIDTH +: DATA_WIDTH] = delay_line[DELAY];
            end
        end
    endgenerate
endmodule
