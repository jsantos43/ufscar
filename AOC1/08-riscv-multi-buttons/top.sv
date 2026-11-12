module top (
    input        CLOCK_50,              // 50 MHz
    input  [1:0] KEY,              // botao S1 (ativo baixo) e S2 (ativo baixo)
    input  [9:0] SW,               // chaves SW[9:0]
    output [9:0] LEDR);

  wire [31:0] addr, writedata, readdata, MEM_readdata, IO_readdata;
  wire        memwrite;

  // memory-mapped i/o
  wire isIO  = addr[8]; // 0x0000_0100
  wire isRAM = !isIO;
  localparam IO_LEDS_bit = 2; // 0x0000_0104
  localparam IO_SW_bit   = 3; // 0x0000_0108
  localparam IO_KEY_bit  = 4; // 0x0000_0110

  // microprocessor
  riscvmulti cpu(CLOCK_50, ~KEY[1], addr, writedata, memwrite, readdata);

  // memory
  mem #(.FILENAME("initial_fpga.hex")) ram(CLOCK_50, memwrite & isRAM, addr, writedata, MEM_readdata);

  reg [9:0] leds = 0;
  always @(posedge CLOCK_50)
    if (memwrite & isIO & addr[IO_LEDS_bit])
      leds <= writedata[9:0];

  assign IO_readdata = addr[IO_SW_bit]  ? {22'b0, SW}      :
                       addr[IO_KEY_bit] ? {31'b0, ~KEY[0]} : 32'b0;
  assign readdata    = isIO ? IO_readdata : MEM_readdata;

  assign LEDR = leds[9:0];
endmodule
