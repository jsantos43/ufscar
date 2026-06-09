module top (
    input [31:0] in, 
    input [1:0] sel, 
    output [7:0] out);

    //declare os fios intermediarios
    wire [7:0] w1, w2;

    // Primeira camada
    mux2byte m1 (in[7:0], in[15:8], sel[0], w1);
    mux2byte m2 (in[23:16], in[31:24], sel[0], w2);

    // Segunda camada
    mux2byte m3 (w1, w2, sel[1], out);
endmodule