module comparator (X, Y, V, N, Z, LTU); // figure3.47.v
	parameter n = 32;
	input [n-1:0] X, Y; 
	output V, N, Z, LTU; // V = Overflow, N = Negativo
	wire [n-1:0] S; // Valor final da subtração
	wire [n:0] C; // Bit do carry-in

	assign C[0] = 1'b1;

	// Estrutura básica de um full adder
	genvar k;	
    generate
        for (k = 0; k < n; k = k + 1) begin : ripple
			full_adder bit_sub (
				.Cin(C[k]), .X(X[k]), .Y(~Y[k]),
				.S(S[k]), .Cout(C[k+1])
			);
        end
    endgenerate

    assign V = C[n] ^ C[n-1];
    assign N = S[n-1];
    assign Z = ~|S;
    // Sem carry em X - Y significa X < Y, sem sinal.
    // Para comparar com sinal, usamos N ^ V.
    assign LTU = ~C[n];
endmodule
