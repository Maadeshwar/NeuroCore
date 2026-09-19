OUTPUT_ARCH(riscv)
ENTRY(main)

MEMORY
{
    IMEM (rx) : ORIGIN = 0x00000000, LENGTH = 64K
    DMEM (rw) : ORIGIN = 0x10000000, LENGTH = 64K
}

SECTIONS
{
    .text : {
        *(.text.init)
        *(.text)
        *(.text.*)
    } > IMEM

    .data : {
        *(.data)
        *(.data.*)
        *(.sdata)
        *(.sdata.*)
    } > DMEM

    .bss : {
        *(.bss)
        *(.bss.*)
        *(.sbss)
        *(.sbss.*)
    } > DMEM
}
