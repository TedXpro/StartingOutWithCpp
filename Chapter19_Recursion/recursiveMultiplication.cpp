/*Programming challenge Question 5 Recursive Multiplucation.*/
#include <iostream>

using namespace std;

int multiplyRecursively(int, int);

int main()
{
    int number1, number2;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;

        if (number1 < 0 && number2 < 0)
    {
        cout << "The product of " << number1 << " and " << number2 << " is ";
        cout << multiplyRecursively(-1 * number2, -1 * number1) << endl;
    }
    else if (number1 < 0 || number2 < 0)
    {
        if (number1 < 0)
            number1 *= -1;
        else
            number2 *= -1;
        cout << "The product of " << number1 << " and " << number2 << " is ";
        cout << -1 * multiplyRecursively(number2, number1) << endl;
    }
    else
    {
        cout << "The product of " << number1 << " and " << number2 << " is ";
        cout << multiplyRecursively(number2, number1) << endl;
    }
}

/**
 * This function will find the product of two numbers
 * using recursive addition.
 *
 * @param x holds the lowest number.
 * @param y holds the largest number.
 */
int multiplyRecursively(int x, int y)
{
    if (x <= 0)
        return 0;
    return y + multiplyRecursively(x - 1, y);
}
