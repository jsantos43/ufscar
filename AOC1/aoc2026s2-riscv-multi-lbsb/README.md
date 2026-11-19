# Implementação de um RISC-V multiciclo com instruções LB/SB

O [código fornecido a você](riscvmulti.sv) nesta simulação é uma implementação multiciclo do RISC-V, adaptada do código de Bruno Levy [^1]. 

Agora usamos o esquema de *von Neumann* (dados e instruções em uma única memória). O código fornecido está praticamente completo, você só precisa pensar nas perguntas abaixo para fornecer os valores corretos nas atribuições faltantes (isso já foi feito em uma simulaçào anterior): 

```verilog
    wire writeBackEn = // Quando se escreve no banco de registradores?
    wire [31:0] writeBackData = // O que se escreve no banco de registradores?
    wire [31:0] LoadStoreAddress = // Como se calcula o endereço de memória para loads e stores?
    assign Address = // Qual o endereço de memória a ser acessado? Alternar entre .text e .data dependendo do estado
    assign MemWrite = // Em que estado se escreve na memória?
    assign WriteData = // O que se escreve na memória?
```

Depois, você precisa notar que o processador só é capaz de acessar a memória com instruções `lw` e `sw`, mas o programa a seguir lhe é fornecido:

```assembly
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
	ebreak				# end of program	

.data	# 0x00000080 
frame_buffer: # wrgb, cmy, white
	.word 0xff300c03, 0x000f333c, 0xaaaaaaaa, 0x000f333c, 0xff300c03
```

Você precisa então completar o processador e a memória para que ele seja capaz de ler e gravar um byte por vez e também meia palavra (*half word*).

## References
[^1]: [From Blinker to RISC-V](https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/TUTORIALS/FROM_BLINKER_TO_RISCV/)
[^2]: [LightRISCV](https://github.com/menotti/LightRISCV)

