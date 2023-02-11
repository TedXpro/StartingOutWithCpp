#include "Queue.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * This function tells the next customer to be served.
 *
 * @returns the next customer waiting inline.
 */
int Queue::peek() const
{
    if (customers.size() == 0)
        return -1;
    return customers[0];
}

/**
 * This function will add the customer to the waiting line.
 */
void Queue::enqueue(int cust)
{
    customers.push_back(cust);
}

/**
 * This function will remove the customer at the begining of the line.
 */
void Queue::dequeue() 
{
    std::vector<int>::const_iterator itr = customers.begin(); // holds the first element of the vector.
    customers.erase(itr);
}

/**
 * This function will show the total amount of customers waiting inline.
 *
 * @return the total amount of customers waiting inline.
 */
int Queue::size() const
{
    return customers.size();
}
