//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef INFIX2POSTFIX
#define INFIX2POSTFIX

// labels designating the parentheses characters
const char lParen  = '(', rParen = ')';

class infix2Postfix :public virtual _aritmetic_base{
private:
	string infixExpression;
	stack<expressionSymbol> operatorStack;
	map<string,t_aritmeticExpression> ftokens;

  void make_ftokens(void);
  void outputHigherOrEqual(const expressionSymbol& op);
  bool evaluate_int(int&);
  bool evaluate_float(int&);
  bool evaluate_functions(int &i);
  bool evaluate_var(int &i);
  bool resolveLex(void);

public:
  infix2Postfix();
	infix2Postfix(const string& infixExp);
	void setInfixExp(const string& infixExp);
  map<string,float>& get_VarMap(void);
	bool makepostfix();
};//_____________________________________________________________________________________
#endif
