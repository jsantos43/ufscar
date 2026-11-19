module vga #(
  parameter
  WIDTH = 640, HEIGHT = 480, // 640 x 480 @ 25 MHz (negative)
  HFRONT = 16, HSYNC = 96, HBACK = 48, HPULSEN = 1,
  VFRONT = 10, VSYNC =  2, VBACK = 33, VPULSEN = 1
) (
  input clk, reset,
  output reg vga_HS, vga_VS, vga_DA,
  output [31:0] vaddr);

  reg [9:0] CounterX, CounterY;
  wire CounterXmaxed = (CounterX == (WIDTH + HFRONT + HSYNC + HBACK));
  wire CounterYmaxed = (CounterY == (HEIGHT + VFRONT + VSYNC + VBACK));

  wire [5:0] row = (CounterY>>5); // 32 pixels x
  wire [5:0] col = (CounterX>>5); // 32 pixels 
  assign vaddr = col + (row<<4) + (row<<2); // addr = col + row x 20

  always @(posedge clk or posedge reset)
  if (reset) begin
    CounterX <= 10'b0;
    CounterY <= 10'b0;
  end
  else
  begin
    if (CounterXmaxed)
      CounterX <= 10'b0;
    else
      CounterX <= CounterX + 1'b1;
		
    if (CounterXmaxed)
      if(CounterYmaxed)
        CounterY <= 10'b0;
      else
        CounterY <= CounterY + 1'b1;

    vga_DA <= (CounterX < WIDTH) && (CounterY < HEIGHT);
    vga_HS <= HPULSEN[0] ^ (CounterX > ( WIDTH + HFRONT) && (CounterX < ( WIDTH + HFRONT + HSYNC)));
    vga_VS <= VPULSEN[0] ^ (CounterY > (HEIGHT + VFRONT) && (CounterY < (HEIGHT + VFRONT + VSYNC)));
  end
endmodule