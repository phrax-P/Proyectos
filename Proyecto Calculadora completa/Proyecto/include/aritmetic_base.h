//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ARITMETIC_BASE_INCLUDED
#define ARITMETIC_BASE_INCLUDED

class _aritmetic_base :public _enum_base{
protected:
  queue<t_aritmeticExpression> t_infixExpression;
  queue<t_aritmeticExpression> t_postfixExpression;
  queue<string>                VariableQueue;
  queue<float>                 DataQueue;
 	map<string,float>            Map_variables_float;

  inline void show_tokenlist(char *msg,queue<t_aritmeticExpression> copy)
  {
    //queue<t_aritmeticExpression> copy(t_infixExpression);
    int length=copy.size();
    cout << msg << " ";
    for (int i=0;i< length;i++)
    {
      cout << "<TOKEN:" << copy.front() << ">";
      copy.pop();
    }
    cout << endl;
  }//_______________________________________________________

  inline void show_data(void)
  {
    //queue<t_aritmeticExpression> copy(t_infixExpression);
    queue<float> copy(DataQueue);
    int length=copy.size();
    cout << "DATA QUEUE ";
    for (int i=0;i< length;i++)
    {
      cout << "<DATA:" << copy.front() << ">";
      copy.pop();
    }
    cout << endl;
  }//_______________________________________________________

  inline void show_variables(void)
  {
    //queue<t_aritmeticExpression> copy(t_infixExpression);
    queue<string> copy(VariableQueue);
    int length=copy.size();
    cout << "VARIABLE QUEUE ";
    for (int i=0;i< length;i++)
    {
      cout << "<VARIABLE:" << copy.front() << ">";
      copy.pop();
    }
    cout << endl;
  }//_______________________________________________________

  inline bool isOperator(t_aritmeticExpression token) const
  {
    switch(token)
    {
      case token_mas:
      case token_menos:
      case token_por:
      case token_div:
      case token_pot: return true;
      default:return false;
    }
  }//_______________________________________________________

  inline bool isFunction(t_aritmeticExpression token) const
  {
    switch(token)
    {
      case token_coseno:
      case token_seno:
      case token_cosenoh:
      case token_senoh:
      case token_tangente:
      case token_ln:
      case token_log:
      case token_exp:return true;
      default:return false;
    }
  }
};//______________________________________________________


#endif // ARITMETIC_BASE_INCLUDED
