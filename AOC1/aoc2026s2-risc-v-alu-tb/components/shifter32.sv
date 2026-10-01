module shifter32 (W, amount, left, arithmetic, Y);
    input [31:0] W;
    input [4:0] amount;
    input left, arithmetic;
    output [31:0] Y;

    wire [31:0] L [0:5];
    wire [31:0] R [0:5];
    wire [31:0] A [0:5];
    wire [31:0] right_result;
    assign L[0] = W;
    assign R[0] = W;
    assign A[0] = W;

    // Etapas de 1, 2, 4, 8 e 16 bits. A soma chega a 31 bits.
    genvar i;
    generate
        for (i = 0; i < 5; i = i + 1) begin : etapas
            shifter #(.n(32), .distance(2**i), .left(1)) sll (
                .W(L[i]), .Shift(amount[i]), .Y(L[i+1]), .k()
            );
            shifter #(.n(32), .distance(2**i)) srl (
                .W(R[i]), .Shift(amount[i]), .Y(R[i+1]), .k()
            );
            shifter #(.n(32), .distance(2**i), .arithmetic(1)) sra (
                .W(A[i]), .Shift(amount[i]), .Y(A[i+1]), .k()
            );
        end
    endgenerate

    mux select_right (.W0(R[5]), .W1(A[5]), .S(arithmetic), .f(right_result));
    mux select_direction (.W0(right_result), .W1(L[5]), .S(left), .f(Y));
endmodule
