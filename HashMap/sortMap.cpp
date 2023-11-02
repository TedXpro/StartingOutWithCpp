#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> nums = {-4, -1, 0, 1, 3, 10};

    map<int, int> sorted;

    for (int i = 0; i < nums.size(); i++)
    {
        int n = pow(nums[i], 2);
        sorted[n + i] = n;
    }
    vector<int> answer;
    for (auto val : sorted)
    {
        answer.push_back(val.second);
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << endl;

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    cout << endl;
}