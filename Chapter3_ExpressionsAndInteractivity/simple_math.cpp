#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int min_num = 1, max_num = 10;
    int num;

    num = min_num;

    cout << "Number" << "\t\t" << "Number Squared" << "\t\t" << "Number Cubed" << endl;
    while (num <= max_num)
    {
        cout << num << "\t\t" << pow(num,2) << "\t\t\t\t" << pow(num,3) << endl;
        num ++;
    }
}