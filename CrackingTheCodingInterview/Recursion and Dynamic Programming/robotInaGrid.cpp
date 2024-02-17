#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool findPath(vector<vector<bool>> &grid, int row, int col, vector<vector<int>> &path, unordered_map<string, bool> &memo)
{
    string key = to_string(row) + "," + to_string(col);
    if(memo.find(key) != memo.end())
        return memo[key];

    if (row >= grid.size() || col >= grid[row].size() || !grid[row][col]){
        memo[key] = false;
        return false;
    }

    if (row == grid.size() - 1 && col == grid[row].size() - 1)
    {
        vector<int> current;
        current.push_back(row);
        current.push_back(col);
        path.push_back(current);
        memo[key] = true;
        return true;
    }

    if (findPath(grid, row + 1, col, path, memo) || findPath(grid, row, col + 1, path, memo))
    {
        vector<int> current;
        current.push_back(row);
        current.push_back(col);
        path.push_back(current);
        memo[key] = true;
        return true;
    }

    memo[key] = false;
    return false;
}

vector<vector<int>> getPath(vector<vector<bool>> &grid)
{
    vector<vector<int>> path;
    vector<vector<int>> current;
    unordered_map<string, bool> memo;
    if (findPath(grid, 0, 0, path, memo))
        return path;
    return current;
}

int main()
{
    vector<vector<bool>> grid = {{true, true, true, true},
                                 {false, true, false, false},
                                 {true, true, true, false},
                                 {true, false, true, true}};

    vector<vector<int>> path = getPath(grid);

    if (!path.empty())
    {
        for (vector<int> &p : path)
            cout << p[0] << "," << p[1] << "->";
        cout << "Destination\n";
        cout << endl;
    }
    else
        cout << "No valid Path\n";

    grid = {{true, true, true, true},
            {false, true, false, false},
            {true, true, true, false},
            {true, false, false, true}};

    path = getPath(grid);

    if (!path.empty())
    {
        for (vector<int> &p : path)
            cout << p[0] << "," << p[1] << "->";
        cout << "Destination\n";
        cout << endl;
    }
    else
        cout << "No valid Path\n\n";

    grid = {{true, true, true},
            {false, true, false},
            {true, true, true},
            {true, false, true}};

    path = getPath(grid);

    if (!path.empty())
    {
        for (vector<int> &p : path)
            cout << p[0] << "," << p[1] << "->";
        cout << "Destination\n";
        cout << endl;
    }
    else
        cout << "No valid Path\n";
}