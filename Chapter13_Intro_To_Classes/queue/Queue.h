#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

class Queue
{
private:
    std::vector<int> customers; // holds the customer
public:
    int peek() const;
    void enqueue(int);
    void dequeue();
    int size() const;
};

#endif