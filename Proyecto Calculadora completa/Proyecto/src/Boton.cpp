#include "Boton.h"
using namespace std;
static int estado = 0;
Boton::Boton(int x,int y, int width, int height,char const* c,Fl_Output* display,int i):Fl_Button(x,y,width,height,c)
{
    out = display;
    op = c;
    labelsize(25);
    switch(i)
    {
    case 1:
        callback(calc,(void*)out);
        break;
    case 2:
        callback(borrar,(void*)out);
        break;
    case 3:
        callback(borrar_todo,(void*)out);
        break;
    case 4:
        color(FL_WHITE);
        callback(agregar,(void*)out);
        break;
    default:
        callback(agregar,(void*)out);
    };
}
void Boton::agregar(Fl_Widget* w, void* c)
{
    Fl_Button* B = (Fl_Button*)w;
    Fl_Output* D = (Fl_Output*)c;
    if(estado==1) D->value("");
    estado =0;
    D->textcolor(FL_BLACK);
    cout << B->label() << endl;
    char const* e;
    string a = B->label();
    string b = D->value()+a;
    e = b.c_str();
    D->value(e);
}
void Boton::calc(Fl_Widget* w, void* c)
{
    Fl_Button* B = (Fl_Button*)w;
    Fl_Output* D = (Fl_Output*)c;
    if(estado==1)
    {
        D->value("");
        estado = 0;
        D->textcolor(FL_BLACK);
    }
    else if (estado==0)
    {
        _aritmetic_expression_eval expression;
        string infixExp = D->value();
        string sust_default = "(0-1)*";
        string sust_default2 = "(0+1)*";
        int tam = infixExp.size();
        for(int i=0;i<tam;i++)
        {
            if(i==0 & infixExp[i]=='+') infixExp.replace(i,1,sust_default2);
            else if(infixExp[i]=='-')
            {
                cout << "Se detecto un numero negativo"<< endl;
                if (i==0)
                {
                    infixExp.replace(i,1,sust_default);
                    i+=sust_default.size();
                    tam+=i-1;
                }
                else if (i!=0 & (infixExp[i-1]=='(' | infixExp[i+1]=='t' | infixExp[i+1]=='e' |infixExp[i+1]=='c'|infixExp[i+1]=='s'|infixExp[i+1]=='l'|infixExp[i-1]=='*'|infixExp[i-1]== '/'|infixExp[i-1]=='^'))
                {
                    if (infixExp[i-1]!='('& infixExp[i-1]!='*'& infixExp[i-1]!='/'&infixExp[i-1]!='^')
                    {
                        infixExp.replace(i,1,"+" + sust_default);
                        i+=sust_default.size()+1;
                        tam+=i-2;
                    }
                    else
                    {
                        infixExp.replace(i,1,sust_default);
                        i+=sust_default.size();
                        tam+=i-1;
                    }
                }
                cout << "Expresion infix modificado "<< infixExp << endl;
            }
        }
        try
        {
            // convert to postfix
            expression.setInfixExp(infixExp);
            if (!expression.makepostfix())
            throw expressionError("infix2Postfix: Invalid expression");
            float resultado = expression.evaluate();
            cout << "Value of the expression = " << resultado << endl << endl;
            ostringstream ss;
            ss << resultado;
            D->value(ss.str().c_str());
        }
        // catch an exception and output the error
        catch (const expressionError& ee)
        {
            cout << ee.what() << endl << endl;
            D->value(ee.what().c_str());
            D->textcolor(FL_RED);
            estado  = 1;
        }
    }
}
void Boton::borrar(Fl_Widget* w, void* c)
{
    Fl_Button* B = (Fl_Button*)w;
    Fl_Output* D = (Fl_Output*)c;
    D->textcolor(FL_BLACK);
    cout << B->label() << endl;
    char const* e;
    string a = D->value();
    if (a=="") return;
    string b ="";
    a.replace(a.size()-1,1,b);
    e = a.c_str();
    D->value(e);
}
void Boton::borrar_todo(Fl_Widget* w, void* c)
{
    Fl_Button* B = (Fl_Button*)w;
    Fl_Output* D = (Fl_Output*)c;
    D->textcolor(FL_BLACK);
    cout << B->label() << endl;
    char const* e= "";
    D->value(e);

}
