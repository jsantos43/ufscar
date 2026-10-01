module mux (W0, W1, S, f);
    parameter n = 32;
    input [n-1:0] W0, W1;
    input S;
    output [n-1:0] f;

    assign f = S ? W1 : W0;
endmodule
