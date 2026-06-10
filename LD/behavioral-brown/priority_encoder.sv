module priority_encoder (
  input [3:0] W,
  output [1:0] Y,
  output Z);

  assign Y = W[3] ? 2'd3 : W[2] ? 2'd2 : W[1] ? 2'd1 :  W[0] ? 2'd0 : 2'bx; 
  assign Z = |W;
endmodule