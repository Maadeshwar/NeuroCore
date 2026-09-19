#include <verilated.h>
#include "Vsoc_tb.h" // Verilator auto-generated header for soc_tb
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vsoc_tb* tb = new Vsoc_tb;

    tb->clk = 0;
    tb->rst_n = 0;

    // Run for a bit in reset
    for (int i = 0; i < 100; i++) {
        tb->clk = !tb->clk;
        tb->eval();
    }
    
    tb->rst_n = 1;

    // Run simulation
    while (!Verilated::gotFinish() && Verilated::time() < 5000000) {
        tb->clk = !tb->clk;
        tb->eval();
        Verilated::timeInc(1);
    }

    tb->final();
    delete tb;
    
    return 0;
}
