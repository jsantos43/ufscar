module top (
  input clk, rst,
  output [31:0] fibonacci_bus);

  // gere o controle do barramento aqui

  reg oe_a = 1;
  reg oe_b = 0; 

  always @(negedge clk) begin
    oe_a <= !oe_a;
    oe_b <= !oe_b;
  end

  // instancie os dois módulos fibo aqui
  
  fibo a(clk, rst, oe_a, fibonacci_bus);
  fibo b(clk, rst, oe_b, fibonacci_bus);
endmodule

module fibo (
  input clk, rst, enable, 
  inout tri [31:0] bus);
  integer value;

  // implemente a lógica do módulo fibo aqui

  always @(posedge clk) begin
    if (rst) begin
      value <= 1;
    end else begin
      value <= enable ? value : value + bus;
    end
  end

  assign bus = enable ? value : 32'bZ;
endmodule