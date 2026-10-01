module ula (
    input [31:0] SrcA, SrcB,
    // 000 ADD/SUB, 001 SLL, 010 SLT, 011 SLTU,
    // 100 XOR, 101 SRL/SRA, 110 OR, 111 AND.
    input [2:0] aluOp,
    input subtract, arithmeticShift,
    output [31:0] res,
    output EQ, LT, LTU
);
    wire [31:0] operand_b, sum, shifted;
    wire [31:0] result_low, result_high;
    wire [31:0] signed_less, unsigned_less;
    wire negative, overflow;

    // Em SUB, invertemos B e colocamos 1 no carry inicial.
    assign operand_b = SrcB ^ {32{subtract}};
    addern soma_subtracao (
        .carryin(subtract), .X(SrcA), .Y(operand_b), .S(sum),
        .carryout(), .overflow()
    );

    comparator comparacao (
        .X(SrcA), .Y(SrcB), .V(overflow), .N(negative),
        .Z(EQ), .LTU(LTU)
    );
    assign LT = negative ^ overflow;
    assign signed_less = {31'b0, LT};
    assign unsigned_less = {31'b0, LTU};

    shifter32 deslocamento (
        .W(SrcA), .amount(SrcB[4:0]), .left(aluOp == 3'b001),
        .arithmetic(arithmeticShift), .Y(shifted)
    );

    // Dois mux4to1 por bit escolhem entre as oito operacoes.
    // W[0] recebe o primeiro elemento da concatenacao.
    genvar i;
    generate
        for (i = 0; i < 32; i = i + 1) begin : selecao
            mux4to1 grupo_0 (
                .W({sum[i], shifted[i], signed_less[i], unsigned_less[i]}),
                .S(aluOp[1:0]), .f(result_low[i])
            );
            mux4to1 grupo_1 (
                .W({SrcA[i] ^ SrcB[i], shifted[i],
                    SrcA[i] | SrcB[i], SrcA[i] & SrcB[i]}),
                .S(aluOp[1:0]), .f(result_high[i])
            );
        end
    endgenerate
    mux resultado (.W0(result_low), .W1(result_high), .S(aluOp[2]), .f(res));
endmodule
