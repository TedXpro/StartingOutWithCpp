#include <iostream>

using namespace std;

int main()
{
    // change for a dollar game
    // challenges the user to input amounts of coins to reach a dollar 
    int ones, fives, tens, quarters, halves, tots;
    const int one_birr = 100;

    cout << "welcome to change for a dollar game\n";
    cout << "enter the numbers u think wud make a dollar\n";

    cout << "ones: ";
    cin >> ones;
    cout << "fives: ";
    cin >> fives;
    cout << "tens: ";
    cin >> tens;
    cout << "quarters: ";
    cin >> quarters;
    cout << "halves: ";
    cin >> halves;

    ones *= 1;
    fives *= 5;
    tens *= 10;
    quarters *= 25;
    halves *= 50;

    tots = ones + fives + tens + quarters + halves;

    if (tots == one_birr)
    {
        cout << "congrats u have won the game by getting " << tots << endl;
    }
    else if (tots > one_birr)
    {
        cout << "the total amount " << tots << " is greater than the required amount which is one birr or 100 cents\n";
    }
    else if(tots < one_birr)
    {
        cout << "the total amount " << tots << " is greater than the required amount which is one birr or 100 cents.\n";
    }
}