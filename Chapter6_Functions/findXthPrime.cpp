/*This program will find the Xth prime number given by
the user.*/
#include <iostream>

using namespace std;

bool checkPrime(int);

int main()
{
    int counter;
    cout << "Enter the number: ";
    cin >> counter;
    int xth = counter;

    int num = 2;
    while (counter != 0)
    {
        if (checkPrime(num))
        {
            counter--;
            if (counter == 0)
                continue;
        }
        num++;
    }
    if (xth == 1)
        cout << "The first prime number is: " << num << endl;
    else if (xth == 2)
        cout << "The second prime number is: " << num << endl;
    else if (xth == 3)
        cout << "The third prime number is: " << num << endl;
    else
        cout << "The " << xth << "th prime number is: " << num << endl;
}

/**
 * Checks if its prime or not.
 *
 * @param values Container whose values are checked if divisible by numbers.
 * @return 1 or 0, if `value` is prime returns 1 if not returns 0.
 */
bool checkPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}