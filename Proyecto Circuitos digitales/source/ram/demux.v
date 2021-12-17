module demux(
    input  [13:0] Input,
    input [1:0] s,
    output reg [13:0] y1, y2, y3, y4
);

always @(*) 
    begin
        if (s == 2'b00)
            begin 
            y1 = Input;
             
        end
    else if (s == 2'b01) 
        begin
            y2 = Input;
            
           
        end
    else if (s == 2'b10) 
        begin
            y3 = Input;
            
        end
    else if (s == 2'b11) 
        begin
            y4 = Input;
        end
    else // no change 
        y1=y1;
        y2=y2;
        y3=y3;
        y4=y4;
    end

    //initial begin
    //    $monitor("times=%0t y1=0x%0h y2=0x%0h y3=0x%0h y4=0x%0h input=0x%0h s=0x%0b",$time,y1,y2,y3,y4,Input,s);
    //end
    
    
endmodule