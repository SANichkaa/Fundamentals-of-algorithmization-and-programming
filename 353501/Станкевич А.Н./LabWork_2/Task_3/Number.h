#ifndef NUMBER_H
#define NUMBER_H


#include "Expression.h"

class Number : public Expression
{
public:
        double evaluate() const { return value; }
    Number(double value) : value(value) {}

private:
    double value;
};

#endif // NUMBER_H
