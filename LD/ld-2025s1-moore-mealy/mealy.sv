module mealy (
    input clk, rst, w, 
    output reg z);

    reg [2:0] estado = 3'b000;
    reg [2:0] prox_estado = 3'b000;

    // Detectar sequencia 1001

    // Detecta mudanças na entrada, qualquer momento, independe da borda do clock
    always @(*) begin
        case (estado)
            3'b000: begin // 1 estado
                prox_estado = w ? 3'b001 : 3'b000;
                z = 0;
            end
            3'b001: begin // 2 estado
                prox_estado = w == 0 ? 3'b010 : 3'b001;
                z = 0;
            end
            3'b010: begin // 3 estado
                prox_estado = w == 0 ? 3'b011 : 3'b001;
                z = 0;
            end
            3'b011: begin // 4 estado
                prox_estado = w ? 3'b100 : 3'b000;
                z = w;
            end
            3'b100: begin
                prox_estado = w ? 3'b001 : 3'b010;
                z = 0;
            end
        endcase
    end

    // Só para verificar a troca de estado
    // É feita na borda do clock
    always @(posedge clk or posedge rst)
        estado <= rst ? 3'b000 : prox_estado;


endmodule