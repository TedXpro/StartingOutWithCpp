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

    void enqueue(int);
    int dequeue();
    int peak();
    int size();
};

void IntQueue::enqueue(int number)
{
    QueueNode *newNode = new QueueNode;

    newNode->value = number;
    newNode->next = nullptr;

    if(top == nullptr)
        top = newNode;
    else
    {
        QueueNode *nodePtr = top;

        while(nodePtr->next != nullptr)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

int IntQueue::dequeue()
{
    
}