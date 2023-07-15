#include <iostream>
#include "IntStack.h"

using namespace std;

class MathStack : public IntStack
{
public:
    MathStack(int n) : IntStack(n) {}

    void add();
    void sub();
};


int main()
{
    MathStack mStack(4);

    cout << "Pushing numbers to the stack.\n";
    mStack.push(5);
    mStack.push(6);
    mStack.push(8);
    mStack.push(9);
    mStack.push(9);
    mStack.push(9);

    mStack.add();
    int sum;
    mStack.pop(sum);
    cout << "The sum of the two numbers is " << sum << endl;

    mStack.sub();
    mStack.pop(sum);
    cout << "The difference of the two numbers is " << sum << endl;
}

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