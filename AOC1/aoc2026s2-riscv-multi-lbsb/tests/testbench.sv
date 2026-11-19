module testbench();
  logic        clk, reset, memwrite, halt;
  logic  [3:0] writemask;
  logic [31:0] pc, instr;
  logic [31:0] writedata, addr, readdata;
    
  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata, writemask, halt);

  // memory 
  mem ram(clk, memwrite, addr, writedata, readdata, writemask);

  // initialize test
  initial
    begin
      $dumpfile("dump.vcd"); $dumpvars(0);
      $monitor("pc=%h instr=%h state=%d wbr=%h wm=%b ram[40]=%h", cpu.PC, cpu.instr, cpu.state, cpu.writeBackData, cpu.WriteMask, ram.RAM[32'h40]);
      reset <= 1; #15 reset <= 0;
      #12000 $writememh("riscv.out", ram.RAM);
      $finish;
    end

  // generate clock to sequence tests
  always
    begin
      clk <= 1; # 5; clk <= 0; # 5;
    end

  always @(posedge clk)
    if (halt)
      $writememh("riscv.out", ram.RAM);
endmodule