module register(
    input clk,
    input write_enable,
    input [31:0] data_in,
    output reg [31:0] data_out);

    always @(posedge clk) 
        if (write_enable) 
            data_out = data_in;
endmodule