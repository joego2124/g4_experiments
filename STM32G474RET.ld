MEMORY {
    FLASH   (RX)  : ORIGIN = 0x08000000, LENGTH = 512k
    RAM     (RWX) : ORIGIN = 0x20000000, LENGTH = 128k
    CCMSRAM (RWX) : ORIGIN = 0x10000000, LENGTH = 32k
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
    .text : ALIGN(4) {
        _stext = .;
        KEEP(*(.ivt))
        *(.text*)
        _etext = .;
    } > FLASH

    .data : ALIGN(4) {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM AT > FLASH

    _idata = LOADADDR(.data);

    .bss : ALIGN(4) {
        _sbss = .;
        *(.bss*)
        _ebss = .;
    } > RAM
}