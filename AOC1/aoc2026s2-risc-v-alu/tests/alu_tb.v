`timescale 1ns/1ns

module alu_tb;
    // Declare testbench variables
    reg [127:0] test_vector [0:20];
    integer i;
    reg [31:0] op1; // rs1;
    reg [31:0] op2; // rs2 or Immediate;
    reg [31:0] instr; // instruction
    reg [31:0] res_exp; // result 
    wire [31:0] res;

    // Instantiate the design under test
    alu dut (op1, op2, instr, res);

    // VCD waveform generation, $monitor formating
    initial begin
        $dumpfile("alu_tb.vcd");
        $dumpvars(0, alu_tb);
        $readmemh("values.tv", test_vector);
        $monitor("Time: %3t, instr: %h, op1: %h, op2: %h, res: %h", $time, instr, op1, op2, res);
        for (i = 0; i <= 20; i++) begin
            instr =   test_vector[i][127:96];
            op1 =     test_vector[i][ 95:64];
            op2 =     test_vector[i][ 63:32];
            res_exp = test_vector[i][ 31: 0];
            #10
            if (res !== res_exp)
                $display("Error in test %0d! res=%h expected=%h", i, res, res_exp);
        end
        #10 $finish;
    end
endmodule