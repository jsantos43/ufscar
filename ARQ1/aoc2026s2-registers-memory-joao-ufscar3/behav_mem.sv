module behav_mem(
    input clk,
    input write_enable,
    input [2:0] address, // read/write address
    input [31:0] data_in,
    output [31:0] data_out);

    reg [31:0] memory [0:7]; // 8 words of 32 bits memory

    initial
        $readmemh("../values.tv", memory); // Load initial values from a file

    always @(posedge clk) 
        if (write_enable) 
            memory[address] = data_in; // Synchronous write to memory

    assign data_out = memory[address]; // Asynchronous read from memory
endmodule