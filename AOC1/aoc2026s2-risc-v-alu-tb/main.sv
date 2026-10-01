module main (
    input [31:0] op1,   // Valor de rs1.
    input [31:0] op2,   // Valor de rs2.
    input [31:0] Instr, // Instrucao ja codificada pelo montador.
    output [31:0] res,
    input [31:0] pc,    // Endereco da instrucao atual.
    output reg branchTaken,
    output [31:0] target,
    output reg valid   // Instrucao atendida por este bloco de ULA/decode.
);
    wire [6:0] opcode = Instr[6:0];
    wire [2:0] funct3 = Instr[14:12];
    wire [6:0] funct7 = Instr[31:25];

    wire [31:0] Iimm = {{20{Instr[31]}}, Instr[31:20]};
    wire [31:0] Simm = {{20{Instr[31]}}, Instr[31:25], Instr[11:7]};
    wire [31:0] Bimm = {{19{Instr[31]}}, Instr[31], Instr[7],
                       Instr[30:25], Instr[11:8], 1'b0};
    wire [31:0] Uimm = {Instr[31:12], 12'b0};
    wire [31:0] Jimm = {{11{Instr[31]}}, Instr[31], Instr[19:12],
                       Instr[20], Instr[30:21], 1'b0};

    reg [31:0] SrcA, SrcB;
    reg [2:0] aluOp;
    reg subtract, arithmeticShift;
    reg isBranch, isJump, isJALR;
    wire [31:0] aluResult;
    wire EQ, LT, LTU;

    // O decode escolhe os operandos e a operacao; a ULA faz o calculo.
    always @(*) begin
        SrcA = op1;
        SrcB = op2;
        aluOp = 3'b000;
        subtract = 1'b0;
        arithmeticShift = 1'b0;
        isBranch = 1'b0;
        isJump = 1'b0;
        isJALR = 1'b0;
        valid = 1'b0;

        case (opcode)
            7'b0110011: begin // ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND.
                aluOp = funct3;
                valid = (funct7 == 7'b0000000) ||
                        ((funct7 == 7'b0100000) &&
                         ((funct3 == 3'b000) || (funct3 == 3'b101)));
                subtract = (funct3 == 3'b000) && funct7[5];
                arithmeticShift = (funct3 == 3'b101) && funct7[5];
            end
            7'b0010011: begin // Versoes com imediato.
                SrcB = Iimm;
                aluOp = funct3;
                valid = 1'b1;
                if (funct3 == 3'b001)
                    valid = (funct7 == 7'b0000000);
                if (funct3 == 3'b101) begin
                    valid = (funct7 == 7'b0000000) || (funct7 == 7'b0100000);
                    arithmeticShift = funct7[5];
                end
            end
            7'b0000011: begin // LB, LH, LW, LBU, LHU: endereco rs1 + Iimm.
                SrcB = Iimm;
                valid = (funct3 == 3'b000) || (funct3 == 3'b001) ||
                        (funct3 == 3'b010) || (funct3 == 3'b100) ||
                        (funct3 == 3'b101);
            end
            7'b0100011: begin // SB, SH, SW: endereco rs1 + Simm.
                SrcB = Simm;
                valid = (funct3 == 3'b000) || (funct3 == 3'b001) ||
                        (funct3 == 3'b010);
            end
            7'b0110111: begin // LUI: 0 + Uimm.
                SrcA = 32'b0;
                SrcB = Uimm;
                valid = 1'b1;
            end
            7'b0010111: begin // AUIPC: PC + Uimm.
                SrcA = pc;
                SrcB = Uimm;
                valid = 1'b1;
            end
            7'b1100011: begin // BEQ, BNE, BLT, BGE, BLTU, BGEU.
                subtract = 1'b1;
                isBranch = 1'b1;
                valid = (funct3 == 3'b000) || (funct3 == 3'b001) ||
                        (funct3 == 3'b100) || (funct3 == 3'b101) ||
                        (funct3 == 3'b110) || (funct3 == 3'b111);
            end
            7'b1101111: begin // JAL: destino PC + Jimm; retorno PC + 4.
                SrcA = pc;
                SrcB = Jimm;
                isJump = 1'b1;
                valid = 1'b1;
            end
            7'b1100111: begin // JALR: destino rs1 + Iimm, bit zero limpo.
                SrcB = Iimm;
                isJump = 1'b1;
                isJALR = 1'b1;
                valid = (funct3 == 3'b000);
            end
            default: begin
                // FENCE, ECALL e EBREAK sao tratados pelo controle do
                // processador, fora da ULA. valid permanece em zero.
            end
        endcase
    end

    ula ula_inst (
        .SrcA(SrcA), .SrcB(SrcB), .aluOp(aluOp),
        .subtract(subtract), .arithmeticShift(arithmeticShift),
        .res(aluResult), .EQ(EQ), .LT(LT), .LTU(LTU)
    );

    // A comparacao usa rs1/rs2 enquanto este somador calcula PC + Bimm.
    // Para saltos, o mesmo somador calcula o endereco de retorno PC + 4.
    wire [31:0] pcOffset, pcResult;
    mux offset_pc (.W0(32'd4), .W1(Bimm), .S(isBranch), .f(pcOffset));
    addern soma_pc (
        .carryin(1'b0), .X(pc), .Y(pcOffset), .S(pcResult),
        .carryout(), .overflow()
    );

    always @(*) begin
        branchTaken = 1'b0;
        if (valid && isBranch) begin
            case (funct3)
                3'b000: branchTaken = EQ;
                3'b001: branchTaken = ~EQ;
                3'b100: branchTaken = LT;
                3'b101: branchTaken = ~LT;
                3'b110: branchTaken = LTU;
                3'b111: branchTaken = ~LTU;
                default: branchTaken = 1'b0;
            endcase
        end
    end

    wire [31:0] jumpTarget, selectedResult, selectedTarget;
    mux destino_salto (
        .W0(aluResult), .W1({aluResult[31:1], 1'b0}),
        .S(isJALR), .f(jumpTarget)
    );
    mux destino (.W0(jumpTarget), .W1(pcResult), .S(isBranch), .f(selectedTarget));
    mux retorno (.W0(aluResult), .W1(pcResult), .S(isJump), .f(selectedResult));
    assign res = valid ? selectedResult : 32'b0;
    assign target = valid && (isBranch || isJump) ? selectedTarget : 32'b0;
endmodule
