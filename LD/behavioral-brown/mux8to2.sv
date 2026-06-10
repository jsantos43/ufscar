module mux8to2 (W, S, f); 
  input [7:0] W;
  input [1:0] S;
  output [1:0] f;

  assign f = S == 0 ? W[1:0] : (S == 1 ? W[3:2] : (S == 2 ? W[5:4] : W[7:6]));
endmodule