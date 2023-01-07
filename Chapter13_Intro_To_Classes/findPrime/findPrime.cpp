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
        integer.setNumber(n);
        integer.checkPrime();

        cout << "Do u want to continue 'Y/n': ";
        cin >> ans;
    } while (ans != 'N' && ans != 'n');
}