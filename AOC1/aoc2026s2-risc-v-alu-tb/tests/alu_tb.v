`timescale 1ns/1ns

module alu_tb;
    parameter COUNT = 1;
    // Mesmo formato original: instrucao_op1_op2_resultado_esperado.
    reg [127:0] test_vector [0:COUNT-1];
    string vectors;
    integer i;
    integer errors = 0;
    reg [31:0] op1, op2, instr, res_exp;
    wire [31:0] res, target;
    wire valid, branchTaken;

    main dut (
        .op1(op1), .op2(op2), .Instr(instr), .pc(32'b0),
        .res(res), .target(target), .valid(valid), .branchTaken(branchTaken)
    );

    initial begin
        if (!$value$plusargs("VECTORS=%s", vectors))
            $fatal(1, "ERRO: informe +VECTORS=arquivo.tv");
        $readmemh(vectors, test_vector);
        $dumpfile("wave.vcd");
        $dumpvars(0, alu_tb);
        for (i = 0; i < COUNT; i = i + 1) begin
            {instr, op1, op2, res_exp} = test_vector[i];
            // Espera o circuito estabilizar antes de registrar a saida.
            #10;
            $display("Time: %3t, instr: %h, op1: %h, op2: %h, res: %h, valid: %b, branch: %b, target: %h",
                     $time, instr, op1, op2, res, valid, branchTaken, target);
            if ((res !== res_exp) || (valid !== 1'b1) ||
                (branchTaken !== 1'b0) || (target !== 32'b0)) begin
                $display("ERRO no vetor %0d: res=%h esperado=%h, valid=%b esperado=1, branch=%b esperado=0, target=%h esperado=00000000",
                         i, res, res_exp, valid, branchTaken, target);
                errors = errors + 1;
            end
        end
        if (errors != 0)
            $fatal(1, "ERRO: %0d vetor(es) incorreto(s)", errors);
        $finish;
    end
endmodule
