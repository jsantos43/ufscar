#!/bin/bash

cd tests
riscv64-linux-gnu-as ../hello.s -o hello.o && \
riscv64-linux-gnu-ld hello.o -o hello.elf && \
qemu-riscv64 ./hello.elf > hello.out
echo $? >> hello.out

if diff hello.out hello.ok >/dev/null; then
    echo "OK"
    exit 0
else
    echo "ERRO"
    exit 1
fi
