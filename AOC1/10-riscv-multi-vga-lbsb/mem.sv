module mem (
  input  logic        clk, we,
  input  logic [31:0] a, wd,
  output logic [31:0] rd,
  input  logic  [3:0] wm);

  logic  [31:0] RAM [0:255];

  // initialize memory with instructions or data
  initial
    $readmemh("riscv.hex", RAM);

  assign rd = RAM[a[31:2]]; // word aligned

  always_ff @(posedge clk)
    if (we) begin
      if(wm[0]) RAM[a[31:2]][7:0] <= wd[7:0];
      if(wm[1]) RAM[a[31:2]][15:8] <= wd[15:8];
      if(wm[2]) RAM[a[31:2]][23:16] <= wd[23:16];
      if(wm[3]) RAM[a[31:2]][31:24] <= wd[31:24];
    end
endmodule