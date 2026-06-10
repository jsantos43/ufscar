module dec2to4 (
	input [1:0] W, 
	input En, 
	output [0:3] Y
);
	
	assign Y = En == 0 ? 4'b0000 : (W == 0 ? 4'b1000 : (W == 1 ? 4'b0100 : (W == 2 ? 4'b0010 : 4'b0001)));
endmodule
