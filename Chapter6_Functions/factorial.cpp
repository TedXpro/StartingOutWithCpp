/*This program will find the factorial of a number.*/
#include <iostream>

using namespace std;

int acceptNumber();
int findFactorial(int);
void displayResult(int, int);

int main()
{
    int number = acceptNumber();

    int factorial = findFactorial(number);

    displayResult(number, factorial);
}

/**
 * This function will accept the number from the user.
 *
 * @return the number accepted from the user.
 */
int acceptNumber()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    return num;
}

/**
 * This function will find the factorial of a number.
 *
 * @param num is the number given by the user.
 *
 * @return the factorial of num.
 */
int findFactorial(int num)
{
    if (num < 0)
        cout << "The number u entered is a negative number.\n";
    else if (num == 0 || num == 1)
        return 1;
    return num * findFactorial(num - 1);
}

/**
 * This function will display the result.
 *
 * @param num is the number given by the user.
 * @param fact is the factorial of the number given by the user.
 */
void displayResult(int num, int fact)
{
    cout << "The factorial of the number " << num << " is " << fact << endl;
}