# RISC-V multiciclo com vídeo VGA

O objetivo desta prática é adicionar instruções de manipulação de bytes ao processor RISC-V multiciclo. Estamos usando um [gerador de vídeo no padrão VGA](vga.sv) que calcula um endereço de memória e busca dados em um *frame buffer* para apresentar na tela. O `Makefile` desta pasta processa o arquivo [`riscv.asm`](riscv.asm), gera o arquivo `.hex` para  a memória e faz a simulação, enquanto [o da pasta superior](../Makefile) pode ser usado para programar a placa. 

O comando `make && make -f ../Makefile clean program` faz, portanto, as duas coisas.  

Para economizar recursos, a resolução real de 640x480 é mapeada na memória com 20x15, onde cada byte tem o formato XXRRGGBB e representa um quadrado de 32x32 pixels na tela. Isso requer 300 bytes ou 75 palavras, pouco mais que 1/4 da nossa memória. Vejamos algumas partes relevantes do nosso código:

```verilog
  // power-on reset
  power_on_reset por(clk, reset);
    
  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata);

  // memory 
  mem ram(clk, memwrite, addr, writedata, readdata, 'h200 + vaddr, vdata);

  // VGA controller
  vga gpu(VGA_CLK, reset, VGA_HS, VGA_VS, VGA_DA, vaddr);
```

Adicionamos um `reset` para facilitar a simulação e garantir o estado inicial dos contadores e endereços. O processador continua acessando a memória normalmente, mas esta agora possui duas portas adicionais: (i) `vaddr` (gerado no módulo `vga`) que aponta para uma palavra do *frame buffer* e (ii) `vdata` que retorna seu respectivo valor. Ela também tem agora leitura síncrona, o que permite que seja mapeada das *block RAMs* do FPGA, economizando muitos ALMs:

```verilog
module mem (
  input  logic        clk, we,
  input  logic [31:0] a, wd,
  output logic [31:0] rd,
  input  logic [31:0] va,
  output logic [31:0] vd);

  logic  [31:0] RAM [0:255];

  // initialize memory with instructions and data
  initial
    $readmemh("riscv.hex", RAM);

  // regular port (read/write)
  always_ff @(posedge clk)
  begin
    if (we)
      RAM[a[31:2]] <= wd;
    rd <= RAM[a[31:2]];
  end

  // video port (read only)
  always_ff @(posedge clk)
    vd <= RAM[va[31:2]];
endmodule
```

O primeiro código de exemplo coloca alguns pixels estáticos na tela. Note que, em relação à declaração, a palavra é  mostrada invertida na tela:

```asm
.data	# 0x00000080 
frame_buffer: # wrgb, bcmy, gray, ... 
	.word 0xff300c03, 0x000f333c, 0xaaaaaaaa, 0x000f333c, 0xff300c03
	.space 300-40
	.word 0xff300c03, 0x000f333c, 0xaaaaaaaa, 0x000f333c, 0xff300c03
frame_end:
```

De certa forma, isso tem relação com o [Endianess](https://en.wikipedia.org/wiki/Endianness) da arquitetura. O RISC-V adota em geral a abordagem *Little-endian*. 

![colors.png](colors.png)

Os recursos ocupados no kit DE0_CV são os seguintes (zeros omitidos):

```
Fitter Status : Successful - Wed Nov  5 10:11:34 2025
Quartus Prime Version : 22.1std.2 Build 922 07/20/2023 SC Lite Edition
Revision Name : project
Top-level Entity Name : top
Family : Cyclone V
Device : 5CEBA4F23C7
Timing Models : Final
Logic utilization (in ALMs) : 454 / 18,480 ( 2 % )
Total registers : 350
Total pins : 92 / 224 ( 41 % )
Total block memory bits : 16,384 / 3,153,920 ( < 1 % )
Total RAM Blocks : 4 / 308 ( 1 % )
```