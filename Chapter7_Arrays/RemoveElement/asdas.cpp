#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int x, y;
    cin >> x >> y;

    vector<int> numbers;

    for (int i = 0; i < x; i++)
        cin >> numbers[i];

    cout << "asd" << endl;
    for (int i = 0; i < x; i++)
        cout << numbers[i] << " ";
}