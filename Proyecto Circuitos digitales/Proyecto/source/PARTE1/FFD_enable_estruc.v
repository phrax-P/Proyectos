//FF tipo D con enable activo en bajo
module DFF_enable_negado(
    input wire clk, en, 
    input d, 
    output wire q,q_n //Q y Q NEGADA
);
//Se baso en el diagrama para crear las conexiones entre cada compuerta 

wire not1_out, not2_out, nand1_out, nand2_out, nand3_out, nand4_out;
wire and1_out, and2_out, or1_out;

wire not3_out, not4_out, nand11_out, nand33_out;

not NOT3(not3_out, clk); //clock negado
//Enable
not NOT1(not1_out, en);
and AND1(and1_out, d, not1_out);
and AND2(and2_out, en, q);
or OR1(or1_out, and1_out, and2_out);
//Primer latch
not NOT2(not2_out, or1_out);
nand NAND1(nand1_out, or1_out, not3_out);
nand NAND3(nand3_out, not2_out, not3_out);
nand NAND2(nand2_out, nand1_out, nand4_out);
nand NAND4(nand4_out, nand3_out, nand2_out);
//Segundo latch
not NOT44(not4_out, nand2_out);
nand NAND11(nand11_out, nand2_out, clk);
nand NAND33(nand33_out, not4_out, clk);
nand NAND22(q, nand11_out, q_n);
nand NAND44(q_n, nand33_out, q);


//Fin

endmodule

