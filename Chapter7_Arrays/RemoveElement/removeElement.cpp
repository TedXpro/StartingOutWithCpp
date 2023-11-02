#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int temp, k = nums.size();

    int count = 0;
    for (int i = 0, j; i < k; i++)
    {
        if (nums[i] == val)
        {
            for (int j = k - 1; j > i; j--)
            {
                if (nums[j] != nums[i])
                {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    k = j;
                    count++;
                    break;
                }
            }
        }
        else 
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> num = {0, 1, 2, 2, 3, 0, 4, 2};
    int n = removeElement(num, 2);
    cout << n << endl;

    for (int i = 0; i < n; i++)
        cout << num[i] << endl;

    cout << "\n\n";

    for (int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
}