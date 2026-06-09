module top (
    input x, y, z,
    output f);
    // assign f = ~y & ~z | ~x & z;
    assign f = ~x & ~y & z
endmodule