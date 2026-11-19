.text	# 0x00000000 
.globl _start
_start:
	la a0, frame_buffer	# load address of frame buffer
	lb t0, 0(a0)		# load first byte
	lb t1, 1(a0)		# load second byte
	lb t2, 2(a0)		# load third byte
	lb t3, 3(a0)		# load fourth byte
	sb t3, 0(a0)		# store fourth byte to first byte
	sb t2, 1(a0)		# store third byte to second byte
	sb t1, 2(a0)		# store second byte to third byte
	sb t0, 3(a0)		# store first byte to fourth byte
end:
	j end
	
.data	# 0x00000080 
frame_buffer: # wrgb, cmy, white
	.word 0xff300c03, 0x000f333c, 0xaaaaaaaa, 0x000f333c, 0xff300c03
	.space 300-40
	.word 0xff300c03, 0x000f333c, 0xaaaaaaaa, 0x000f333c, 0xff300c03
frame_end:
