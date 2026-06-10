module compare (A, B, AeqB, AgtB, AltB); //figure4.40.v
	input [3:0] A, B;
	output AeqB, AgtB, AltB; // A == B, A > B, A < B
	
    assign AeqB = (A == B);
    assign AgtB = (A > B);
    assign AltB = (A < B);
				
endmodule