#include <iostream>

using namespace std;

inline int acceptNumber();
void extract(int);

int main()
{
    int number = acceptNumber();

    extract(number);
    cout << endl;
}

/**
 * This function will accept the number from the user.
 *
 * @return the number the user entered.
 */
inline int acceptNumber()
{
    int num;
    cout << "Enter the Number: ";
    cin >> num;

    return num;
}

/**
 * This function will separate the numbers recursively.
 *
 * @param num holds the value.
 */
void extract(int num)
{
    if (num < 10)
        cout << num << " ";
    else
    {
        extract(num / 10);
        cout << num % 10 << " ";
    }
}