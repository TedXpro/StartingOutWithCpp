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

int main()
{
    IntQueue numberQueue;
    numberQueue.enqueue(10);
    numberQueue.enqueue(20);
    numberQueue.enqueue(30);
    numberQueue.enqueue(40);
    numberQueue.enqueue(50);
    numberQueue.enqueue(60);

    int number  = numberQueue.peak();
    cout << "front of queue " << number << endl;
    number = numberQueue.size();
    cout << "the queue has " << number << " elements\n";

    number = numberQueue.dequeue();
    cout << number << " has been removed from front of queue\n";
    number = numberQueue.dequeue();
    cout << number << " has been removed from front of queue\n";

    number = numberQueue.peak();
    cout << "front of queue " << number << endl;
    number = numberQueue.size();
    cout << "the queue has " << number << " elements\n";
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

    cout << number << " has been added to the queue.\n";
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
    return top->value;
}

int IntQueue::size()
{
    return queueSize;
}
