module top (
  input [2:0] SW,
  output [9:0] LEDR,
)

  wire f_pos, f_sop;

  pos p_inst(SW[2], SW[1], SW[0], f_pos);
  sop s_inst(SW[2], SW[1], SW[0], f_sop);

  assign LEDR[0] = f_pos;
  assign LEDR[1] = f_pos;
  assign LEDR[2] = f_pos;
  assign LEDR[3] = f_pos;
  assign LEDR[4] = f_pos;
  assign LEDR[5] = f_sop;
  assign LEDR[6] = f_sop;
  assign LEDR[7] = f_sop;
  assign LEDR[8] = f_sop;
  assign LEDR[9] = f_sop;


endmodule