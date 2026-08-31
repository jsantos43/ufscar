.section .text
.globl _start
_start:
  li a7, 64         # syscall write
  li a0, 1          # fd = 1 (stdout)
  la a1, msg        # endereço da string
  li a2, 14         # tamanho da mensagem
  ecall

  li a0, 42         # valor de retorno
  li a7, 93        # syscall exit (Linux)
  ecall

msg:
  .asciz "Hello RISC-V!\n"