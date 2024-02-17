#include <iostream>
#include <vector>

using namespace std;

vector<int> howSum(int target, vector<int> &numbers)
{
    vector<vector<int>> dp(target + 1, vector<int>{});
    dp[0] = vector<int>{};
    for (int i = 0; i < dp.size(); i++)
    {
        if (!dp[i].empty())
        {
            for (int num : numbers)
            {
                // // if (i + num <= target)
                // // {
                //     vector<int> current = dp[i];
                //     current.push_back(num);
                //     dp[i + num] = move(current);
                // // }

                if (i + num <= target)
                {
                    std::vector<int> combined = dp[i];
                    combined.push_back(num);

                    if (dp[i + num].empty() || combined.size() < dp[i + num].size())
                    {
                        dp[i + num] = combined;
                    }
                }
            }
        }
    }

    return dp[target];
}

int main()
{
    vector<int> numbers = {2, 3};
    vector<int> answer = howSum(7, numbers);
    if (!answer.empty())
    {
        cout << "True: Its possible to construct it.\n";
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {5, 4, 7, 3};
    answer = howSum(7, numbers);
    if (!answer.empty())
    {
        cout << "True: Its possible to construct it.\n";
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {2, 4};
    answer = howSum(7, numbers);
    if (!answer.empty())
    {
        cout << "True: Its possible to construct it.\n";
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {2, 3, 5};
    answer = howSum(7, numbers);
    if (!answer.empty())
    {
        cout << "True: Its possible to construct it.\n";
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
        cout << "False: Its Impossible to construct it.\n";

    numbers = {7, 14};
    answer = howSum(300, numbers);
    if (!answer.empty())
    {
        cout << "True: Its possible to construct it.\n";
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
        cout << "False: Its Impossible to construct it.\n";
}