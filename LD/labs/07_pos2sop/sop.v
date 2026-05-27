module osp (
  input x, y, z,
  output);
  assign f = (~x & ~y & ~z) | (~x & y & z) | (x & ~y & z) | (x & y & ~z)

endmodule