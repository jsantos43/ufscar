module vector(
  input [3:0] a,
  input [3:0] b,
  output [3:0] a_bitwise_or_b,
  output a_logical_or_b,
  output a_reduction_or,
  output b_reduction_or,
  output [7:0] not_a_not_b);

  assign a_bitwise_or_b = a | b;
  assign a_logical_or_b = a || b;
  assign a_reduction_or = |a;
  assign b_reduction_or = |b;
  assign not_a_not_b = {~a, ~b};

endmodule
