module top #(parameter VGA_BITS = 4) (
  input CLOCK_50, // 50MHz
  input [9:0] SW,
  output reg [9:0] LEDR,
  output [6:0] HEX5, HEX4, HEX3, HEX2, HEX1, HEX0,
  output [VGA_BITS-1:0] VGA_R, VGA_G, VGA_B,
  output VGA_HS, VGA_VS,
  output reg VGA_CLK);

  wire VGA_DA; // In display area
  
  wire memwrite, clk, reset;
  wire [31:0] pc, instr;
  wire [31:0] writedata, addr, readdata;
  wire [31:0] vaddr, vdata;
  wire [ 7:0] vbyte = vaddr[1] ? (vaddr[0] ? vdata[31:24] : vdata[23:16])
                               : (vaddr[0] ? vdata[15: 8] : vdata[ 7: 0]);
  integer counter = 0; 
  
  always @(posedge CLOCK_50)
    VGA_CLK <= ~VGA_CLK;

  always @(posedge CLOCK_50) 
      counter <= counter + 1;
  `ifdef SIM
  assign clk = counter[0];  
  `else     
  assign clk = CLOCK_50;
  `endif

  // power-on reset
  power_on_reset por(clk, reset);
    
  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata);

  // memory 
  mem ram(clk, memwrite, addr, writedata, readdata, 'h200 + vaddr, vdata);

  // VGA controller
  vga gpu(VGA_CLK, reset, VGA_HS, VGA_VS, VGA_DA, vaddr);

  // memory-mapped i/o
  wire isIO  = addr[8]; // 0x0000_0100
  wire isRAM = !isIO;
  localparam IO_LEDS_bit = 2; // 0x0000_0104
  localparam IO_HEX_bit  = 3; // 0x0000_0108
  reg [23:0] hex_digits; // memory-mapped I/O register for HEX
  dec7seg hex0(hex_digits[ 3: 0], HEX0);
  dec7seg hex1(hex_digits[ 7: 4], HEX1);
  dec7seg hex2(hex_digits[11: 8], HEX2);
  dec7seg hex3(hex_digits[15:12], HEX3);
  dec7seg hex4(hex_digits[19:16], HEX4);
  dec7seg hex5(hex_digits[23:20], HEX5);
  always @(posedge clk)
    if (memwrite & isIO) begin // memory-mapped I/O
      if (addr[IO_LEDS_bit])
        LEDR <= writedata;
      if (addr[IO_HEX_bit])
        hex_digits <= writedata;
    end
  wire [VGA_BITS-3:0] fill = {VGA_BITS-2{1'b0}};
  assign VGA_R = VGA_DA ? {vbyte[5:4], fill} : 0;
  assign VGA_G = VGA_DA ? {vbyte[3:2], fill} : 0;
  assign VGA_B = VGA_DA ? {vbyte[1:0], fill} : 0;
endmodule

