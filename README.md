# NeuroCore SoC

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Build: Passing](https://img.shields.io/badge/Build-Passing-brightgreen.svg)

**NeuroCore** is a configurable, AI-accelerated System-on-Chip (SoC) combining a custom RISC-V processor and a tightly coupled high-performance Neural Processing Unit (NPU).

## 🚀 Architecture Overview

NeuroCore integrates standard SoC peripherals with a dedicated hardware accelerator pipeline to execute deep learning models at the edge. 

### The NPU Subsystem (
tl/NPU)
At the heart of NeuroCore is our proprietary, natively integrated **16x16 Systolic Array NPU**. 
* **Seamless Scalability:** We instantiated the standalone parameterized IP with parameter N = 16, instantly scaling it from edge to high-performance compute.
* **3-Stage FSM Intelligence:** The NPU is driven by a highly optimized 3-Stage FSM (IDLE -> LOAD_WEIGHT -> RUN_MAC), which abstracts the matrix math timing and completely controls SRAM fetching and data pushing automatically.
* **Native Features:** The tightly-coupled NPU natively processes Bias Addition (A*B + C), Hardware ReLU, 2x2 Max Pooling, and Quantization Scaling directly within the hardware pipeline.

### Integration Mechanism
The NPU memory modules (IBUF, WBUF, PBUF, OBUF) are directly memory-mapped into the RISC-V CPU's address space. 
1. The CPU initiates an internal DMA transfer to rapidly stream weights and input data from Main Memory (DRAM) into the NPU's localized SRAMs.
2. The CPU pushes a 32-bit execution command (e.g., OP_RUN_MAC) into the NPU's asynchronous Command FIFO.
3. The NPU's 3-Stage FSM takes over, autonomously orchestrating the matrix math, and raises a hardware interrupt (
pu_ready) when the OBUF contains the final tensor.

## 🧪 Verification

NeuroCore includes an end-to-end SoC verification suite. The simulated RISC-V CPU executes a bare-metal C firmware payload (irmware.c) that:
* Compiles C code into RISC-V instructions (irmware.hex).
* Manages the DMA controller to push 16x16 matrices into the NPU.
* Issues NPU commands via the Memory-Mapped FIFO.
* Explicitly asserts mathematically correct results for standard Matrix Math, ReLU thresholding, and Max Pooling operations directly from software.
