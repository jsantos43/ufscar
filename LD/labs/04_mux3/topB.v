module top (
    input x1, x2, x3, s0, s1,
    output xfe, xff);
    mux3e dute(x1, x2, x3, s0, s1, xfe);
    mux3f dutf(x1, x2, x3, s0, s1, xff);
endmodule 

// Estrutural
module mux3e (
    input x1, x2, x3, s0, s1,
    output f);

    wire fio;

    // Instancie e conecte os componentes abaixo
    mux2 muxA(.f(fio), .s(s0), .x1(x3), .x2(x2));
    mux2 muxB(.f(f), .s(s1), .x1(fio), .x2(x1));
endmodule

// Funcional
module mux3f (
    input x1, x2, x3, s0, s1,
    output f);

    // Digite o seu código abaixo  
    assign f = s1 ? x1 : (s0 ? x2 : x3);
endmodule

module mux2(
    output f,
    input x1, x2, s);
    assign f = s ? x2 : x1;
endmodule
