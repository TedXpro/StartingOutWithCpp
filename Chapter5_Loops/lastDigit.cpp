#include <iostream>

using namespace std;

int main()
{
    // I wrote this code not knowing theere is an easiest way 
    // y dumb ass think!!
    long long num, ans;
    long long const a = -1;

    cout << "enter a number: ";
    cin >> num;

    if (num < 0)
    {
        num = num * a;
    }

    long long i = 0;
    while (i <= num)
    {
        i += 10;
    }

    if (i > num)
    {
        i -= 10;
        ans = num - i;
        cout << ans << endl;
    }
    else if (i = num) 
    {
        long long ans = 0;
        cout << ans << endl;
    }

    return 0;
}