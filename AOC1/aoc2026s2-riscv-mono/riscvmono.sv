module riscvmono(
  input  logic        clk, reset,
  // instruction memory interface
  output logic [31:0] pc, 
  input  logic [31:0] instr,
  // data memory interface
  output logic [31:0] addr, writedata,
  output logic        memwrite,
  input  logic [31:0] readdata);

  assign memwrite = isStore;
  assign addr = rs1 + (isStore ? Simm : Iimm);
  assign writedata = rs2;

  wire [31:0] writeBackData = (isJAL || isJALR) ? PCplus4 : isLUI ? Uimm : isAUIPC ? (pc + Uimm) : isLoad ? readdata : aluOut;
  wire        writeBackEn = isALUreg || isALUimm || isJAL || isJALR || isAUIPC || isLUI || isLoad;
  wire [31:0] aluIn1 = rs1;
  wire [31:0] aluIn2 = (isALUreg || isBranch) ? rs2 : Iimm;

  always@(negedge clk)
    if(writeBackEn && rdId != 0)
	    RegisterBank[rdId] <= writeBackData;

  wire [31:0] PCplusImm = pc + Jimm;
  wire [31:0] PCplus4 = pc + 4;
  always@(posedge clk)
    if (reset)
      pc <= 0;
    else
      pc <= isJAL ? PCplusImm : PCplus4;
  
   // The registers bank
   reg [31:0] RegisterBank [0:31];
   wire [31:0] rs1 = rs1Id ? RegisterBank[rs1Id] : 32'b0; // value of source
   wire [31:0] rs2 = rs2Id ? RegisterBank[rs2Id] : 32'b0; //  registers.

   // The 10 RISC-V instructions
   wire isALUreg  =  (instr[6:0] == 7'b0110011); // rd <- rs1 OP rs2   
   wire isALUimm  =  (instr[6:0] == 7'b0010011); // rd <- rs1 OP Iimm
   wire isBranch  =  (instr[6:0] == 7'b1100011); // if(rs1 OP rs2) PC<-PC+Bimm
   wire isJALR    =  (instr[6:0] == 7'b1100111); // rd <- PC+4; PC<-rs1+Iimm
   wire isJAL     =  (instr[6:0] == 7'b1101111); // rd <- PC+4; PC<-PC+Jimm
   wire isAUIPC   =  (instr[6:0] == 7'b0010111); // rd <- PC + Uimm
   wire isLUI     =  (instr[6:0] == 7'b0110111); // rd <- Uimm   
   wire isLoad    =  (instr[6:0] == 7'b0000011); // rd <- mem[rs1+Iimm]
   wire isStore   =  (instr[6:0] == 7'b0100011); // mem[rs1+Simm] <- rs2
   wire isSYSTEM  =  (instr[6:0] == 7'b1110011); // special

   // The 5 immediate formats
   wire [31:0] Uimm={    instr[31],   instr[30:12], {12{1'b0}}};
   wire [31:0] Iimm={{21{instr[31]}}, instr[30:20]};
   wire [31:0] Simm={{21{instr[31]}}, instr[30:25],instr[11:7]};
   wire [31:0] Bimm={{20{instr[31]}}, instr[7],instr[30:25],instr[11:8],1'b0};
   wire [31:0] Jimm={{12{instr[31]}}, instr[19:12],instr[20],instr[30:21],1'b0};

   // Source and destination registers
   wire [4:0] rs1Id = instr[19:15];
   wire [4:0] rs2Id = instr[24:20];
   wire [4:0] rdId  = instr[11:7];
   
   // function codes
   wire [2:0] funct3 = instr[14:12];
   wire [6:0] funct7 = instr[31:25];
   
   // The ALU
   wire [4:0] shamt = isALUreg ? rs2[4:0] : instr[24:20]; // shift amount

   // The adder is used by both arithmetic instructions and JALR.
   wire [31:0] aluPlus = aluIn1 + aluIn2;

   // Use a single 33 bits subtract to do subtraction and all comparisons
   // (trick borrowed from swapforth/J1)
   wire [32:0] aluMinus = {1'b1, ~aluIn2} + {1'b0,aluIn1} + 33'b1;
   wire        LT  = (aluIn1[31] ^ aluIn2[31]) ? aluIn1[31] : aluMinus[32];
   wire        LTU = aluMinus[32];
   wire        EQ  = (aluMinus[31:0] == 0);

   // Flip a 32 bit word. Used by the shifter (a single shifter for
   // left and right shifts, saves silicium !)
   function [31:0] flip32;
      input [31:0] x;
      flip32 = {x[ 0], x[ 1], x[ 2], x[ 3], x[ 4], x[ 5], x[ 6], x[ 7], 
                x[ 8], x[ 9], x[10], x[11], x[12], x[13], x[14], x[15], 
                x[16], x[17], x[18], x[19], x[20], x[21], x[22], x[23],
                x[24], x[25], x[26], x[27], x[28], x[29], x[30], x[31]};
   endfunction

   wire [31:0] shifter_in = (funct3 == 3'b001) ? flip32(aluIn1) : aluIn1;
   wire [31:0] shifter = $signed({instr[30] & aluIn1[31], shifter_in}) >>> aluIn2[4:0];
   wire [31:0] leftshift = flip32(shifter);
   
   // ADD/SUB/ADDI: 
   // funct7[5] is 1 for SUB and 0 for ADD. We need also to test instr[5]
   // to make the difference with ADDI
   //
   // SRLI/SRAI/SRL/SRA: 
   // funct7[5] is 1 for arithmetic shift (SRA/SRAI) and 
   // 0 for logical shift (SRL/SRLI)
   reg [31:0]  aluOut;
   always @(*) begin
      case(funct3)
        3'b000: aluOut = (funct7[5] & instr[5]) ? aluMinus[31:0] : aluPlus;
        3'b001: aluOut = leftshift;
        3'b010: aluOut = {31'b0, LT};
        3'b011: aluOut = {31'b0, LTU};
        3'b100: aluOut = (aluIn1 ^ aluIn2);
        3'b101: aluOut = shifter;
        3'b110: aluOut = (aluIn1 | aluIn2);
        3'b111: aluOut = (aluIn1 & aluIn2);	
      endcase
   end
endmodule