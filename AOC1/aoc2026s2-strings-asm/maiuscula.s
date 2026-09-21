    .section .data
buffer: .space 128        # buffer para leitura (128 bytes máx)

    .section .text
    .globl _start
_start:
    # read(0, buffer, 128)
    li a7, 63             # syscall read
    li a0, 0              # fd = 0 (stdin)
    la a1, buffer         # buffer destino
    li a2, 128            # tamanho máx
    ecall
    mv s0, a0             # s0 = número de bytes lidos (preservar)







    # converter somente letras a-z em maiúsculas
    la t1, buffer         # t1 = ponteiro para buffer
    mv t0, s0             # contador de bytes
loop:
    beqz t0, done         # se não há mais bytes -> fim
    lbu t2, 0(t1)         # lê próximo byte (unsigned)
    li t3, 'a'            # 0x61
    blt t2, t3, skip      # se < 'a' -> ignora
    li t3, 'z'            # 0x7A
    bgt t2, t3, skip      # se > 'z' -> ignora
    andi t2, t2, 0xDF     # limpa bit 5 -> maiúsculo (~0x20 = 0xDF)
    sb t2, 0(t1)          # grava de volta
skip:
    addi t1, t1, 1        # avança ponteiro
    addi t0, t0, -1       # decrementa contador
    j loop

done:
    # write(1, buffer, nbytes)
    li a7, 64             # syscall write
    li a0, 1              # fd = 1 (stdout)
    la a1, buffer         # endereço do buffer
    mv a2, s0             # número de bytes lidos
    ecall
    # exit(0)
    li a7, 93             # syscall exit
    li a0, 0
    ecall
