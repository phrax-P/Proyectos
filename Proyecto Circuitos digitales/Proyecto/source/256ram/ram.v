module ram//memoria ram de 14 bits
#(parameter BUS_WIDTH = 14)(
    // Inputs
    input clk,
    input [BUS_WIDTH-1:0] addr,
    input [31:0] dataIn,
    input wrEnable, // 0: Read, 1: Write
    // Outputs
    output reg [31:0] dataOut
);
reg [31:0] memory [0 : 2**BUS_WIDTH- 1];

always @(posedge clk) begin
    if (wrEnable == 1'b1) memory[addr] = dataIn;
    else if (wrEnable == 1'b0) dataOut = memory[addr];
    else dataOut <= 32'bx;

end
    

endmodule