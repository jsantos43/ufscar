module power_on_reset(
  input clk, 
  output reset);

  reg [3:0] q = 0;
 
  always@(posedge clk)
    q <= {q, 1'b1};

  assign reset = !(&q);
endmodule
