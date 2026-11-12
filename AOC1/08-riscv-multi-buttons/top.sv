// Top para a Tang Nano 20K: RISC-V multiciclo + E/S mapeada em memoria
module top (
    input        clk,              // 27 MHz
    input        reset,            // botao S2 (ativo alto)
    input  [0:0] KEY,              // botao S1 (ativo alto)
    output [9:0] LEDR);

  wire [31:0] addr, writedata, readdata, MEM_readdata, IO_readdata;
  wire        memwrite;

  // memory-mapped i/o
  wire isIO  = addr[8]; // 0x0000_0100
  wire isRAM = !isIO;
  localparam IO_LEDS_bit = 2; // 0x0000_0104
  localparam IO_KEY_bit  = 4; // 0x0000_0110

  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata);

  // memory
  ram mem0(clk, memwrite & isRAM, addr, writedata, MEM_readdata);

  reg [9:0] leds = 0;
  always @(posedge clk)
    if (memwrite & isIO & addr[IO_LEDS_bit])
      leds <= writedata[9:0];

  assign IO_readdata = addr[IO_KEY_bit] ? {31'b0, KEY} : 32'b0;
  assign readdata    = isIO ? IO_readdata : MEM_readdata;

  // LEDs da placa (LEDR[5:0]) acendem em nivel baixo;
  // LEDs externos (LEDR[9:6]) ligados do pino para o GND acendem em nivel alto
  assign LEDR = {leds[9:6], ~leds[5:0]};
endmodule

module ram (
    input         clk, we,
    input  [31:0] a, wd,
    output [31:0] rd);

  reg [31:0] RAM [0:255];

  initial $readmemh("deslocador_fpga.hex", RAM);

  assign rd = RAM[a[9:2]]; // word aligned

  always @(posedge clk)
    if (we) RAM[a[9:2]] <= wd;
endmodule
