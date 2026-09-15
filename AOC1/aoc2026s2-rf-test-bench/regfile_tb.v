`timescale 1ns/1ns

module regfile_tb;
    // Declare testbench variables
    reg clk, we3;
    reg [31:0] test_vector [0:7];
    integer i;
    reg [4:0] ra1, ra2, wa3;
    reg [31:0] wd3;
    wire [31:0] rd1, rd2;

    // VCD waveform generation, $monitor formating, clock generation
    initial begin
        $dumpfile("regfile_tb.vcd");
        $dumpvars(0, regfile_tb);
        $readmemh("../values.tv", test_vector);
        $monitor("Time: %2t, ra1:%d, ra2:%d, wa3:%d, we3:%b, wd3: %h, rd2: %h, rd1: %h", $time, ra1, ra2, wa3, we3, wd3, rd2, rd1);
        clk = 0; we3 = 0;
        forever #5 clk = ~clk;
    end

    // Instantiate the design under test
    regfile dut (clk, we3, ra1, ra2, wa3, wd3, rd1, rd2);

    initial begin
        for (i = 1; i <= 9; i = i + 1) begin
            @(negedge clk);
            if (i == 1)
                ra1 = 5'd0;
            else
                ra1 = wa3;      
            wa3 = i[4:0];    
            ra2 = wa3;       
            we3 = (i <= 8);   
            wd3 = test_vector[i-1]; 
        end

        $finish;
    end

endmodule