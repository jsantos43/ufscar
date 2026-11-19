OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
  text (rx)  : ORIGIN = 0x00000000, LENGTH = 512
  data (rw)  : ORIGIN = 0x00000200, LENGTH = 512
}

SECTIONS
{
  /* Código em 0x00000000 */
  .text : {
    *(.text)
    *(.text.*)
  } > text

  /* Dados em 0x00000080 */
  .data : {
    *(.data)
    *(.data.*)
  } > data

  .bss : {
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } > data
}