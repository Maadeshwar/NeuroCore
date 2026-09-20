<div align="center">

# NeuroCore-SoC

![](https://img.shields.io/badge/Architecture-RISC--V-blue?style=for-the-badge)
![](https://img.shields.io/badge/CPU-Ibex-orange?style=for-the-badge)
![](https://img.shields.io/badge/Accelerator-16x16_NPU-red?style=for-the-badge)
![](https://img.shields.io/badge/Bus-Custom_Arbiter-green?style=for-the-badge)
![](https://img.shields.io/badge/Status-RTL_Complete-brightgreen?style=for-the-badge)

A highly optimized, fully integrated Edge AI System-on-Chip (SoC) designed for high-performance neural network inference.

</div>

---

## Overview

NeuroCore-SoC is a complete, bare-metal artificial intelligence hardware platform. It combines a lowRISC Ibex (RV32IMC) microcontroller with a custom, highly pipelined 16x16 Systolic Array Neural Processing Unit (NPU). 

The system is built from the ground up for edge inference, featuring a True Harvard memory architecture, a dedicated Memory-to-Memory Direct Memory Access (DMA) controller, and a hardware-accelerated post-processing pipeline for quantization and pooling.

## Purpose

The primary purpose of this SoC is to provide a highly autonomous, power-efficient, and mathematically rigid hardware accelerator for Deep Learning inference at the edge. By heavily offloading matrix multiplications, nested layer loops, and post-processing (ReLU, Pooling) directly into dedicated silicon, NeuroCore-SoC allows the host CPU to remain in a low-power sleep state during heavy workloads. It is specifically designed to run Convolutional Neural Networks (CNNs) and dense feed-forward networks with extremely low latency and zero memory bottlenecks.

## Architecture Highlights

*   **16x16 Systolic MAC Array**: Capable of executing 256 Multiply-Accumulate operations per clock cycle.
*   **Hardware Tiler**: Nested loop controller allows the CPU to schedule entire multi-dimensional tensor operations with a single configuration command.
*   **32-bit Partial Sum Accumulator (PBUF)**: Retains full 32-bit mathematical precision across deep channel dimensions and supports DMA bias preloading.
*   **Post-Processing Pipeline**: Integrated hardware Activation (ReLU), Quantization (8-bit downshift), and a 2x2 Max Pooling unit.
*   **True Harvard Memory**: 64KB Instruction RAM and 64KB Data RAM arrays operate independently to prevent CPU starvation during heavy NPU workloads.
*   **Asynchronous Interrupts**: The NPU and DMA controller are wired directly to the Ibex Fast Local Interrupts, allowing the CPU to sleep during compute-heavy matrix multiplications.

## System Memory Map

The custom bus arbiter maps the hardware peripherals into the following address space:

| Range Start | Range End   | Subsystem | Description |
| :--- | :--- | :--- | :--- |
| `0x0000_0000` | `0x0000_3FFF` | **IMEM** | 64KB Instruction RAM |
| `0x1000_0000` | `0x1000_3FFF` | **DMEM** | 64KB Data RAM |
| `0x2000_0000` | `0x2000_3FFF` | **IBUF** | NPU Input Activation Buffer |
| `0x3000_0000` | `0x3000_3FFF` | **WBUF** | NPU Weight Buffer |
| `0x4000_0000` | `0x4000_3FFF` | **OBUF** | NPU Output Buffer (Read-Only) |
| `0x5000_0000` | `0x5000_000F` | **CFG** | NPU Config (Quantization, ReLU, Pool) |
| `0x6000_0000` | `0x6000_001F` | **DMA** | DMA Controller Configuration |
| `0x7000_0000` | `0x7000_3FFF` | **PBUF** | NPU 32-bit Accumulator (Bias Preload) |

## RTL Module Hierarchy

*   `soc_top.v`: Top-level integration and Priority Bus Arbiter.
    *   `ibex_core`: RISC-V RV32IMC processor.
    *   `dma_controller.v`: 3-Stage FSM memory copy engine.
    *   `npu_top.v`: The complete NPU Subsystem IP.
        *   `layer_controller.v`: 3-Stage FSM Command scheduler and Tiler.
        *   `sram_buffers.v`: Internal IBUF, WBUF, and OBUF SRAM wrappers.
        *   `accumulator_pbuf.v`: 32-bit precision accumulator.
        *   `activation_pool.v`: Hardware ReLU and Quantization.
        *   `max_pool_2x2.v`: Hardware 2D pooling logic.
        *   `systolic_array.v`: The 16x16 Systolic Matrix Multiplier.

## Status and Verification

All finite state machines (FSMs) have been rigorously audited and written in a strict 3-stage architecture (Sequential State, Next-State Combinational, Output Logic). Data alignment between the skew buffers and the systolic core has been verified to the exact clock cycle, ensuring zero data loss during high-speed streaming.

The RTL phase is complete. The repository is ready for testbench simulation and FPGA synthesis.
