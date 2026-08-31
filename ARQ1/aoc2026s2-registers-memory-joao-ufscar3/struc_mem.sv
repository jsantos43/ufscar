module struc_mem(
    input clk,
    input write_enable,
    input [2:0] address, // read/write address
    input [31:0] data_in,
    output [31:0] data_out);
    
    wire [31:0] o7, o6, o5, o4, o3, o2, o1, o0; // outputs of registers
    wire [7:0] re, en; // enable signals for registers

    decoder3x8 dec(address, re); // decode address to enable one register
    assign en = {8{write_enable}} & re; // enable only if write_enable is high

    register w0(clk, en[0], data_in, o0);
    register w1(clk, en[1], data_in, o1);
    register w2(clk, en[2], data_in, o2);
    register w3(clk, en[3], data_in, o3);
    register w4(clk, en[4], data_in, o4);
    register w5(clk, en[5], data_in, o5);
    register w6(clk, en[6], data_in, o6);
    register w7(clk, en[7], data_in, o7);

    mux8to1 mux(o7, o6, o5, o4, o3, o2, o1, o0, address, data_out); // asynchronous select output based on address
endmodule