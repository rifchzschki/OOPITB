#include "SubstractExpression.hpp"
#include "Expression.hpp"
#include <iostream>

using namespace std;

SubstractExpression :: SubstractExpression(Expression*A, Expression*B): BinaryExpression(A,B), left(A), right(B){}
int SubstractExpression :: solve(){
    cout << left->solve() - right->solve() << endl;
    return left->solve() - right->solve();
}