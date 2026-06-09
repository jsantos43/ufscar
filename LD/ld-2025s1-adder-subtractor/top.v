
module top (
    input  [31:0] a,
    input  [31:0] b,
    input         sub,         // 0 = soma, 1 = subtração
    output [31:0] result,
    output        carry_out,
    output        overflow);

    genvar i;
    assign C[0] = carryin;
    assign carryout = C[n];
    generate
        for (i = 0; i <= n-1; i = i+1)
            begin:addbit
            full_add stage (C[i], X[i], Y[i], S[i], C[i+1]);
        end
    endgenerate



endmodule