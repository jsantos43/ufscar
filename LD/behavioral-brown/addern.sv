module addern (carryin, X, Y, S, carryout, overflow); // figure3.28.v
	parameter n = 32;
	input carryin;
	input [n-1:0] X, Y;
	output [n-1:0] S;
	output carryout, overflow;
	wire [n:0] Sum;

	assign	Sum = {1'b0, X} + {1'b0, Y} + carryin;
	assign	S = Sum[n-1:0];
	assign	carryout = Sum[n];
	assign	overflow = (X[n-1] & Y[n-1] & ~S[n-1]) | 
		           (~X[n-1] & ~Y[n-1] & S[n-1]);
endmodule
