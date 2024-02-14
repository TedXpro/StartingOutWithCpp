#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define a type for memoization
using MemoMap = unordered_map<string, vector<int>>;

string vectorToString(const vector<int> &vec)
{
    string result;
    for (int num : vec)
    {
        result += to_string(num) + ",";
    }
    return result;
}

// Modified bestSum function with memoization
void bestSumMemo(int target, const vector<int> &numbers, vector<int> &current, vector<int> &best, MemoMap &memo)
{
    // Create a unique key for the current state
    string key = to_string(target) + ":" + vectorToString(current);

    // Check if the result is already memoized
    if (memo.find(key) != memo.end())
    {
        best = memo[key];
        return;
    }

    if (target == 0)
    {
        if (best.empty() || current.size() < best.size())
            best = current;

        // Memoize the result
        memo[key] = best;
        return;
    }

    if (target < 0)
        return;

    for (int num : numbers)
    {
        current.push_back(num);
        bestSumMemo(target - num, numbers, current, best, memo);
        current.pop_back();
    }

    // Memoize the result
    memo[key] = best;
}

int main()
{
    vector<int> current;
    vector<int> numbers = {1, 2, 5, 25};
    vector<int> bestCombination;
    MemoMap memo; // Memoization table

    bestSumMemo(100, numbers, current, bestCombination, memo);

    if (!bestCombination.empty())
    {
        cout << "Best Combination: ";
        for (int num : bestCombination)
            cout << num << " ";
        cout << endl;
    }
    else
    {
        cout << "No combination found." << endl;
    }

    return 0;
}
