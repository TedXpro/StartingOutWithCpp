#include <iostream>

using namespace std;

int main()
{
    const int test = 2;
    int num;

    cout << "enter the number to be tested: ";
    cin >> num;

    if ((num % test) == 0 )
        cout << "the number " << num << " is an even number." << endl;
    else
        cout << "the number " << num << " is an odd number." << endl; 
        
    return 0;
}