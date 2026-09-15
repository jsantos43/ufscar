module mux8to1 (
  input [31:0] W7, W6, W5, W4, W3, W2, W1, W0,
  input [2:0] S,
  output reg [31:0] f);

  always @(*)
    case (S)
      3'b000: f = W0;
      3'b001: f = W1;
      3'b010: f = W2;
      3'b011: f = W3;
      3'b100: f = W4;
      3'b101: f = W5;
      3'b110: f = W6;
      3'b111: f = W7;
    endcase
endmodule