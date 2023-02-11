#include <iostream>
#include "Queue.h"
#include <vector>

using namespace std;

int main()
{
    Queue kebele;
    int option;
    do
    {
        cout << "Enter the number of your option:\n";
        cout << "1. Peak\n";
        cout << "2. enqueue\n";
        cout << "3. Dequeue\n";
        cout << "4. size\n";
        cout << "0. Quit\n";
        cout << "Input: ";
        cin >> option;

        while (option > 5 || option < 0)
        {
            cout << "Please enter yout choice between 0-4: ";
            cin >> option;
        }

        if (option == 1)
        {
            if (kebele.peek() == -1)
                cout << "There are no customers waiting inline at the moment!\n";
            else
                cout << "The next customer is: " << kebele.peek() << endl;
        }
        else if (option == 2)
        {
            int customer;
            cout << "Enter the next customer: ";
            cin >> customer;
            kebele.enqueue(customer);
        }
        else if (option == 3)
        {
            if (kebele.size() == 0)
                cout << "There are no customers waiting inline at the moment!\n";
            else
            {
                cout << "The customer being served now is: " << kebele.peek() << endl;
                kebele.dequeue();
            }
        }
        else if (option == 4)
            cout << "The amount of customers waiting in line is: " << kebele.size() << endl;
        else
            cout << "Thank you!\nHave a great day:)\n";
    } while (option != 0);
}