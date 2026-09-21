# Manipulando *strings* em assembly do RISC-V 

Nesta simulação, vamos aprender como manipular *strings* usando o assembly do RISC-V. 

## Exemplo

Observe o programa [minuscula.s](minuscula.s) a seguir, criado ler uma *string* da console, convertê-la para minúsculas e imprimir o resultado:

```asm
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

    # converter somente letras A–Z em minúsculas
    la t1, buffer         # t1 = ponteiro para buffer
    mv t0, s0             # contador de bytes
loop:
    beqz t0, done         # se não há mais bytes -> fim
    lbu t2, 0(t1)         # lê próximo byte (unsigned)
    li t3, 'A'            # 0x41
    blt t2, t3, skip      # se < 'A' -> ignora
    li t3, 'Z'            # 0x5A
    bgt t2, t3, skip      # se > 'Z' -> ignora
    ori t2, t2, 0x20      # força bit 5 -> minúsculo
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
```

- Na seção de dados, um único *buffer* de 128 bytes é reservado (linhas 1 e 2). 
- O *buffer* é lido usando a `syscall read` e o tamanho usado é salvo em `s0` (linhas de 8 até 13).
- Antes de entrar no laço principal, `t1` recebe o endereço do *buffer* e `t0` o número de bytes (linhas 16 e 17). No final do laço `t1` é incrementado e `t0` decrementado (linhas 28 e 29).
- O critério de parada é feito com `beqz` (linha 19).
- Apenas as letras maiúsculas e sem acento são consideradas, então os limites são testados (linhas de 21 a 24). Números e caracteres especiais são ignorados por este filtro. 
- O bit 5 do caracter lido é setado com `ori`, pois as minúsculas estão exatamente 32 posições adiante na tabela ASCII, e o byte é então gravado de volta na memória (linhas 26). 
- Após a conclusão do laço, as syscalls `write` e `exit` são chamadas para imprimir o resultado e finalizar o programa respectivamente. 

# Agora é a sua vez! 

1. Usando este programa como exemplo, crie um programa em [maiuscula.s](maiuscula.s) para fazer o contrário, ou seja, converter para maiúsculas. 
1. Crie também um programa em [inverte.s](inverte.s) para inverter a *string* sem modificar os caracteres. 