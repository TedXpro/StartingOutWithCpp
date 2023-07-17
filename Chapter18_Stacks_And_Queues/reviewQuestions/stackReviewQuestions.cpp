#include <iostream>

using namespace std;

class IntStack
{
private:
    struct StackNode
    {
        int value;
        StackNode *next;
    };
    StackNode *top;

    int stackSize;

public:
    class EmptyStack
    {
    };

    IntStack()
    {
        top = nullptr;
        stackSize = 0;
    }

    ~IntStack()
    {
        while(top != nullptr)
            int number = pop();
    }

    int pop();
    void push(int);
    int peak();
    int size();
};

int menu();

int main()
{
    int choice = menu();

    if(choice == 5)
    {
        cout << "Than you for using!\n";
        return 0;
    }

    IntStack userStack;
    do 
    {
        if(choice == 1)
        {
            cout << "Enter number: ";
            cin >> choice;
            userStack.push(choice);
        }
        else if(choice == 2)
        {
            try
            {
                cout << userStack.pop() << " has been poped from stack.\n";
            }
            catch(IntStack::EmptyStack)
            {
                cout << "The stack is empty\n";
            }
        }
        else if(choice == 3)
            cout << "The element at the top of stack is " << userStack.peak() << endl;
        else if(choice == 4)
            cout << "There is/are " << userStack.size() << " element(s) in the stack.\n";

        choice = menu();
    } while (choice != 5);

    cout << "Thank you for using.\n";
}

int menu()
{
    int choice;
    cout << "Welcome to Stacks!\n";
    cout << "1. Push to stack\n";
    cout << "2. Pop from stack\n";
    cout << "3. Peak in stack\n";
    cout << "4. Size of stack\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while(choice >=6 || choice < 1)
    {
        cout << "Enter between 1- 5: ";
        cin >> choice;
    }

    return choice;
}

int IntStack::pop()
{
    int number;

    if (top == nullptr)
    {
        throw EmptyStack();
    }
    else
    {
        StackNode *tempNode = nullptr;
        number = top->value;

        tempNode = top->next;
        delete top;
        stackSize--;
        top = tempNode;
    }

    return number;
}

void IntStack::push(int number)
{
    StackNode *newNode = new StackNode;
    newNode->value = number;

    if (top == nullptr)
    {
        top = newNode;
        newNode->next = nullptr;
        stackSize++;
    }
    else
    {
        newNode->next = top;
        top = newNode;
        stackSize++;
    }
    cout << number << " has successfully been added to stack.\n";
}

int IntStack::peak()
{
    return top->value;
}

int IntStack::size()
{
    return stackSize;
}