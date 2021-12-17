//Se incluye la libreria de la ram de 256kB para un benchmark o test
`include "256ram.v"
//Escala de segundos en nanosegundos/ nanosegundos
`timescale 1 ns/ 1 ns 
//Creamos el cascaron
module ram256_tb;
    //dirreccion de bit 16s
    reg [15:0] addr16;
    //Dato que queremos escribir en la memoria si wrEnable=1
    reg [31:0] dataIn;
    reg wrEnable;
    //Dato que obtenemos por el addr16
    wire [31:0] dataOut;
    //Tiempos para la simulacion
    localparam period = 40;
    //Ciclo del reloj con un periodo de 40s
    reg clk;

    always begin
        clk = 1'b1; #20; // 20s en alto
        clk = 1'b0; #20; // 20s en bajo
    end

    //Conectamos el cascaron con la ram256 para probarla
    ram256 ram256test (
        .clk(clk),
        .addr16(addr16),
        .dataIn(dataIn),
        .wrEnable(wrEnable),
        .dataOut(dataOut)
    );


    initial begin
        $dumpfile("test2.vcd");//Guardamos los datos simulados en test2.vcd
        $dumpvars(0, ram256_tb); // Variables a guardar
        #period; #period; #period; // 60ns
        //Leemos y escribimos para primera ram00
        wrEnable = 0; 
        dataIn = 32'hCAFECAFE;
        addr16 = 16'h0003; // ram00 
        #period; #period; #period; //60s
        wrEnable = 1; 
        #period;#period;  
        wrEnable = 0;
        #period; #period; // 60s


        //Leemos y escribimos para segunda ram01
        wrEnable = 0;
        addr16= 16'h4003;
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


        //Leemos y escribimos para tercera ram10
        wrEnable = 0;
        addr16= 16'h8003 ;
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


         //Leemos y escribimos para tercera ram11
        wrEnable = 0;
        addr16= 16'hC003; 
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


        #period;

        //SEGUNDA RONDA////////////////////////////////////

        //Leemos y escribimos para primera ram00
        dataIn = 32'hBEBEBEBE;
        wrEnable = 0; 
        addr16 = 16'h3; // ram00 
        #period; #period; #period; //60s
        wrEnable = 1; 
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


        //Leemos y escribimos para segunda ram01
        wrEnable = 0;
        addr16= 16'h4003; 
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


        //Leemos y escribimos para tercera ram10
        wrEnable = 0;
        addr16= 16'h8003; 
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s


         //Leemos y escribimos para tercera ram11
        wrEnable = 0;
        addr16= 16'hC003; 
        #period; #period; #period;
        wrEnable = 1;
        #period; #period; 
        wrEnable = 0;
        #period; #period; // 60s

        #period;
        
        $stop;
        $finish;

    end

endmodule



