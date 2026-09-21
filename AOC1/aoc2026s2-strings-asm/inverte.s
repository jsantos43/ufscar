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







    # inverter a string no buffer
    la t1, buffer         # t1 = ponteiro para o inicio do buffer
    mv t0, s0             # t0 = nbytes
    beqz t0, done         # se 0 bytes, termina
    add t2, t1, t0        # t2 = ponteiro apos o fim
    addi t2, t2, -1       # t2 = ponteiro para o ultimo char

loop_inv:
    bge t1, t2, done      # se (inicio >= fim), termina
    lbu t3, 0(t1)         # le char do inicio
    lbu t4, 0(t2)         # le char do fim
    sb t4, 0(t1)          # salva no inicio
    sb t3, 0(t2)          # salva no fim
    addi t1, t1, 1        # avanca inicio
    addi t2, t2, -1       # recua fim
    j loop_inv

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
