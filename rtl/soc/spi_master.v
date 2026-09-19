`default_nettype none

module spi_master (
    input  wire        clk,
    input  wire        rst_n,

    // Memory-Mapped Bus Interface
    input  wire        bus_req,
    input  wire        bus_we,
    input  wire [3:0]  bus_addr,   // 4 registers: TX, RX, STATUS, CTRL
    input  wire [31:0] bus_wdata,
    output reg  [31:0] bus_rdata,

    // SPI Physical Pins
    output reg         spi_sclk,
    output reg         spi_mosi,
    input  wire        spi_miso,
    output reg         spi_cs_n
);

    // Registers
    // 0x0 : TX Data (Write starts transfer)
    // 0x4 : RX Data (Read)
    // 0x8 : Status  (Bit 0: Busy)
    // 0xC : Control (Bit 0: CS_N Manual Override, [15:8]: Clock Divider)

    reg [31:0] tx_data;
    reg [31:0] rx_data;
    reg [7:0]  clk_div;
    reg        busy;

    // SPI State Machine
    localparam S_IDLE = 2'd0;
    localparam S_SCLK_LOW = 2'd1;
    localparam S_SCLK_HIGH = 2'd2;
    localparam S_DONE = 2'd3;

    reg [1:0] state;
    reg [4:0] bit_count;
    reg [7:0] div_counter;
    
    reg [31:0] shift_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            bus_rdata <= 0;
            spi_sclk <= 0;
            spi_mosi <= 0;
            spi_cs_n <= 1;
            tx_data <= 0;
            rx_data <= 0;
            clk_div <= 8'd2; // Default divider
            busy <= 0;
            state <= S_IDLE;
            bit_count <= 0;
            div_counter <= 0;
            shift_reg <= 0;
        end else begin
            // Bus Interface (Read)
            if (bus_req && !bus_we) begin
                case (bus_addr[3:2])
                    2'b00: bus_rdata <= tx_data;
                    2'b01: bus_rdata <= rx_data;
                    2'b10: bus_rdata <= {31'b0, busy};
                    2'b11: bus_rdata <= {16'b0, clk_div, 7'b0, spi_cs_n};
                endcase
            end

            // Bus Interface (Write)
            if (bus_req && bus_we) begin
                case (bus_addr[3:2])
                    2'b00: begin 
                        if (!busy) begin
                            tx_data <= bus_wdata;
                            shift_reg <= bus_wdata;
                            busy <= 1;
                            bit_count <= 31; // 32-bit transfer
                            state <= S_SCLK_LOW;
                            div_counter <= 0;
                            spi_sclk <= 0;
                        end
                    end
                    2'b11: begin
                        spi_cs_n <= bus_wdata[0];
                        clk_div  <= bus_wdata[15:8];
                    end
                endcase
            end

            // SPI FSM
            case (state)
                S_IDLE: begin
                    spi_sclk <= 0;
                    if (!busy) spi_mosi <= 0;
                end

                S_SCLK_LOW: begin
                    if (div_counter == clk_div) begin
                        div_counter <= 0;
                        spi_sclk <= 1;
                        spi_mosi <= shift_reg[31]; // MSB first
                        state <= S_SCLK_HIGH;
                    end else begin
                        div_counter <= div_counter + 1;
                    end
                end

                S_SCLK_HIGH: begin
                    if (div_counter == clk_div) begin
                        div_counter <= 0;
                        spi_sclk <= 0;
                        shift_reg <= {shift_reg[30:0], spi_miso}; // Sample MISO
                        
                        if (bit_count == 0) begin
                            state <= S_DONE;
                        end else begin
                            bit_count <= bit_count - 1;
                            state <= S_SCLK_LOW;
                        end
                    end else begin
                        div_counter <= div_counter + 1;
                    end
                end

                S_DONE: begin
                    rx_data <= shift_reg;
                    busy <= 0;
                    state <= S_IDLE;
                end
            endcase
        end
    end

endmodule
