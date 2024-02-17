#include <iostream>
#include <vector>

using namespace std;

bool canSum(int target, vector<int> &numbers)
{
    vector<bool> canBool(target + 1, false);
    canBool[0] = true;

    for (int i = 0; i < canBool.size(); i++)
    {
        if (canBool[i])
        {
            for (int num : numbers)
            {
                if (i + num < canBool.size())
                    canBool[i + num] = true;
            }
        }
    }

    return canBool[target];
}

int main()
{
    vector<int> numbers = {2, 3};
    bool answer = canSum(7, numbers);
    if (answer)
        cout << "True: Its possible to construct it.\n";
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {5, 4, 7, 3};
    answer = canSum(7, numbers);
    if (answer)
        cout << "True: Its possible to construct it.\n";
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {2, 4};
    answer = canSum(7, numbers);
    if (answer)
        cout << "True: Its possible to construct it.\n";
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {2, 3, 5};
    answer = canSum(7, numbers);
    if (answer)
        cout << "True: Its possible to construct it.\n";
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {7, 14};
    answer = canSum(300, numbers);
    if (answer)
        cout << "True: Its possible to construct it.\n";
    else
        cout << "False: Its Impossible to construct it.\n";
}