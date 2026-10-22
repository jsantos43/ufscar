#!/bin/sh
# Monta deslocador.asm e simula com o testbench desta pasta
cd "$(dirname "$0")" || exit 1

# Ubuntu: riscv64-unknown-elf-*, Arch: riscv64-elf-*
if command -v riscv64-unknown-elf-as >/dev/null; then CROSS=riscv64-unknown-elf; else CROSS=riscv64-elf; fi

$CROSS-as -march=rv32i -o riscv.o ../deslocador.asm || exit 1
$CROSS-ld -m elf32lriscv -T ../tests/riscv.ld -o riscv.elf riscv.o || exit 1
$CROSS-objcopy -O verilog --verilog-data-width=4 riscv.elf riscv.hex || exit 1
$CROSS-objdump -D riscv.elf > riscv.lst

iverilog -Wall -g2012 ../riscvmulti.sv ../tests/mem.sv testbench.sv || exit 1
vvp a.out
