module top(
    input [3:0] SW,
    output [9:0] LEDR);

    // Transformar os bits do switch para gray bits
    wire [3:0] decode;
    gray2bin g2b(SW, decode);

    // Transformar os gray bits para decimal
    wire [9:0] onehot;
    bin2onehot b2o(decode, onehot);

    // Verificar gray bits válidos
    assign LEDR = |onehot ? onehot : 10'b1111111111;
endmodule

module gray2bin(
    input [3:0] gray_in,
    output [3:0] bin_out);

    assign bin_out = gray_in ^ (gray_in >> 3) ^ (gray_in >> 2) ^ (gray_in >> 1);
endmodule

module bin2onehot (
    input [3:0] bin_in,
    output [9:0] onehot_out);

    assign onehot_out = 10'b1 << bin_in;
endmodule