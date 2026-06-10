module comparator (X, Y, V, N, Z); // figure3.47.v
	parameter n = 32;
	input [n-1:0] X, Y; 
	output V, N, Z; // V = Overflow, N = Negativo 
	wire [n-1:0] S; // Valor final da subtração
	wire [n:0] C; // Bit do carry-in

	assign C[0] = 1'b1;

	// Estrutura básica de um full adder
	genvar k;	
    generate
        for (k = 0; k < n; k = k + 1) begin : ripple
            assign S[k]   = X[k] ^ ~Y[k] ^ C[k];
            assign C[k+1] = (X[k] & ~Y[k]) | (X[k] & C[k]) | (~Y[k] & C[k]);
        end
    endgenerate

    assign V = C[n] ^ C[n-1];
    assign N = S[n-1];
    assign Z = ~|S;
endmodule