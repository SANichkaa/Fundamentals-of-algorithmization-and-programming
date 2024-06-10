#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"
#include <cmath>

class BinaryOperation : public Expression
{
public:
  BinaryOperation(Expression* var1, char znak, Expression* var2);
  double evaluate() override;
  ~BinaryOperation() override;
private:
  Expression* var1;
  Expression* var2;
  char znak;
};

#endif // BINARYOPERATION_H
