#include <iostream>

using namespace std;

int factorial(int);

int main()
{
    int number;
    cout << "Enter the number to find the factorial: ";
    cin >> number;

    cout << "The factorial of " << number << " is " << factorial(number) << endl;
}

/**
 * This function will find the factorial of a number using recurrsive method.
 * 
 * @param num holds the value the user entered.
 * 
 * @return the factorial of num.
*/
int factorial(int num)
{
    if (num == 0)
        return 1;
    else
    {
        return num * factorial(num - 1);
    }
}