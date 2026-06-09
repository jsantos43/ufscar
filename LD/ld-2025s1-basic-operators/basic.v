module basic(
  input a, 
  input b, 
  output buf_a,
  output not_b,
  output a_and_b,
  output a_or_b,
  output a_xor_b,
  output a_nand_b,
  output a_nor_b,
  output a_xnor_b);

  assign buf_a = a;
  assign not_b = ~b; 
  assign a_and_b = a & b;
  assign a_or_b = a | b;
  assign a_xor_b = a ^ b;
  assign a_nand_b = (~a) | (~b);
  assign a_nor_b = (~a) & (~b);
  assign a_xnor_b = (a & b) | ((~a) & (~b));
  // assign ... 
endmodule
