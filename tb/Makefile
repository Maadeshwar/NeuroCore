# NeuroCore-SoC Verification Makefile

# Toolchains (in WSL)
CC = riscv64-unknown-elf-gcc
OBJCOPY = riscv64-unknown-elf-objcopy
VERILATOR = verilator

# Flags
CFLAGS = -march=rv32imc -mabi=ilp32 -mcmodel=medany -O2 -ffreestanding -nostdlib
LDFLAGS = -T link.ld

# Source Files
RTL_SRC = mock_cpu.v \
          soc_mock_top.v \
          ../rtl/soc/dma_controller.v \
          ../rtl/soc/spi_master.v \
          ../rtl/NPU/rtl/npu_top.v \
          ../rtl/NPU/rtl/layer_controller.v \
          ../rtl/NPU/rtl/accumulator_pbuf.v \
          ../rtl/NPU/rtl/max_pool_2x2.v \
          ../rtl/NPU/rtl/activation_pool.v \
          ../rtl/NPU/rtl/skew_buffers.v \
          ../rtl/NPU/rtl/sram_buffers.v \
          ../rtl/NPU/rtl/npu_command_fifo.v \
          ../rtl/NPU/rtl/systolic_array.v \
          ../rtl/NPU/rtl/pe.v

# Targets
all: run

firmware.elf: firmware.c
	$(CC) $(CFLAGS) $(LDFLAGS) firmware.c -o firmware.elf

firmware.hex: firmware.elf
	$(OBJCOPY) -O verilog firmware.elf firmware.hex

obj_dir/Vsoc_tb: soc_tb.v sim_main.cpp firmware.hex
	$(VERILATOR) -Wall --cc --exe --build -Wno-fatal \
	-I. -I../rtl/soc -I../rtl/NPU/rtl -I../rtl/CPU/ibex/rtl \
	--top-module soc_tb sim_main.cpp soc_tb.v $(RTL_SRC)

run: obj_dir/Vsoc_tb
	./obj_dir/Vsoc_tb

clean:
	rm -rf firmware.elf firmware.hex obj_dir
