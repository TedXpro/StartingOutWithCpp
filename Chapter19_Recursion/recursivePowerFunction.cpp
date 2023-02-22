/*Programming Challenge Question 6 Recursion Power Function.*/
#include <iostream>

using namespace std;

int powerRecursive(int, int);

int main()
{
    int number, power;
    cout << "Enter the number to be raised: ";
    cin >> number;
    cout << "Enter the power(It has to be non-negative): ";
    cin >> power;

    while (power < 0)
    {
        cout << "Error!!\n";
        cout << "The power must be a non-negative number: ";
        cin >> power;
    }

    cout << number << " raised to " << power << " is " << powerRecursive(number, power) << endl;
}

/**
 * This function will find the nth power of a number.
 *
 * @param num holds the number.
 * @param x holds the power.
 *
 * @return the number raised to the power.
 */
int powerRecursive(int num, int x)
{
    if (x <= 0)
        return 1;
    return num * powerRecursive(num, x - 1);
}
