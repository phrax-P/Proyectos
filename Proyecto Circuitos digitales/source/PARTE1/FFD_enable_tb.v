`include "FFD_enable.v"
`include "FFD_enable_estruc.v"
`timescale 1ns/1ns

module FFD_enable_tb;
    reg clk, en;
    reg d;
    wire q,q_n;

always begin
        clk = 1'b1; #1; // 20s en alto
        clk = 1'b0; #1; // 20s en bajo
end
always begin
        en = 1'b1; #3; // 20s en alto
        en = 1'b0; #3; // 20s en bajo
end

//Creamos el Flip Flop y lo conectamos con el cascaron
BasicDFF_enable FFD_conduc (.clk(clk), 
    .en(en), .d(d), .q(q));

initial begin
    $dumpfile("prueba1.vcd");//Guardamos los datos simulados en prueba.vcd
    $dumpvars(1, FFD_enable_tb);
    d=0; #9 d=1; #1 d=0; #1 d=1; #2 d=0; #1 d=1; #12 d=0;
        #1 d=1; #2 d=0; #1 d=1; #1 d=0; #1 d=1; #1 d=0; # 7 d=1;
        #8
    $stop;
    $finish;
end

endmodule