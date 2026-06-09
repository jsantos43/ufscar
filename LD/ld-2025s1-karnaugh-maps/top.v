module top (
    input a, b, c, d,
    output f1, f2, f3);

    assign f1 = (~c & ~d) | (~a & ~b & c & d) | (a & b & d);
    assign f2 = (b | c | d) & (a | ~c) & (~b | ~d); 
    assign f3 = (a & ~c) | (b & c & d) | (~a & ~b & ~d) | (~a & ~b & c);

endmodule