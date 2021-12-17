//Utilizamos un demux 1x4 con un select de tamaño 2 bits
//Se llamo demux1 el modulo y demux2 el archivo porque se habia creado otro demux que se elimino
module demux1(
    input Input,//wrEnable
    input [1:0] s,//select 
    output reg y1, y2, y3, y4
);

always @(Input) //Cada vez que la entrada (wrEnable) cambie, se actualizara los datos de salida para las rams
    begin
        if (s == 2'b00)
            begin 
            y1 = Input;
            {y2, y3, y4} = 0;//modo lectura
            end
    else if (s == 2'b01) 
        begin
            y2 = Input;
            {y1, y3, y4} = 0;//modo lectura
        end
    else if (s == 2'b10) 
        begin
            y3 = Input;
            {y2, y1, y4} = 0;//modo lectura
        end
    else if (s == 2'b11) 
        begin
            y4 = Input;
            {y2, y3, y1} = 0;//modo lectura
        end
    else // no change 
        y1=y1;
        y2=y2;
        y3=y3;
        y4=y4;
    end

    //Se utilizo para hacer un debug de lo que pasaba dentro del demux
    //initial begin
    //    $monitor("times=%0t y1=0x%0h y2=0x%0h y3=0x%0h y4=0x%0h input=0x%0h s=0x%0b",$time,y1,y2,y3,y4,Input,s);
    //end
    
    
endmodule