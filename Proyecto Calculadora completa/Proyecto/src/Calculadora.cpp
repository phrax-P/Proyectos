#include "Calculadora.h"
void crear_boton(int ancho, int largo,int fila,float height, int column, std::list<char const*>::iterator& ite,Fl_Output* Display)
{
    std::list<char const*> numeros = {"0","1","2","3","4","5","6","7","8","9"};
    bool num = false;
    std::list<char const*>::iterator first,last;
    first = numeros.begin();
    last = numeros.end();
    while (first!=last)
    {
        if(*first==*ite) num = true;
        first++;
    }
    if(*ite == "C") new Boton(1+fila*ancho,height/1.2-column*largo,ancho,largo,*ite,Display,3);
    else if(*ite == "DEL") new Boton(1+fila*ancho,height/1.2-column*largo,ancho,largo,*ite,Display,2);
    else if (*ite =="=") new Boton(1+fila*ancho,height/1.2-column*largo,ancho,largo,*ite,Display,1);
    else if(num) new Boton(1+fila*ancho,height/1.2-column*largo,ancho,largo,*ite,Display,4);
    else new Boton(1+fila*ancho,height/1.2-column*largo,ancho,largo,*ite,Display);
    ite++;
}
Calculadora::Calculadora(int width, int height_):Fl_Window(width, height_, ""),height(height_)
{
    label("Calculadora");
    Fl_Output* Data = new Fl_Output(20,20,360,70);
    Data->textsize(25);
    Data->value("");
    std::list<char const*>  simb = {"0",".","(",")","=","1","2","3","+","-","4","5","6","*","/","7","8","9","C","DEL","sen","cos","tan","^","log","exp","ln"};
    std::list<char const*>::iterator first = simb.begin();
    dim_x = 80;
    dim_y =60;
    int n=0,m=0;
    for (int i=0;i<simb.size();i++)
    {
        crear_boton(dim_x,dim_y,n,height,m,first,Data);
        n++;
        if (n>4) n=0,m++;
    }
    show();
}

