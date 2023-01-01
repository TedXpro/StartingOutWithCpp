/*This program will find numbers that can add up
and give the number the user wants.*/
#include <iostream>

using namespace std;

bool checkNumbers(int, int, int);

int main()
{
    int first, last;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the last number: ";
    cin >> last;

    int number;
    cout << "Enter the number: ";
    cin >> number;

    int counter = 0;

    for (int i = first; i <= last; i++)
    {
        for (int j = first; j <= last; j++)
        {
            if (checkNumbers(i, j, number))
            {
                counter++;
                cout << i << " & " << j << endl;
                if (i == (number / 2))
                    exit(0);
            }
        }
    }
    if (counter == 0)
        cout << "I cant find any number between " << first << " and " << last
             << " that can add up to give " << number << endl;
}

/**
 * Check if the first two parameters add up to give the third parameter.
 *
 * @param the first two contain the numbers to be summed, the last
 * contains the number to be checked.
 * @return 1 if the numbers add up or 0 if the numbers dont.
 */
bool checkNumbers(int f, int l, int num)
{
    if ((f + l) == num)
        return 1;
    return 0;
}