#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num = 5;
    int *ptr = &num;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &num << endl;
    cout << &ptr << endl;
}