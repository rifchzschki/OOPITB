#include <iostream>
#include "AddExpression.hpp"
#include "Expression.hpp"

using namespace std;

AddExpression :: AddExpression(Expression* A, Expression* B): BinaryExpression(A, B), left(A), right(B){}

int AddExpression :: solve(){
    cout << left->solve()+right->solve() <<endl;
    return left->solve()+right->solve();
}