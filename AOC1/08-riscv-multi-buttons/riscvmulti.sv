module riscvmulti (
    input 	      clk,
    input 	      reset,
    output [31:0] Address, 
    output [31:0] WriteData,
    output 	      MemWrite,
    input  [31:0] ReadData); 

    logic [31:0] instr, PC = 0;

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
    wire [4:0] rs1Id_A1 = instr[19:15];
    wire [4:0] rs2Id_A2 = instr[24:20];
    wire [4:0] rdId_A3  = instr[11:7];

    // function codes
    wire [2:0] funct3 = instr[14:12];
    wire [6:0] funct7 = instr[31:25];

    // The registers bank
    reg [31:0] RegisterBank [0:31];
    reg [31:0] rs1; // value of source
    reg [31:0] rs2; //  registers.

    // The ALU
    wire [31:0] SrcA = rs1;
    wire [31:0] SrcB = isALUreg | isBranch ? rs2 : Iimm;
    wire [ 4:0] shamt  = isALUreg ? rs2[4:0] : instr[24:20]; // shift amount

    // The adder is used by both arithmetic instructions and JALR.
    wire [31:0] aluPlus = SrcA + SrcB;

    // Use a single 33 bits subtract to do subtraction and all comparisons
    // (trick borrowed from swapforth/J1)
    wire [32:0] aluMinus = {1'b1, ~SrcB} + {1'b0,SrcA} + 33'b1;
    wire        LT  = (SrcA[31] ^ SrcB[31]) ? SrcA[31] : aluMinus[32];
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

    wire [31:0] shifter_in = (funct3 == 3'b001) ? flip32(SrcA) : SrcA;
    wire [31:0] shifter = $signed({instr[30] & SrcA[31], shifter_in}) >>> SrcB[4:0];
    wire [31:0] leftshift = flip32(shifter);

    // ADD/SUB/ADDI: 
    // funct7[5] is 1 for SUB and 0 for ADD. We need also to test instr[5]
    // to make the difference with ADDI
    //
    // SRLI/SRAI/SRL/SRA: 
    // funct7[5] is 1 for arithmetic shift (SRA/SRAI) and 
    // 0 for logical shift (SRL/SRLI)
    reg [31:0]  ALUResult;
    always @(*) begin
        case(funct3)
            3'b000: ALUResult = (funct7[5] & instr[5]) ? aluMinus[31:0] : aluPlus;
            3'b001: ALUResult = leftshift;
            3'b010: ALUResult = {31'b0, LT};
            3'b011: ALUResult = {31'b0, LTU};
            3'b100: ALUResult = (SrcA ^ SrcB);
            3'b101: ALUResult = shifter;
            3'b110: ALUResult = (SrcA | SrcB);
            3'b111: ALUResult = (SrcA & SrcB);	
        endcase
    end

    // The predicate for branch instructions
    reg takeBranch;
    always @(*) begin
        case(funct3)
            3'b000: takeBranch = EQ;
            3'b001: takeBranch = !EQ;
            3'b100: takeBranch = LT;
            3'b101: takeBranch = !LT;
            3'b110: takeBranch = LTU;
            3'b111: takeBranch = !LTU;
            default: takeBranch = 1'b0;
        endcase
    end

    // Address computation
    // An adder used to compute branch address, JAL address and AUIPC.
    // branch->PC+Bimm    AUIPC->PC+Uimm    JAL->PC+Jimm
    wire [31:0] PCplus4  = PC + 4;
    wire [31:0] PCTarget = PC + (isJAL ? Jimm : isAUIPC ? Uimm : Bimm);
    wire [31:0] PCNext = ((isBranch && takeBranch) || isJAL) ? PCTarget :
                                                      isJALR ? {aluPlus[31:1],1'b0} :
                                                               PCplus4;


    // The state machine
    localparam FETCH_INSTR = 0;
    localparam WAIT_INSTR  = 1;
    localparam FETCH_REGS  = 2;
    localparam EXECUTE     = 3;
    localparam LOAD        = 4;
    localparam WAIT_DATA   = 5;
    localparam STORE       = 6;
    reg [2:0] state = FETCH_INSTR;

    wire writeBackEn =
    (state == WAIT_DATA && isLoad) ||
    (state == EXECUTE &&
        (isALUreg || isALUimm || isJALR || isJAL ||
         isAUIPC || isLUI));

    wire [31:0] writeBackData =
        isLoad  ? ReadData :
        isJALR  ? PCplus4 :
        isJAL   ? PCplus4 :
        isAUIPC ? PCTarget :
        isLUI   ? Uimm :
                  ALUResult;

    wire [31:0] LoadStoreAddress =
        rs1 + (isStore ? Simm : Iimm);

    assign Address =
        (state == FETCH_INSTR || state == WAIT_INSTR) ? PC :
                                                      LoadStoreAddress;

    assign MemWrite = (state == STORE);

    assign WriteData = rs2;

    always @(posedge clk)
        if (reset) begin
            PC    <= 0;
            state <= FETCH_INSTR;
        end else begin
            if (writeBackEn) begin
                RegisterBank[rdId_A3] <= writeBackData;
                //$display("r%0d <= %b (%d) (%d)",rdId_A3,writeBackData,writeBackData,$signed(writeBackData));
            end
            case(state)
                FETCH_INSTR: begin
                    state <= WAIT_INSTR;
                end
                WAIT_INSTR: begin
                    instr <= ReadData;
                    state <= FETCH_REGS;
                end
                FETCH_REGS: begin
                    rs1 <= rs1Id_A1 ? RegisterBank[rs1Id_A1] : 32'b0;
                    rs2 <= rs2Id_A2 ? RegisterBank[rs2Id_A2] : 32'b0;
                    state <= EXECUTE;
                end
                EXECUTE: begin
                    if (!isSYSTEM) begin
                        PC <= PCNext;
                    end
                    state <= isLoad  ? LOAD  : 
                             isStore ? STORE : 
                                       FETCH_INSTR;
                end
                LOAD: begin
                    state <= WAIT_DATA;
                end
                WAIT_DATA: begin
                    state <= FETCH_INSTR;
                end
                STORE: begin
                    state <= FETCH_INSTR;
                end
            endcase 
        end
endmodule