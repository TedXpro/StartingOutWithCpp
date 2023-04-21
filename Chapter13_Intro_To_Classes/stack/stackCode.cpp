#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack nums;
    int choice, counter = 0;
    do
    {
        cout << "\tMenu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peak\n";
        cout << "4. Size\n";
        cout << "0. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 0 || choice > 4)
        {
            cout << "The number u entered is not in the range (0 - 4)\n";
            cout << "Please try again: ";
            cin >> choice;
        }

        // if ((choice == 2 || choice == 3) && counter == 0)
        // {
        //     cout << "There are no stacks at the moment.\nPlease push some numbers first!\n";
        //     continue;
        // }
        if (choice == 1)
        {
            int n;
            cout << "Enter number: ";
            cin >> n;
            nums.push(n);
            counter++;
        }
        else if (choice == 2)
            nums.pop();
        else if (choice == 3)
             nums.peak();
        else if (choice == 4)
            cout << "There are " << nums.size() << " elements at the moment " << endl;
    } while (choice != 0);
    cout << "Thank you for using!\n";
}