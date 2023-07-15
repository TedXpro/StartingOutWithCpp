#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
    int number; // to hold values popped of from the stack;

    IntStack stack(5);

    stack.push(10);
    stack.push(5);
    stack.push(2);
    stack.push(1);
    stack.push(0);
    stack.push(100);

    cout << "One element from stack one popped\n";
    stack.pop(number);
    cout << number << endl;

    cout << "Creating a copy of stack one\n";
    IntStack secondStack(stack);

    cout << "Pushing elements to stack two\n";
    secondStack.push(100);

    cout << "Popping elements from stack two\n";
    secondStack.pop(number);
    cout << number << endl;
    secondStack.pop(number);
    cout << number << endl;
    secondStack.pop(number);
    cout << number << endl;
    secondStack.pop(number);
    cout << number << endl;
    secondStack.pop(number);
    cout << number << endl;
    secondStack.pop(number);

    cout << "Poping elements from stack one\n";
    stack.pop(number);
    cout << number << endl;
    stack.pop(number);
    cout << number << endl;
    stack.pop(number);
    cout << number << endl;
    stack.pop(number);
    cout << number << endl;
    stack.pop(number);
}