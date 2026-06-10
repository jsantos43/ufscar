module top (
  input [15:0] W,
  output [3:0] Y,
  output Z
  ); 
  
  wire [1:0] y3, y2, y1, y0;
  wire z3, z2, z1, z0;

  priority_encoder p3 (W[15:12], y3, z3);
  priority_encoder p2 (W[11:8], y2, z2);
  priority_encoder p1 (W[7:4], y1, z1);
  priority_encoder p0 (W[3:0], y0, z0);

  wire [3:0] valid_bus;
  wire [1:0] msb_out;

  assign valid_bus = {z3, z2, z1, z0};

  priority_encoder pe_master (valid_bus, msb_out, Z);

  wire [7:0] mux_input;
  wire [1:0] lsb_out;

  assign mux_input = {y3, y2, y1, y0};
  mux8to2 mux_selector (mux_input, msb_out, lsb_out);
  
  assign Y = {msb_out, lsb_out};  
  //Insta7ncie aqui os componentes disponiveis para formar um codificador de 16x4

  
endmodule