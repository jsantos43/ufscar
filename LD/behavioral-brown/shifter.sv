module shifter (W, Shift, Y , k); //figure4.54.v
	input [3:0] W;
	input Shift;
	output [3:0] Y;
	output k;
	
    assign Y = Shift ? (W >> 1) : W;
    assign k = Shift ? W[0] : 1'b0;

endmodule