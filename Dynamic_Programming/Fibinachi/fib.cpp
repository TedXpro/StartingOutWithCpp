#include <iostream>
#include <unordered_map>

using namespace std;

long long fib(int n, unordered_map<long long, long long> &memo){
    if(memo.find(n) != memo.end())
        return memo[n];
    if(n <= 2)
        return 1;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main(){
    unordered_map<long long, long long> memo;
    long long answer = fib(50, memo);
    cout << answer << endl;
}

