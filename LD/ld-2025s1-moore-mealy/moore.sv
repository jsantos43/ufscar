module moore (
    input clk, rst, w, 
    output z);

    reg [2:0] estado = 3'b000;

    always @(posedge clk or posedge rst) begin
        if (rst)
            estado <= 3'b000;
        else begin
            case (estado)
                3'b000: estado <= w ? 3'b001 : 3'b000; // 1 estado
                3'b001: estado <= w == 0 ? 3'b010 : 3'b001; // 2 estado
                3'b010: estado <= w == 0 ? 3'b011 : 3'b001; // 3 estado
                3'b011: estado <= w ? 3'b100 : 3'b000; // 4 estado
                3'b100: estado <= w ? 3'b001 : 3'b010; // 5 estado
            endcase
        end
    end

    assign z = estado == 3'b100 ? 1 : 0;
endmodule