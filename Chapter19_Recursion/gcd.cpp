#include <iostream>

using namespace std;

int gcd(int, int);

int main()
{
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl;
    return 0;
}

/**
 * This function will find the gcd of two numbers.
 * 
 * @param n1 holds the first number.
 * @param n2 holds the second number.
 * 
 * @return the gcd of the two numbers using recursive function.
*/
int gcd(int n1, int n2)
{
    if (n1 % n2 == 0)
        return n2;
    else
        return gcd(n2, n1 % n2);
}