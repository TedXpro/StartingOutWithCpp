#include <iostream>

using namespace std;

template <class T>
class DynamicQueue
{
private:
    struct QueueNode
    {
        T value;
        QueueNode *next;
    };

    QueueNode *front;
    QueueNode *rear;

    int numItems;

public:
    DynamicQueue();

    ~DynamicQueue();

    void enqueue(T);
    void dequeue(T &);
    bool isEmpty() const;
    void clear();
};

int main()
{
    string name;

    DynamicQueue<string> stringQueue;

    cout << "Queing up elements.\n";
    stringQueue.enqueue("Yohannes");
    stringQueue.enqueue("Eyobel");
    stringQueue.enqueue("Miki");
    stringQueue.enqueue("Henok");
    stringQueue.enqueue("Abel");

    cout << "Dequining elements from queue\n";
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
    stringQueue.dequeue(name);
    cout << name << endl;
}

template <class T>
DynamicQueue<T>::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

template <class T>
DynamicQueue<T>::~DynamicQueue()
{
    clear();
}

template <class T>
void DynamicQueue<T>::enqueue(T number)
{
    QueueNode *newNode = nullptr;

    newNode = new QueueNode;

    newNode->value = number;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++;
}

template <class T>
void DynamicQueue<T>::dequeue(T &number)
{
    QueueNode *temp = nullptr;

    if (isEmpty())
        cout << "The Queue is Empty\n";
    else
    {
        number = front->value;
        temp = front;
        front = front->next;
        delete temp;

        numItems--;
    }
}

template <class T>
bool DynamicQueue<T>::isEmpty() const
{
    bool status;
    if (numItems == 0)
        status = true;
    else
        status = false;
    return status;
}

template <class T>
void DynamicQueue<T>::clear()
{
    T num;

    while (!isEmpty())
        dequeue(num);
}
