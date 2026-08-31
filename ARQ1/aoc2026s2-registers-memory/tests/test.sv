// Testbench
module test;
    reg clk, write_enable;
    reg [2:0] address;
    wire [31:0] sm_data, bm_data;
    integer i;

    top dut(clk, write_enable, address, sm_data, bm_data);

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, test);
        $monitor("Time: %0t | Address: %0d | BM Data: %h | SM Data: %h", $time, address, bm_data, sm_data);
        clk = 0;
        write_enable = 1;
        address = 0;
        // Initialize clock
        forever #5 clk = ~clk; // Toggle clock every 5 time units
    end

    initial begin
        // Apply test vectors
        for (i = 0; i <= 8; i = i + 1) begin
            @(negedge clk);
            address = i;
        end
        $writememh("values.out", dut.bm.memory); // Save final memory state to a file
        $finish; // End simulation
    end 

endmodule