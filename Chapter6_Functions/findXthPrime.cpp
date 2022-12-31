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
                break;
            else
                num++;
        }
        else
            num++;
    }
    cout << "The " << xth << "th prime number is: " << num << endl;
}

/**
 * This function will test whether a number is prime or not.
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