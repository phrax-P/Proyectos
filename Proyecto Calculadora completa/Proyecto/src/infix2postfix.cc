//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
#include "enum_base.h"
#include "aritmetic_base.h"
#include "expsymbol.h"	// expressionSymbol class
#include "d_except.h"	// for expressionError exception
#include "infix2postfix.h"

//+++++++++++++++++++
// infix2postfix
//+++++++++++++++++++
bool infix2Postfix::evaluate_int(int &i)
{
  bool salida=false;
  enum e_int_state {inicial,espera_ultimo_digito} estado=inicial;
  string valor="";
  while(!salida )
  {
    if (!infixExpression[i]) break;
    char car=infixExpression[i];
    switch(estado)
    {
      case inicial: switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;
                                  estado=espera_ultimo_digito;
                                  i++;
                        break;

                        default: return false;
                    }
                    break;

       case espera_ultimo_digito:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                        break;

                        default: salida=true;
                                 break;

                    }
                    break;
   }
  }
  t_infixExpression.push(token_numero);
  int val=atoi(valor.c_str());
  DataQueue.push(val);
  return true;
}//______________________________________________________________

bool infix2Postfix::evaluate_float(int &i)
{
  bool salida=false,exponente_abierto=false;
  enum e_int_state {inicial,mantiza,decimal,exponente,valor_exponente} estado=inicial;
  string valor="";
  while(!salida )
  {
    if (!infixExpression[i]) break;
    char car=infixExpression[i];
    switch(estado)
    {
      case inicial: switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;
                                  estado=mantiza;
                                  i++;
                        break;

                        default: return false;
                    }
                    break;

       case mantiza:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  break;

                        case '.': estado=decimal;
                                  valor+=car;i++;
                                  break;
                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  valor+=car;i++;
                                  break;

                        default: salida=true;
                                 break;

                    }
                    break;

       case decimal:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  break;

                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  valor+=car;i++;
                                  break;

                        default: salida=true;
                                 break;

                    }
                    break;

       case exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        case '-': valor+=car;i++;
                                  estado=valor_exponente;
                                  break;

                        default: return false;
                                 break;

                    }
                    break;

       case valor_exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        default: if(exponente_abierto) return false;
                                 salida=true;
                                 break;

                    }
                    break;
   }
  }
  t_infixExpression.push(token_numero);
  float val=atof(valor.c_str());
  DataQueue.push(val);
  return true;
}//______________________________________________________________

bool infix2Postfix::evaluate_functions(int &i)
{
  bool salida=false;
  enum e_int_state {inicio_posible_funcion,espera_final_posible_funcion} estado=inicio_posible_funcion;
  string funcion="";
  while(!salida )
  {
    if (!infixExpression[i]) break;
    char car=infixExpression[i];
    switch(estado)
    {
      case inicio_posible_funcion:
          if (!isalpha(car)) return false;
          funcion+=car;i++;
          estado=espera_final_posible_funcion;
          break;

      case espera_final_posible_funcion:
          if (isalpha(car))
          {
            funcion+=car;i++;
          }else  salida=true;
          break;
    }
  }//while
  map<string,t_aritmeticExpression>::iterator result=ftokens.find(funcion);
  if (result==ftokens.end()) return false;
  t_infixExpression.push((*result).second);
  return true;
}//________________________________________________________________

bool infix2Postfix::evaluate_var(int &i)
{
  bool salida=false;
  enum e_int_state {inicio_variable,espera_final_variable} estado=inicio_variable;
  string variable="";
  while(!salida )
  {
    if (!infixExpression[i]) break;
    char car=infixExpression[i];
    switch(estado)
    {
      case inicio_variable:
          if (car != '$') return false;
          variable+=car;i++;
          estado=espera_final_variable;
          break;

      case espera_final_variable:
          if (isalpha(car)||isdigit(car))
          {
            variable+=car;i++;
          }else  salida=true;
          break;
    }
  }//while
  //Localiza o crea una $VAR en variables_float
  //Ingresa un token_variable en la cola de tokens
  //Además ingresa el nombre de la variable detectada en la cola de variables
  Map_variables_float[variable]=0.0;
  t_infixExpression.push(token_variable);
  VariableQueue.push(variable);
  return true;
}//________________________________________________________________

