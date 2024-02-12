#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canSum(int target, vector<int> numbers, unordered_map<int, bool> &memo){
    if(memo.find(target) != memo.end())
        return memo[target];
    if(target == 0)
        return true;
    if(target < 0)
        return false;
    
    for(int num : numbers){
        if(canSum(target - num, numbers, memo)){
            memo[target] = true;
            return memo[target];
        }
            
    }

    memo[target] = false;
    return memo[target];
}

int main(){
    unordered_map<int, bool> memo;
    bool status = canSum(300, vector<int>{7,14}, memo);
    cout << status << endl;
}
