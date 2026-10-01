.section .text

.globl main

main:
.L0:
    li t2, 0xCAFE0000
    li t3, 0x0000BABE
    li t4, 0x4
    add t1, t2, t3
    sub t1, t1, t2
    addi t1, t2, 0x3
    or t1, t2, t3
    ori t1, t2, 0x3
    xor t1, t2, t3
    xori t1, t2, 0x3
    sll t1, t2, t4
    slli t1, t2, 0x2
    srl t1, t2, t4
    srli t1, t2, 0x8
    sra t1, t2, t4
    srai t1, t2, 0x8
    ebreak
	j .L0

