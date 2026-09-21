#!/bin/bash

cd tests
riscv64-linux-gnu-as ../$1.s -o $1.o && \
riscv64-linux-gnu-ld $1.o -o $1.elf && \
qemu-riscv64 ./$1.elf < string.in > $1.out

if diff $1.out $1.ok >/dev/null; then
    echo "OK"
    exit 0
else
    echo "ERRO"
    exit 1
fi
