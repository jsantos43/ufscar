module shifter (W, Shift, Y , k); //figure4.54.v
	parameter n = 4;
	parameter distance = 1;
	parameter left = 0;
	parameter arithmetic = 0;
	input [n-1:0] W;
	input Shift;
	output [n-1:0] Y;
	output k;
	
    wire [n-1:0] shifted;
    // A distancia e fixa em cada componente: apenas ligacoes de fios.
    generate
        if (left) begin : esquerda
            assign shifted = W << distance;
            assign k = Shift ? W[n-distance] : 1'b0;
        end else if (arithmetic) begin : direita_com_sinal
            assign shifted = $signed(W) >>> distance;
            assign k = Shift ? W[distance-1] : 1'b0;
        end else begin : direita_sem_sinal
            assign shifted = W >> distance;
            assign k = Shift ? W[distance-1] : 1'b0;
        end
    endgenerate
    assign Y = Shift ? shifted : W;

endmodule
