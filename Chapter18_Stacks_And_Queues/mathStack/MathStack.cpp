#include "MathStack.h"

void MathStack::add()
{
    int number1, number2;
    pop(number1);
    pop(number2);

    push(number1 + number2);
}

void MathStack::sub()
{
    int number1, number2;

    pop(number1);
    pop(number2);

    push(number1 - number2);
}