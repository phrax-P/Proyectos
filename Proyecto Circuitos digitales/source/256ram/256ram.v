`include "ram.v"
`include "mux.v"
`include "demux2.v"
module ram256
#(parameter BUS_WIDTH = 16)(
    // Inputs
    input clk,
    input [BUS_WIDTH-1:0] addr16,
    input [31:0] dataIn,
    input wrEnable, // 0: Read, 1: Write
    // Outputs
    output [31:0] dataOut
);


wire [31:0] dataOutA, dataOutB, dataOutC, dataOutD;//Cables para conectar salidas de las rams con el Mux
wire wireA, wireB, wireC, wireD;//Cables para conectar la salida del segundo Dmux con las rams
wire [1:0] s = addr16[15:14];//Valor de s1 y s2 
//Instancias 
//Demux_wrEnable
demux1 Dmux_wr(.Input(wrEnable), .s(s), .y1(wireA), .y2(wireB), .y3(wireC), .y4(wireD));
//RAMS 64kB
ram ramA (.clk(clk), .addr(addr16[13:0]), .dataIn(dataIn), .wrEnable(wireA), .dataOut(dataOutA));
ram ramB (.clk(clk), .addr(addr16[13:0]), .dataIn(dataIn), .wrEnable(wireB), .dataOut(dataOutB));
ram ramC (.clk(clk), .addr(addr16[13:0]), .dataIn(dataIn), .wrEnable(wireC), .dataOut(dataOutC));
ram ramD (.clk(clk), .addr(addr16[13:0]), .dataIn(dataIn), .wrEnable(wireD), .dataOut(dataOutD));
//Mux
mux Mux(.s(s), .i0(dataOutA), .i1(dataOutB), .i2(dataOutC), .i3(dataOutD), .y(dataOut));


endmodule