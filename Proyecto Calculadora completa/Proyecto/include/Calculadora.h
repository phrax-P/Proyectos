#ifndef CALCULADORA_H
#define CALCULADORA_H
#include "Boton.h"
#include <list>
class Calculadora: public Fl_Window
{
private:
    Fl_Output* Data;
    int dim_x,dim_y;
    int height;
public:
    Calculadora(int , int );
};

#endif // CALCULADORA_H
