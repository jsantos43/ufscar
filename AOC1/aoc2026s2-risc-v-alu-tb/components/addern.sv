module addern (carryin, X, Y, S, carryout, overflow); // figure3.28.v
	parameter n = 32;
	input carryin;
	input [n-1:0] X, Y;
	output [n-1:0] S;
	output carryout, overflow;
	wire [n:0] C;
	assign C[0] = carryin;

	// Cada somador passa o carry para o proximo bit.
	genvar i;
	generate
		for (i = 0; i < n; i = i + 1) begin : bits_soma
			full_adder bit_soma (
				.Cin(C[i]), .X(X[i]), .Y(Y[i]),
				.S(S[i]), .Cout(C[i+1])
			);
		end
	endgenerate
	assign carryout = C[n];
	assign overflow = C[n] ^ C[n-1];
endmodule
