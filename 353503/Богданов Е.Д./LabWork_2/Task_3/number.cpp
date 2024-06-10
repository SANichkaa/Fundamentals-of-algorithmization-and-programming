#include "number.h"

Number::Number(double var) : number(var) {}

double Number::evaluate()
{
  return number;
}

Number::~Number() = default;
