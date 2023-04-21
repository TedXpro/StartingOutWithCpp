#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> numbers;
    bool execption()
    {
        if (numbers.size() == 0)
            return true;
        return false;
    }

public:
    void push(int num)
    {
        numbers.push_back(num);
    }
    void pop()
    {
        if (execption())
        {
            cout << "There are no more numbers to be poped at the moment!\n";
            return;
        }
        else
        {
            int n = numbers[numbers.size() - 1];
            numbers.pop_back();
            cout << "The numbers poped out is: " << n << endl;
        }
    }
    void peak()
    {
        if (execption())
        {
            cout << "There are no more numbers to see at the moment!\n";
            return ;
        }
        cout << "The number at the top is " << numbers[numbers.size() - 1] << endl;
    }
    int size()
    {
        return numbers.size();
    }
};

#endif