#include <iostream>

using namespace std;

class StackLoad
{
private:
    int stackSize; // to hold the size of the array;
    int top;       // to hold the top element of the stack;
    int *stackPtr; // pointer to hold the array;

public:
    StackLoad(int size)
    {
        stackSize = size;
        top = -1;
        stackPtr = new int[size];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (top == stackSize - 1)
            return true;
        return false;
    }

    void push(int value)
    {
        // precondition  check if stack is full??
        if (isFull())
        {
            cout << "Stack is Full\n";
            return;
        }
        else
        {
            top++;
            stackPtr[top] = value; // the given value is added.
        }
    }

    void pop()
    {
        // precondition is to check if stack is empty.
        if (isEmpty())
        {
            cout << "Stack is empty. There is nothing to pop.\n";
            return;
        }
        else
        {
            top--;
        }
    }

    void topElement()
    { // display only the top element.
        // precondition is to check if stack is emptty.
        if (isEmpty())
        {
            cout << "The stack is empty, there is no Top element.\n";
            return;
        }
        else
        {
            cout << "The Top element of the stack is " << stackPtr[top] << endl;
        }
    }
};

int main()
{
    // ClassName ObjectName   (calling the constructor)
    /*  |            |               |*/
    StackLoad afoStack(10); // object is being initialized.
    StackLoad yoStack(5);   // another object is being initialized.

    cout << "Afo's Stack";
    cout << "Pushing 1\n";
    afoStack.push(1);
    cout << "Pushing 10\n";
    afoStack.push(10);
    cout << "Pushing 100\n";
    afoStack.push(100);
    cout << "Pushing 11\n";
    afoStack.push(11);
    cout << "Pushing 12\n";
    afoStack.push(12);
    cout << "Pushing 13\n";
    afoStack.push(13);
    cout << "Pushing 14\n";
    afoStack.push(14);
    cout << "Pushing 15\n";
    afoStack.push(15);
    cout << "Pushing 19\n";
    afoStack.push(19);
    cout << "Pushing 21\n";
    afoStack.push(21);
    cout << "Pushing 31\n";
    afoStack.push(31);

    afoStack.topElement();

    cout << "Yo's Stack\n";
    cout << "Pushing -1\n";
    yoStack.push(-1);
    cout << "Pushing -2\n";
    yoStack.push(-2);
    cout << "Pushing -3\n";
    yoStack.push(-3);
    cout << "Pushing -4\n";
    yoStack.push(-4);
    cout << "Pushing -5\n";
    yoStack.push(-5);
    cout << "Yohannes Stack\n";
    cout << "Pushing -6\n";
    yoStack.push(-6);
    yoStack.topElement();

    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.topElement();

    // afoStack.push(1000000);
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.pop();
    // afoStack.push(1000);
    // afoStack.topElement();
    // afoStack.pop();
    // afoStack.pop();
}