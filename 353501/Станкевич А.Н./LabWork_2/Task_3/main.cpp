#include <iostream>
#include <cstring>
#include "BinaryOperation.h"
#include "Number.h"

bool check_equals(Expression const* left, Expression const* right)
{
    return (*((size_t*)left) == *((size_t*)right));
}

int main()
{
    Number* n2 = new Number(5);
    Number* n1 = new Number(5.1);


    BinaryOperation* a  = new BinaryOperation(n1, '*', n2);
    std::cout<<a->evaluate()<<"\n";
    std::cout << (check_equals(n1, n2) ? "Yes\n" : "No\n");
    std::cout << (check_equals(n1, a) ? "Yes\n" : "No\n");
    return 0;
}
