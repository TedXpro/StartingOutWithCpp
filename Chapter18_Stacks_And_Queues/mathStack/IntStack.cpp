#include "IntStack.h"
#include <iostream>

using namespace std;

IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

IntStack::IntStack(const IntStack &obj)
{
    if (obj.stackSize > 0)
        stackArray = new int[obj.stackSize];
    else
        stackArray = nullptr;

    stackSize = obj.stackSize;

    for (int count = 0; count < stackSize; count++)
        stackArray[count] = obj.stackArray[count];

    top = obj.top;
}

IntStack::~IntStack()
{
    delete[] stackArray;
}

void IntStack::push(int num)
{
    if(isFull())
        cout << "The Stack is full\n";
    else{
        top++;
        stackArray[top] = num;
    }
}

void IntStack::pop(int &num)
{
    if(isEmpty())
        cout << "The Stack is Empty\n";
    else
    {
        num = stackArray[top];
        top--;
    }
}

bool IntStack::isFull() const
{
    bool status;

    if(top == stackSize - 1)
        status = true;
    else
        status = false;
    return status;
}

bool IntStack::isEmpty() const
{
    bool status;

    if(top == -1)
        status = true;
    else
        status = false;
    return status;
}