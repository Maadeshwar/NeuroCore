#include <stdint.h>

#define DMEM_BASE  0x10000000
#define IBUF_BASE  0x20000000
#define WBUF_BASE  0x30000000
#define OBUF_BASE  0x40000000
#define CFG_BASE   0x50000000
#define DMA_BASE   0x60000000
#define PBUF_BASE  0x70000000
#define SPI_BASE   0x80000000
#define FIFO_BASE  0xA0000000
#define TB_MAGIC   0x90000000

#define NPU_CFG         ((volatile uint32_t*)(CFG_BASE + 0x00))
#define NPU_CMD_FIFO    ((volatile uint32_t*)(FIFO_BASE + 0x00))
#define DMA_SRC_ADDR    ((volatile uint32_t*)(DMA_BASE + 0x00))
#define DMA_DST_ADDR    ((volatile uint32_t*)(DMA_BASE + 0x04))
#define DMA_TRANSFER_LEN ((volatile uint32_t*)(DMA_BASE + 0x08))
#define DMA_START_BUSY  ((volatile uint32_t*)(DMA_BASE + 0x0C))
#define OBUF_MEM        ((volatile uint32_t*)(OBUF_BASE))

#define OP_LOAD_WEIGHTS 1
#define OP_RUN_MAC      2
#define OP_SET_TILER    3

uint32_t build_cmd(uint8_t opcode, uint32_t payload) {
    return ((uint32_t)opcode << 28) | (payload & 0x0FFFFFFF);
}

void dma_copy(uint32_t src, uint32_t dst, uint32_t words) {
    *DMA_SRC_ADDR = src;
    *DMA_DST_ADDR = dst;
    *DMA_TRANSFER_LEN = words;
    *DMA_START_BUSY = 1;
    while (*DMA_START_BUSY & 1);
}

void delay() {
    for (volatile int i = 0; i < 2000; i++);
}

int main(void) {
    volatile uint32_t* dmem = (volatile uint32_t*)DMEM_BASE;
    uint32_t w_start = DMEM_BASE + 0x000;
    uint32_t a_start = DMEM_BASE + 0x200;
    
    for (int r = 0; r < 16; r++) {
        for (int c = 0; c < 4; c++) {
            uint32_t val = 0;
            for (int b = 0; b < 4; b++) {
                int col_idx = c * 4 + b;
                if (col_idx == r) val |= (1 << (b * 8));
            }
            dmem[(0x000/4) + r*4 + c] = val;
        }
    }
    
    for (int r = 0; r < 16; r++) {
        for (int c = 0; c < 4; c++) {
            uint32_t val = 0;
            for (int b = 0; b < 4; b++) {
                int col_idx = c * 4 + b;
                int8_t act_val = (col_idx % 2 == 0) ? 2 : -2;
                val |= ((uint8_t)act_val << (b * 8));
            }
            dmem[(0x200/4) + r*4 + c] = val;
        }
    }
    
    dma_copy(w_start, WBUF_BASE, 16 * 4);
    dma_copy(a_start, IBUF_BASE, 16 * 4);
    
    int errors = 0;
    
    // TEST 1: Baseline (No ReLU, No Pool, No Quantize)
    *NPU_CFG = 0x00;
    *NPU_CMD_FIFO = build_cmd(OP_LOAD_WEIGHTS, 16);
    *NPU_CMD_FIFO = build_cmd(OP_SET_TILER, 0);
    *NPU_CMD_FIFO = build_cmd(OP_RUN_MAC, (0 << 27) | (1 << 26) | 16);
    delay();
    
    if (*OBUF_MEM != 0xFE02FE02) errors++;
    
    // TEST 2: ReLU
    *NPU_CFG = (1 << 5); 
    *NPU_CMD_FIFO = build_cmd(OP_RUN_MAC, (0 << 27) | (1 << 26) | 16);
    delay();
    if (*OBUF_MEM != 0x00020002) errors++;

    // TEST 3: Pool
    *NPU_CFG = (1 << 6); 
    *NPU_CMD_FIFO = build_cmd(OP_RUN_MAC, (0 << 27) | (1 << 26) | 16);
    delay();
    if (*OBUF_MEM != 0x02020202) errors++;
    
    volatile uint32_t* magic = (volatile uint32_t*)TB_MAGIC;
    if (errors == 0) {
        *magic = 0x00000001; // PASS
    } else {
        *magic = 0xDEADBEEF; // FAIL
    }
    
    while(1);
    return 0;
}
