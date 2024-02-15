#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gridTraveler(int m, int n, unordered_map<string, int> &memo) {
    string key = to_string(m) + "," + to_string(n);
    if(memo.find(key) != memo.end())
        return memo[key];
    if (m == 0 || n == 0)
        return 0;
    if (m == 1 && n == 1)
        return 1; 

    if (memo.find(key) != memo.end())
        return memo[key];

    memo[key] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
    return memo[key];
}

int main()
{
    unordered_map<string, int> memo;

    long answer = gridTraveler(10, 10, memo);
    cout << answer << endl;

    return 0;
}
