#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool howSum(int target, vector<int> &numbers, vector<int> &answer, unordered_map<int, bool> &memo){
    if(memo.find(target) != memo.end())
        return memo[target];
    if (target == 0)
        return true;
    if(target < 0)
        return false;
    
    for(int num : numbers){
        if(howSum(target - num, numbers, answer, memo)){
            answer.push_back(num);
            return true;
        }
    }

    memo[target] = false;
    return false;
}

int main(){
    vector<int> answer {};
    vector<int> numbers = {2, 3, 4, 5, 7};
    unordered_map<int, bool> memo;
    int target = 8;
    bool status = howSum(target, numbers, answer, memo);

    if(status){
        for(int num : answer)
            cout << num << " ";
        cout << endl;
    }else {
        cout << "Cannot find an array that sum to " << target << endl;
    }

    answer = {};
    numbers = {14, 7};
    memo.clear();
    target = 300;
    status = howSum(target, numbers, answer, memo);

    if (status)
    {
        for (int num : answer)
            cout << num << " ";
        cout << endl;
    }
    else
    {
        cout << "Cannot find an array that sum to " << target << endl;
    }
}