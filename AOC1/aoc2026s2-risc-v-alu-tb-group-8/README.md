# Escrevendo a ULA do RISC-V

O objetivo desta simulação é escrever uma ULA para o processador RISC-V [baseada neste modelo](alu.v). Utilize o processador de referência e também suas referências como modelo. Insira a função `$monitor` em seus códigos, para obter valores reais de suas entradas/saídas como as seguintes:

```
Time:   0, instr: 01c38333, op1: cafe0000, op2: 0000babe, res: cafebabe
Time:  10, instr: 40730333, op1: cafe0000, op2: 0000babe, res: cafd4542
Time:  20, instr: 40730333, op1: cafebabe, op2: cafe0000, res: 0000babe
Time:  30, instr: 00338313, op1: cafebabe, op2: 00000003, res: cafebac1
Time:  40, instr: 00338313, op1: cafe0000, op2: 00000003, res: cafe0003
Time:  50, instr: 01c3e333, op1: cafe0000, op2: 00400000, res: cafe0000
Time:  60, instr: 01c3e333, op1: cafe0000, op2: 0000babe, res: cafebabe
Time:  70, instr: 0033e313, op1: cafe0000, op2: 00000003, res: cafe0003
Time:  80, instr: 01c3c333, op1: cafe0000, op2: 00400000, res: cabe0000
Time:  90, instr: 01c3c333, op1: cafe0000, op2: 0000babe, res: cafebabe
Time: 100, instr: 0033c313, op1: cafe0000, op2: 00000003, res: cafe0003
Time: 110, instr: 01d39333, op1: cafe0000, op2: 00400000, res: cafe0000
Time: 120, instr: 01d39333, op1: cafe0000, op2: 00000004, res: afe00000
Time: 130, instr: 00239313, op1: cafe0000, op2: 00000002, res: 2bf80000
Time: 140, instr: 01d3d333, op1: cafe0000, op2: 00001800, res: cafe0000
Time: 150, instr: 01d3d333, op1: cafe0000, op2: 00000004, res: 0cafe000
Time: 160, instr: 0083d313, op1: cafe0000, op2: 00000008, res: 00cafe00
Time: 170, instr: 41d3d333, op1: cafe0000, op2: 00000000, res: cafe0000
Time: 180, instr: 41d3d333, op1: cafe0000, op2: 00000004, res: fcafe000
Time: 190, instr: 4083d313, op1: cafe0000, op2: 00000408, res: ffcafe00
Time: 200, instr: 00100073, op1: cafe0000, op2: 00000001, res: cafe0001
```


Esta saída foi obtida com o seguinte programa de teste:

```asm
.section .text
.globl main
main:
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
```

## Referências

- [LigthRISCV ](https://github.com/menotti/lightriscv)