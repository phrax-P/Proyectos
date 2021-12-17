#ifndef BOTON_H
#define BOTON_H
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <stdio.h>
#include <FL/Fl_Output.H>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#include "enum_base.h"
#include "aritmetic_base.h"
#include "expsymbol.h"
#include "infix2postfix.h"
#include "postfixEval.h"
#include "aritmetic_expression_eval.h"
#include "d_except.h"
#include <sstream> //Biblioteca para convertir float->string
class Boton: public Fl_Button
{
private:
    Fl_Output* out;
    char const* op = "";
    static void agregar(Fl_Widget*,void*);
    static void calc(Fl_Widget*,void*);
    static void borrar(Fl_Widget*,void*);
    static void borrar_todo(Fl_Widget*,void*);
public:
    Boton(int x,int y, int width, int height,char const* c,Fl_Output* display,int i =0);
};

#endif // BOTON_H
