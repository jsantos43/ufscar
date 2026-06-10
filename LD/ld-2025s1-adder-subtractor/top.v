
module top (
    input  [31:0] a,
    input  [31:0] b,
    input         sub,         // 0 = soma, 1 = subtração
    output [31:0] result,
    output        carry_out,
    output        overflow);

    wire [32:0] carry; // Carry in para cada operação do bits
    wire [31:0] b_xor; // Vetor dos bits de b, caso seja necessário inverter cada um

    // Se sub for 1, inverte todos os bits de b para realizar a subtração
    // XOR com 1 inverte o bit(subtração), XOR com 0 deixa igual
    assign b_xor = b ^ {32{sub}};

    // carry[0] é 0 na soma, e é 1 na subtração
    assign carry[0] = sub;

    genvar i;

    // Esse generate cria uma instancia do stage full_adder para cada interação, 
    // na prática esse genvar i nem existe no circuito
    generate
        for (i = 0; i < 32; i = i + 1) begin : stage
            full_adder somador (a[i], b_xor[i], carry[i], result[i], carry[i+1]);
        end
    endgenerate

    assign carry_out = carry[32];

    // Overflow: carry de entrada no bit 31 ≠ carry de saída do bit 31
    assign overflow = carry[31] ^ carry[32];

endmodule