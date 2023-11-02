#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    unordered_map<int, int> numMap;
    vector<int> newNums;
    for (int i = 0; i < nums.size(); i++)
    {
        if (numMap[i] != nums[i])
        {
            numMap[i] = nums[i];
            newNums.push_back(numMap[i]);
        }
    }
    nums.swap(newNums);
    return nums.size();
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    cout << k << endl;
    for(int v: nums)
        cout << v << " ";
    cout << endl;
}

// int main()
// {
//     map<int, string> fruits;
//     fruits.insert(pair<int, string>(0, "Apple"));
//     fruits.insert(pair<int, string>(3, "Strawberry"));
//     fruits.insert(pair<int, string>(2, "Orange"));
//     fruits.insert(pair<int, string>(1, "Banana"));

//     for (int i = 0; i < fruits.size(); i++)
//     {
//         cout << fruits[i]
//     }
// }