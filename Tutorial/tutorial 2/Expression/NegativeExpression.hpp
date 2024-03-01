#ifndef _NEGATIVEEXPRESSION_HPP_
#define _NEGATIVEEXPRESSION_HPP_

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression{
    public:
        NegativeExpression(Expression*);
        int solve();
    private:
        Expression* num;
};
#endif