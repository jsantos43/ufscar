module top (
    input x, y, z, 
    output f);

    wire f0, f1;

    assign f0 = ~y & z;
    assign f1 = ~y | z;       

    assign f = x ? f1 : f0;
endmodule