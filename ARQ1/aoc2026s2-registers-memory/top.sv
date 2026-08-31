module top (
  input clk,
  input write_enable,
  input [2:0] address,
  output [31:0] sm_data, bm_data); 

  wire [31:0] initial_bm;
  assign initial_bm = 32'hc0000001;
  
  // Instancie a memória comportamental com o nome "bm" e conecte suas portas
  behav_mem bm (clk, write_enable, address, initial_bm, bm_data);  
  
  // Instancie a memória estrutural com o nome "sm" e conecte suas portas
  struc_mem sm (clk, write_enable, address, bm_data, sm_data);

endmodule