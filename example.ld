ENTRY(_start)
SECTIONS
{
  . = 0x8000000 ;
  .text.start : { *(.text.start)}
  .text : {*(.text)}
  .data : {*(.data)}
  .bss : {*(.bss COMMON)}
  .rodata : {*(.rodata)}
  . = ALIGN(4);
}