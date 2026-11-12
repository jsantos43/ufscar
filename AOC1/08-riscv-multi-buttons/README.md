# Testando seu RISC-V multiciclo na placa

O objetivo desta prática é testar diretamente no kit de FPGA [o processador que você desenvolveu na simulação](https://github.com/DC-UFSCar/riscv-multi) desta semana. Aproveite o `Makefile` fornecido lá para gerar automaticamente o conteúdo da memória a partir do código *assembly*. No processador multiciclo, podemos usar a mesma memória para instruções e dados:

```verilog
  // microprocessor
  riscvmulti cpu(clk, reset, addr, writedata, memwrite, readdata);

  // memory 
  mem ram(clk, memwrite, addr, writedata, MEM_readdata);
```

O esquema de E/S mapeado em memória, [fornecido anteriormente](https://github.com/menotti/aoc/blob/main/labs/06-riscv-mono-leds/top.sv#L25), deve ser alterado da seguinte forma para suportar a leitura dos botões da placa:

```verilog
  // memory-mapped i/o
  wire isIO  = addr[8]; // 0x0000_0100
  wire isRAM = !isIO;
  localparam IO_LEDS_bit = 2; // 0x0000_0104
  localparam IO_HEX_bit  = 3; // 0x0000_0108
  localparam IO_KEY_bit  = 4; // 0x0000_0110 
  localparam IO_SW_bit   = 5; // 0x0000_0120
  reg [23:0] hex_digits; // memory-mapped I/O register for HEX
  dec7seg hex0(hex_digits[ 3: 0], HEX0);
  dec7seg hex1(hex_digits[ 7: 4], HEX1);
  dec7seg hex2(hex_digits[11: 8], HEX2);
  dec7seg hex3(hex_digits[15:12], HEX3);
  dec7seg hex4(hex_digits[19:16], HEX4);
  dec7seg hex5(hex_digits[23:20], HEX5);
  always @(posedge clk)
    if (memwrite & isIO) begin // I/O write 
      if (addr[IO_LEDS_bit])
        LEDR <= writedata;
      if (addr[IO_HEX_bit])
        hex_digits <= writedata;
  end
  assign IO_readdata = addr[IO_KEY_bit] ? {32'b0, KEY} :
                       addr[ IO_SW_bit] ? {32'b0,  SW} : 
                                           32'b0       ;
  assign readdata = isIO ? IO_readdata : MEM_readdata; 
``` 

Aproveite o *test bench* do laboratório anterior para testar o seu _software/hardware_ **antes de programar na placa**.
