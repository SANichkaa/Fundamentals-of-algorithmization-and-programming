#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *var1, char znak, Expression *var2)
    : var1(var1), var2(var2), znak(znak) {}

double BinaryOperation::evaluate() {
  if (znak == '+') {
    return var1->evaluate() + var2->evaluate();
  }
  if (znak == '-') {
    return var1->evaluate() - var2->evaluate();
  }
  if (znak == '*') {
    return var1->evaluate() * var2->evaluate();
  }
  if (znak == '/') {
    return var1->evaluate() / var2->evaluate();
  }
  if (znak == '%') {
    return fmod(var1->evaluate(), var2->evaluate());
  }
  return __DBL_MIN__;
}

BinaryOperation::~BinaryOperation() {
  delete var1;
  delete var2;
}
