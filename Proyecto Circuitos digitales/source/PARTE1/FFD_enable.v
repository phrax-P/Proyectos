module BasicDFF_enable(
    input wire clk, en, 
    input d, 
    output reg q //No se ocupa q negada pero si se requiere solo lo agregamos y sera ~q
);
always @(posedge clk) //Cada flanco creciente activarse
    begin
        if (en == 0) q <= d;//Si en esta en bajo, se activa el flip flop
        else q=q; //De lo contrario no cambios
    end
endmodule


