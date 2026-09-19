# NeuroCore-SoC Verification Makefile

# Toolchains
CC = riscv32-unknown-elf-gcc
OBJCOPY = riscv32-unknown-elf-objcopy
IV = iverilog
VVP = vvp

# Flags
CFLAGS = -march=rv32imc -mabi=ilp32 -mcmodel=medany -O2 -ffreestanding -nostdlib
LDFLAGS = -T link.ld

# Source Files
RTL_SRC = ../rtl/soc/soc_top.v \
          ../rtl/soc/dma_controller.v \
          ../rtl/soc/spi_master.v \
          ../rtl/accelerator/accelerator_top.v \
          ../rtl/accelerator/layer_controller.v \
          ../rtl/accelerator/accumulator_pbuf.v \
          ../rtl/accelerator/max_pool_2x2.v \
          ../rtl/accelerator/activation_pool.v \
          ../rtl/accelerator/skew_buffers.v \
          ../rtl/accelerator/sram_buffers.v \
          ../rtl/accelerator/npu_command_fifo.v \
          ../rtl/NPU/rtl/npu_core.v \
          ../rtl/NPU/rtl/systolic_array.v \
          ../rtl/NPU/rtl/pe.v \
          ../rtl/CPU/ibex/rtl/*.v # Includes Ibex core files

# Targets
all: run

firmware.elf: firmware.c
	$(CC) $(CFLAGS) $(LDFLAGS) firmware.c -o firmware.elf

firmware.hex: firmware.elf
	$(OBJCOPY) -O verilog firmware.elf firmware.hex

sim.vvp: soc_tb.v firmware.hex
	$(IV) -I../rtl/soc -I../rtl/accelerator -I../rtl/NPU/rtl -s soc_tb -o sim.vvp soc_tb.v $(RTL_SRC)

run: sim.vvp
	$(VVP) sim.vvp

clean:
	rm -f firmware.elf firmware.hex sim.vvp soc_tb.vcd
