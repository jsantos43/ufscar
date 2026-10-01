module mux4to1 (W, S, f); // figure4.28.v
	input [0:3] W;
	input [1:0] S;
	output f;

	assign f = S == 0 ? W[0] : (S == 1 ? W[1] : (S == 2 ? W[2] : W[3]));
endmodule

