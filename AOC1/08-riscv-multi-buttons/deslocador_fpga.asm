# Deslocador para a placa: mesmo algoritmo do deslocador.asm,
# mas usando a E/S mapeada em memoria do top.sv
#   0x0000_0110 -> KEY  (leitura do botao)
#   0x0000_0104 -> LEDR (escrita nos LEDs)
.text	# 0x00000000
.globl _start
_start:
	li s0, 0x110		# endereco de KEY
	li s1, 0x104		# endereco de LEDR
	li t0, 1		# sequencia = 0000000001
	li t1, 512		# limite esquerdo: 1000000000
	li t2, 1		# limite direito:  0000000001
	sw t0, (s1)
espera_esq:
	lw t3, (s0)
	beqz t3, espera_esq	# espera KEY[0] = 1
esquerda:
	slli t0, t0, 1
	sw t0, (s1)
	jal ra, atraso
	bne t0, t1, esquerda	# botao ignorado ate chegar ao fim
espera_dir:
	lw t3, (s0)
	beqz t3, espera_dir	# espera KEY[0] = 1 de novo
direita:
	srli t0, t0, 1
	sw t0, (s1)
	jal ra, atraso
	bne t0, t2, direita	# botao ignorado ate chegar ao fim
	j espera_esq

# atraso de ~0,15 s a 27 MHz (cada volta: addi + bnez = 8 ciclos)
atraso:
	li t4, 980000
atraso_loop:
	addi t4, t4, -1
	bnez t4, atraso_loop
	jalr zero, 0(ra)	# volta para quem chamou (ret)
