#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int num = 0, sum = 0;
    ifstream readData("file.txt");
    while (readData >> num)
    {
        sum += num;
    }
    cout << sum << endl;
    
}