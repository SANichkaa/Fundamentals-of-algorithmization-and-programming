#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "Expression.h"

class BinaryOperation : public Expression {
private:
        Expression *rightOperand;
    char op;
    Expression *leftOperand;

public:
    BinaryOperation(Expression *left, char operation, Expression *right);
    virtual double evaluate() const override;
    virtual ~BinaryOperation();
};

#endif // BINARYOPERATION_H
