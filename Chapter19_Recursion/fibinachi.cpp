#include <iostream>

using namespace std;

int fibinachi(int);

int main()
{
    int nth;
    cout << "Enter the any number and I will find all "
         << "the fibinachi numbers: ";
    cin >> nth;

    cout << "The first " << nth << " fibinachi numbers upto "
         << " are :\n";
    for (int i = 0; i < nth; i++)
        cout << fibinachi(i) << " ";
    cout << endl;
}

/**
 * This function will find the nth fibinachi number.
 *
 * @param n holds the nth number.
 *
 * @return the nth fibinachi number.
 */
int fibinachi(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibinachi(n - 1) + fibinachi(n - 2);
}