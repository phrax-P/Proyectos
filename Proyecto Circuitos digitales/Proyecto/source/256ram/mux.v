//Utilizamos un mux de 4x1 con un selector de 2 bits, salidas y entradas de 32 bits
module mux(
    input  [1:0]s,
    input  [31:0] i0, i1, i2, i3, 
    output reg [31:0] y
);
wire [1:0] a = (s==2'b00);
always @(*)
    begin
        if (s == 2'b00)y = i0;
    else if (s == 2'b01) y = i1;
    else if (s == 2'b10) y = i2;
    else if (s == 2'b11) y = i3;
    else y = y; // no change
    
    
   // $monitor("times=%0t y=0%0h s=0x%0b, i0=0x%0h LOG=0x%0b",$time,y,s,i0,a);
    
    end
endmodule
