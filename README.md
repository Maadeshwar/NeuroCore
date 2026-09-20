<h1 align="center">NeuroCore SoC</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Architecture-RISC--V_SoC-007ACC?style=for-the-badge" alt="RISC-V">
  <img src="https://img.shields.io/badge/Accelerator-16x16_NPU-FF3366?style=for-the-badge" alt="Accelerator">
  <img src="https://img.shields.io/badge/Language-Verilog_2001-4B32C3?style=for-the-badge" alt="Verilog">
  <img src="https://img.shields.io/badge/Status-Production_Grade-00C853?style=for-the-badge" alt="Status">
</p>

---

<h2 align="center">System Architecture Overview</h2>

**NeuroCore** is a high-performance, configurable, AI-accelerated System-on-Chip (SoC). It seamlessly merges a custom RISC-V processor with a deeply integrated Neural Processing Unit (NPU) subsystem, establishing a production-grade environment for executing deep learning models directly at the edge.

<h3 align="center">The 16x16 NPU Subsystem</h3>
At the physical core of the NeuroCore SoC is our proprietary, tightly-coupled **16x16 Systolic Array NPU**. 
* **Seamless Scalability:** By leveraging the NPU's universal parameterized logic, we physically instantiated the accelerator inside the SoC with parameter N = 16, instantly scaling it to a high-performance parallel compute matrix.
* **3-Stage FSM Intelligence:** The NPU abstracts all physical pipeline timing and data skewing via a highly optimized 3-Stage Finite State Machine (IDLE, LOAD_WEIGHT, RUN_MAC). This controller completely automates SRAM memory fetching and matrix dot-product orchestration without stalling the CPU.
* **Native Post-Processing Integration:** The 16x16 subsystem natively processes Bias Addition (A*B + C), Hardware ReLU non-linear activation, 2x2 Max Pooling spatial downsampling, and Quantization Scaling directly within the hardware pipeline, requiring zero post-processing overhead from the RISC-V core.

---

<h2 align="center">Integration and Data Flow</h2>

<h3 align="center">Direct Memory Mapping</h3>
The NPU memory modules (IBUF, WBUF, PBUF, OBUF) are directly memory-mapped into the RISC-V CPU's physical address space. This zero-protocol SRAM architecture avoids the extreme latency of heavy bus wrappers.

<h3 align="center">Execution Pipeline</h3>
1. **DMA Streaming:** The RISC-V CPU configures the internal Direct Memory Access (DMA) controller to rapidly stream flattened input images (Activations) and convolutional kernels (Weights) from Main DRAM directly into the NPU's localized SRAM buffers.
2. **Command Dispatch:** The CPU pushes a precise 32-bit execution command packet (e.g., OP_RUN_MAC) into the NPU's asynchronous Command FIFO, releasing the CPU to perform other operations.
3. **Autonomous Execution:** The NPU's 3-Stage FSM detects the command, wakes from the IDLE state, and autonomously drives the physical matrix math.
4. **Hardware Interrupt:** Upon completion of the matrix block and post-processing, the FSM raises a hardware interrupt (npu_ready) back to the RISC-V processor, signaling that the output tensor is ready to be fetched from the OBUF.

---

<h2 align="center">End-to-End Verification</h2>

NeuroCore includes an exhaustive SoC-level verification suite. The environment simulates the RISC-V processor executing a bare-metal C firmware payload (firmware.c) that rigorously validates the hardware logic.

<h3 align="center">Firmware Validation Routine</h3>
* The C compiler generates firmware.hex containing the RISC-V machine instructions.
* The firmware dynamically manages the DMA controller to push exact 16x16 matrices into the NPU.
* It dispatches execution commands via the Memory-Mapped FIFO to test all internal paths.
* It explicitly asserts that the hardware returns mathematically identical results for:
  1. Baseline Matrix-Vector Multiplication.
  2. ReLU Negative Thresholding.
  3. 2x2 Max Pooling Operations.

All operations execute flawlessly in simulated hardware, proving the production-grade stability of the complete SoC architecture.
