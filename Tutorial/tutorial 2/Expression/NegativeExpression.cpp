#include <iostream>
#include "NegativeExpression.hpp"
#include "Expression.hpp"

using namespace std;

NegativeExpression :: NegativeExpression(Expression* x):UnaryExpression(x), num(x){}
int NegativeExpression :: solve(){
    cout<< (-1)*(num->solve()) << endl;
    return (-1)*(num->solve());
}