#include <iostream>
#include "Prime.h"

using namespace std;

int main()
{
    char ans;
    do
    {
        int n;
        Prime integer;
        cout << "Enter a number: ";
        cin >> n;
        if (n < 0)
        {
            cout << "The number you entered is a negative number.\n";
            continue;
        }
        integer.setNumber(n);
        integer.checkPrime();

        cout << "Do u want to continue 'Y/n': ";
        cin >> ans;
    } while (ans != 'N' && ans != 'n');
}