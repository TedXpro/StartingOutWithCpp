#include "Prime.h"
#include <iostream>

using namespace std;

/**
 * Setting the value of the num from the user to number.
 *
 * @param num is the number recieved from the user.
 */
void Prime::setNumber(int num)
{
    number = num;
}

/**
 * Check if the number is prime or composite.
 *
 * @param number is the number to be checked.
 */
void Prime::checkPrime() const
{
    if (number == 0 || number == 1)
        cout << number << " is neither prime nor composite.\n";
    else
    {
        bool flag = true;
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                cout << number << " is Composite.\n";
                flag = false;
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << number << " is Prime.\n";
    }
}