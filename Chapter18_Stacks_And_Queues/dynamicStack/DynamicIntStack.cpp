#include <iostream>

using namespace std;

template <class T>
class DynamicIntStack
{
private:
    struct StackNode
    {
        T value;
        StackNode *next;
    };
    StackNode *top;

public:
    DynamicIntStack()
    {
        top = nullptr;
        size = 0;
    }

    ~DynamicIntStack();

    void push(T);
    void pop(T &);
    bool isEmpty();
    void size() const;
};

int main()
{
    DynamicIntStack<double> dynStack;

    cout << "Pushing elemtents into the stack.\n";
    dynStack.push(10.0);
    dynStack.push(100.00);
    dynStack.push(1000.000);
    dynStack.push(10000.0000);
    dynStack.push(100000.0000);
    dynStack.push(11.1);
    dynStack.push(111.11);
    dynStack.push(1111.115);
    dynStack.push(11111.1111);
    dynStack.push(111111.1111);

    double num;
    cout << "Poping elements into the stack\n";
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    cout << num << endl;
    dynStack.pop(num);
    // cout << num << endl;
}

template <class T>
DynamicIntStack<T>::~DynamicIntStack()
{
    StackNode *nextNode = nullptr, *nodePtr = nullptr;

    nodePtr = top;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <class T>
void DynamicIntStack<T>::pop(T &number)
{
    StackNode *temp = nullptr;

    if (isEmpty())
    {
        cout << "The Stack is empty.\n";
    }
    else
    {
        number = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

template <class T>
void DynamicIntStack<T>::push(T number)
{
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = number;
    newNode->next = top;
    top = newNode;
}

template <class T>
bool DynamicIntStack<T>::isEmpty()
{
    bool status;
    if (top == nullptr)
        status = true;
    else
        status = false;

    return status;
}