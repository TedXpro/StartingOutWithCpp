#include <iostream>

using namespace std;

class IntQueue
{
private:
    struct QueueNode
    {
        int value;
        QueueNode *next;
    };
    QueueNode *top;
    int queueSize;

public:
    IntQueue()
    {
        top = nullptr;
        queueSize = 0;
    }
    ~IntQueue()
    {
    }

    class EmptyQueue
    {
    };

    void enqueue(int);
    int dequeue();
    int peak();
    int size();
};

int menu();

int main()
{
    int choice = menu();

    if (choice == 5)
    {
        cout << "thank you for using!\n";
        return 0;
    }

    IntQueue numberQueue;
    do
    {
        if (choice == 1)
        {
            cout << "Enter number: ";
            cin >> choice;
            numberQueue.enqueue(choice);
        }
        else if (choice == 2)
        {
            try
            {
                choice = numberQueue.dequeue();
                cout << choice << " has been removed from queue.\n\n";
            }
            catch (IntQueue::EmptyQueue)
            {
                cout << "The Stack is EMPTY!\n\n";
            }
        }
        else if (choice == 3)
        {
            try
            {
                choice = numberQueue.peak();
                cout << "The element at the front of the queue is " << choice << endl
                     << endl;
            }
            catch (IntQueue::EmptyQueue)
            {
                cout << "The Stack is EMPTY!!\n\n";
            }
        }
        else
        {
            choice = numberQueue.size();
            cout << "The size of the queue is " << choice << endl
                 << endl;
        }

        choice = menu();
    } while (choice != 5);

    cout << "Thank you for using!!\n";
    return 0;
}

int menu()
{
    int choice;
    cout << "Welcome to Queue's!\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peak in queue\n";
    cout << "4. Size of queue\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice >= 6 || choice < 1)
    {
        cout << "Enter between 1- 5: ";
        cin >> choice;
    }

    return choice;
}

void IntQueue::enqueue(int number)
{
    QueueNode *newNode = new QueueNode;

    newNode->value = number;
    newNode->next = nullptr;

    if (top == nullptr)
    {
        top = newNode;
        queueSize++;
    }
    else
    {
        QueueNode *nodePtr = top;

        while (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
        queueSize++;
    }

    cout << number << " has been added to the queue.\n\n";
}

int IntQueue::dequeue()
{
    int number;
    if (top == nullptr)
        throw EmptyQueue();
    else
    {
        QueueNode *nodePtr = top->next;
        number = top->value;
        delete top;
        top = nodePtr;
        queueSize--;
    }

    return number;
}

int IntQueue::peak()
{
    if (top == nullptr)
        throw EmptyQueue();
    return top->value;
}

int IntQueue::size()
{
    return queueSize;
}
