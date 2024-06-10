#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
  explicit Number(double var);
  double evaluate() override;
  ~Number() override;
private:
  double number;
};

#endif // NUMBER_H
