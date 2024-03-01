#ifndef _ADDEXPRESSION_HPP_
#define _ADDEXPRESSION_HPP_

#include "Expression.hpp"


class AddExpression : public BinaryExpression{
    public:
        AddExpression(Expression*, Expression*);
        int solve();
    private:
        Expression* left;
        Expression* right;

};

#endif