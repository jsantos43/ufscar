.text	# 0x00000000
.globl _start
_start:
	li s0, 0x108		# endereco de SW
	li s1, 0x104		# endereco de LEDR
loop:
	lw t0, (s0)		# le as chaves
	sw t0, (s1)		# copia para os LEDs
	j loop
