#ifndef _SUBSTRACTEXPRESSION_HPP_
#define _SUBSTRACTEXPRESSION_HPP_

#include "Expression.hpp"
class SubstractExpression: public BinaryExpression
{
private:
    Expression* left;
    Expression* right;
public:
    SubstractExpression(Expression*, Expression*);
    int solve();
};




#endif