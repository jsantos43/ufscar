.text	# 0x00000000
.globl _start
_start:
	la s0, entrada		# endereco do dado de entrada
	la s1, saida		# endereco da sequencia
	li t0, 1		# sequencia = 0000000001
	li t1, 512		# limite esquerdo: 1000000000
	li t2, 1		# limite direito:  0000000001
	sw t0, (s1)
espera_esq:
	lw t3, (s0)
	beqz t3, espera_esq	# espera entrada = 1
esquerda:
	slli t0, t0, 1
	sw t0, (s1)
	bne t0, t1, esquerda	# entrada ignorada ate chegar ao fim
espera_dir:
	lw t3, (s0)
	beqz t3, espera_dir	# espera entrada = 1 de novo
direita:
	srli t0, t0, 1
	sw t0, (s1)
	bne t0, t2, direita	# entrada ignorada ate chegar ao fim
	j espera_esq

.data	# 0x00000100
entrada: .word 0
saida:	 .word 1
