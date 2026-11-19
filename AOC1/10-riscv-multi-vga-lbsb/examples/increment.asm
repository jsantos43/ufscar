.text	# 0x00000000 
.globl _start
_start:
	la s0, frame_buffer
	la s1, frame_end
	la s2, 0x10c
loop:

	li a0, 0x80
delay:
	addi a0, a0, -1
	bne a0, x0, delay

	lw t0, 0(s0)
	addi t0, t0, 1
	sw t0, 0(s0)
	sw t0, 0(s2)
	addi s0, s0, 4
	bne s0, s1, loop
	j _start
	
.data	# 0x00000080 
frame_buffer: # all black
	.space 300
frame_end:
