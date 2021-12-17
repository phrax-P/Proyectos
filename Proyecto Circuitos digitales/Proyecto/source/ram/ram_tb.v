`include "ram.v"
`timescale 1 ns/1 ns

module ram_tb;
    reg [7:0] addr;
    reg [31:0] dataIn;
    reg wrEnable;
    wire [31:0] dataOut;
    localparam period = 20; //periodo de 20s


    reg clk;
    //clock de 20s alto y bajo
    always begin
        clk = 1'b1; #20;
        clk = 1'b0; #20;
    end
    //conectamos con el cascaron los wires
    ram UUT (
        .clk(clk),
        .addr(addr),
        .dataIn(dataIn),
        .wrEnable(wrEnable),
        .dataOut(dataOut)
    );

initial begin
    $dumpfile("test.vcd");
    $dumpvars(1, ram_tb);
    #period; #period; #period;
    wrEnable = 1;
    dataIn = 32'hC0FFEE00;
    addr = 7'h0;
    #period; #period; #period;
    wrEnable = 0;
    addr = 7'h0;
    #period; #period; #period;
    addr= 7'h1;
    #period; #period; #period;
    addr= 7'h78;
    #period; #period; #period;
    $stop;
    $finish;

end

endmodule