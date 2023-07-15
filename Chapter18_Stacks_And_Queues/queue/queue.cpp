#include <iostream>

using namespace std;

template<class T>
class Queue
{
private:
    T *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;

public:
    Queue(int);

    Queue(const Queue &);

    ~Queue();

    void enqueue(T);
    void dequeue(T &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

int main()
{
    Queue<int> iQueue(8);

    cout << "Enqueing elements to the queue.\n";
    iQueue.enqueue(10);
    iQueue.enqueue(100);
    iQueue.enqueue(1000);
    iQueue.enqueue(10000);
    iQueue.enqueue(100000);
    iQueue.enqueue(10);

    cout << "dequing elements from the queue.\n";

    while(!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << endl;
    }

}

template<class T>
Queue<T>::Queue(int size)
{
    queueArray = new T[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

template<class T>
Queue<T>::Queue(const Queue &obj)
{
    queueArray = new int[obj.queueSize];

    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queueArray;
}

template <class T>
void Queue<T>::enqueue(T number)
{
    if (isFull())
        cout << "The queue is full\n";
    else
    {
        rear = (rear + 1) % queueSize;

        queueArray[rear] = number;

        numItems++;
    }
}

template <class T>
void Queue<T>::dequeue(T &number)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        front = (front + 1) % queueSize;

        number = queueArray[front];

        numItems--;
    }
}

template <class T>
bool Queue<T>::isEmpty() const
{
    bool status;

    if (numItems)
        status = false;
    else
        status = true;

    return status;
}

template <class T>
bool Queue<T>::isFull() const
{
    bool status;
    if (numItems == queueSize)
        status = true;
    else
        status = false;

    return status;
}

template <class T>
void Queue<T>::clear()
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}