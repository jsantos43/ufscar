module top (input mtpx, input mtpy, output mtpz);
    // use os fios a seguir de acordo com a figura
    wire a1, b1, a2, b2, a1b1, a2b2;
    // Implemente a primeira parte do circuito usando os módulos ma e mb
    // Preste atenção nas portas desconectadas 

    ma ia1(.mapx(mtpx), .mapy(), .mapz(a1));
    mb ib1(.mbpx(mtpx), .mbpy(mtpy), .mbpz(b1));
    ma ia2(.mapx(mtpx), .mapy(mtpy), .mapz(a2));
    mb ib2(.mbpx(), .mbpy(mtpy), .mbpz(b2));

    // Implemente a segunda parte do circuito usando primitivas da linguagem
    or p1(a1b1, a1, b1);
    and p2(a2b2, a2, b2);
    xor p3(mtpz, a1b1, a2b2);


endmodule