bool infix2Postfix::resolveLex(void)
{
  bool salida=false;
  int i=0;
  while(!t_infixExpression.empty()) t_infixExpression.pop();
  while(!DataQueue.empty()) DataQueue.pop();

  while(!salida)
	{
	  if (i==(int)infixExpression.length()) break;
    if (!infixExpression[i]) break;
		char ch = infixExpression[i];
		switch(ch)
		{
          case '+': t_infixExpression.push(token_mas);break;
          case '-': t_infixExpression.push(token_menos);break;
          case '*': t_infixExpression.push(token_por);break;
          case '/': t_infixExpression.push(token_div);break;
          case '%': t_infixExpression.push(token_resto);break;
          case '^': t_infixExpression.push(token_pot);break;
          case '(': t_infixExpression.push(token_pizq);break;
          case ')': t_infixExpression.push(token_pder);break;
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9': if (evaluate_float(i)) continue;
                    return false;
          case 's':
          case 'c':
          case 't':
          case 'l':
          case 'e': if (evaluate_functions(i)) continue;
                    return false;
          case '$': if (evaluate_var(i)) continue;
          default:  return false;
		}
		i++;
	}
	return true;
}//_______________________________________________________

void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;

	while(!operatorStack.empty() &&
			(op2 = operatorStack.top()) >= op)
	{
		operatorStack.pop();
		t_postfixExpression.push(op2.getOp());
	}
}//_______________________________________________________

void infix2Postfix::make_ftokens(void)
{
  ftokens.insert(pair<string,t_aritmeticExpression>("cos",token_coseno));
  ftokens["sen"]=token_seno;
  ftokens["tan"]=token_tangente;
  ftokens["ln"]=token_ln;
  ftokens["log"]=token_log;
  ftokens["exp"]=token_exp;
  ftokens["cosh"]=token_cosenoh;
  ftokens["senh"]=token_senoh;
}//_______________________________________________________

infix2Postfix::infix2Postfix()
{
  make_ftokens();
}//_______________________________________________________

infix2Postfix::infix2Postfix(const string& infixExp):
		infixExpression(infixExp)
{
  make_ftokens();
}//_______________________________________________________

void infix2Postfix::setInfixExp(const string& infixExp)
{
	infixExpression = infixExp;
  while(!t_postfixExpression.empty())  t_postfixExpression.pop();
	while(!t_infixExpression.empty())    t_infixExpression.pop();
  while(!DataQueue.empty())            DataQueue.pop();
  while(!VariableQueue.empty())        VariableQueue.pop();
  Map_variables_float.clear();
}//_______________________________________________________

bool infix2Postfix::makepostfix()
{
  if (!resolveLex()) return false;
  show_tokenlist("Infix:",t_infixExpression);

  expressionSymbol op;

	int rank = 0;
	t_aritmeticExpression token;

	// process until end of the expression
	while(!t_infixExpression.empty())
	{
		token = t_infixExpression.front();
		t_infixExpression.pop();
		if ((token==token_numero) || (token ==token_variable))
		{
			t_postfixExpression.push(token);
			rank++;
			if (rank > 1)
				throw expressionError("infix2Postfix: Operator expected");
		}
		//  *********  process an operator or '('  **********
		else if (isOperator(token) || (isFunction(token)) ||token == token_pizq)
		{
			if ((token != token_pizq) && (!isFunction(token)) )
					rank--;

			if (rank < 0)
				throw expressionError("infix2Postfix: Operand expected");	else
			{
				op = expressionSymbol(token);
				outputHigherOrEqual(op);
				operatorStack.push(op);
			}
		}
		else if (token == token_pder)
		{
			op = expressionSymbol(token);
			outputHigherOrEqual(op);
			if(operatorStack.empty())
				throw expressionError("infix2Postfix: Missing '('");
			else
				operatorStack.pop(); // get rid of '('
		}
		//  *********  make sure ch is whitespace  **********
		else throw expressionError("infix2Postfix: Invalid input");
	}
	if (rank != 1)
		throw expressionError("infix2Postfix: Operand expected");
	else
	{
 		while (!operatorStack.empty())
		{
			op = operatorStack.top();
			operatorStack.pop();
			if (op.getOp() == token_pizq)
				throw expressionError("infix2Postfix: Missing ')'");
			else
			{
				t_postfixExpression.push(op.getOp());
			}
		}
	}
  show_data();
  show_variables();
	return true;
}//_______________________________________________________

map<string,float>& infix2Postfix::get_VarMap(void)
{
  return Map_variables_float;
}//_______________________________________________________
