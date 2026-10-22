module testbench();
  logic        clk, reset, memwrite;
  logic        entrada;
  logic [31:0] writedata, addr, readdata, ramdata;
  logic [9:0]  sequencia;

  // enderecos de E/S (labels entrada e saida do deslocador.asm)
  localparam ENTRADA_ADDR = 32'h00000100;
  localparam SAIDA_ADDR   = 32'h00000104;

  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata);

  // memory
  mem ram(clk, memwrite, addr, writedata, ramdata);

  // leituras do endereco de entrada recebem o dado de entrada do testbench
  assign readdata = (addr == ENTRADA_ADDR) ? {31'b0, entrada} : ramdata;

  // desloca: o programa escreveu uma nova sequencia
  // espera:  o programa leu a entrada = 0 e continua parado
  event desloca, espera;

  // initialize test
  initial
    begin
      $dumpfile("dump.vcd"); $dumpvars(0);
      entrada <= 0;
      reset <= 1; #15 reset <= 0;
      repeat (3) @(espera);  entrada <= 1;  // sai de 0000000001 para a esquerda
      repeat (3) @(desloca); entrada <= 0;
      repeat (2) @(desloca); entrada <= 1;  // ignorado: ainda esta deslocando
      repeat (2) @(desloca); entrada <= 0;  // chega em 1000000000 e para
      repeat (3) @(espera);  entrada <= 1;  // volta para a direita
      repeat (2) @(desloca); entrada <= 0;  // chega em 0000000001 e para
      repeat (3) @(espera);  entrada <= 1;  // fica em 1: vai e volta direto
      repeat (16) @(desloca); entrada <= 0; // chega em 0000000001 e para
      repeat (3) @(espera);  $finish;
    end

  // seguranca caso o programa trave
  initial #50000 begin $display("Tempo esgotado!"); $finish; end

  // generate clock to sequence tests
  always
    begin
      clk <= 1; # 5; clk <= 0; # 5;
    end

  // mostra tempo, entrada e sequencia a cada deslocamento
  // e a cada leitura da entrada enquanto a sequencia esta parada
  initial
    $display(" tempo | entrada | sequencia");

  always @(negedge clk)
    if (memwrite && addr == SAIDA_ADDR) begin
      sequencia = writedata[9:0];
      $display("%6t |    %b    | %b", $time, entrada, sequencia);
      -> desloca;
    end
    else if (cpu.state == cpu.WAIT_DATA && addr == ENTRADA_ADDR && !entrada) begin
      $display("%6t |    %b    | %b", $time, entrada, sequencia);
      -> espera;
    end
endmodule
