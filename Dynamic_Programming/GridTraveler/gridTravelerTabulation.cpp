#include <iostream>
#include <vector>

using namespace std;

long long gridTraveler(int row, int col){
    vector<vector<long long>> grid(row + 1, vector<long long>(col + 1));
    grid[1][1] = 1;
    for (int r = 0; r < grid.size(); r++){
        for (int c = 0; c < grid[r].size(); c++){
            if(r  + 1 >= grid.size() && c + 1 < grid[r].size())
                grid[r][c + 1] += grid[r][c];
            if(c + 1 >= grid[r].size() && r + 1 < grid.size())
                grid[r + 1][c] += grid[r][c];
            if(r + 1 < grid.size() && c + 1 < grid[r].size()){
                grid[r + 1][c] += grid[r][c];
                grid[r][c + 1] += grid[r][c];
            }
        }
    }

    return grid[row][col];
}

int main(){
    long long answer = gridTraveler(1, 1);
    cout << answer << endl;

    answer = gridTraveler(2, 3);
    cout << answer << endl;

    answer = gridTraveler(3, 2);
    cout << answer << endl;

    answer = gridTraveler(3, 3);
    cout << answer << endl;

    answer = gridTraveler(18, 18);
    cout << answer << endl;
}