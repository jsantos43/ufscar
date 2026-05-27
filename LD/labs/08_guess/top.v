module top(
  input CLOCK_50,
  input [9:0] SW,
  output [9:0] LEDR,
  output [6:0] HEX5, HEX4, HEX3, HEX2, HEX1, HEX0);

  wire [6:0] dig1, dig0; // fios para inverter os segmentos
  
  integer counter = 0; // contador para piscar
  always @(posedge CLOCK_50)
    counter <= counter + 1;
  assign clk1hz = counter[23];

  wire shuffle = SW[0]; // embaralhar
  wire [7:0] random, guess = SW[8:1]; // palpite

  // implemente a lógica do jogo aqui
  wire match;
  random r1(CLOCK_50, shuffle, random);
  comp c1(random, guess, match);

  dec7seg d1(random[7:4], dig1);
  dec7seg d0(random[3:0], dig0);

  wire blink = clk1hz & match; // pisca se acertou
  assign LEDR = {blink, guess, blink};
  assign HEX1 = ~dig1;
  assign HEX0 = ~dig0;

  // Palavra AE se acertou
  assign HEX3 = match ? ~(7'b1110111) : 7'b1111111; // A
  assign HEX2 = match ? ~(7'b1111001) : 7'b1111111; // E

  // Contador de tempo
  integer counter_temp = 0; // contador para o tempo
  always @(posedge CLOCK_50) begin
    if (~match) begin
      if (shuffle) begin
        counter_temp <= 0;
      end else begin
        counter_temp <= counter_temp + 1;
      end
    end
  end

  wire [1:0] tens = counter_temp[31:26] / 10;
  wire [3:0] ones = counter_temp[31:26] % 10;
  wire [6:0] temp1, temp2;
  
  dec7seg t1({2'b00, tens}, temp1);
  dec7seg t2(ones, temp2);

  assign HEX5 = ~temp1;
  assign HEX4 = ~temp2;
endmodule