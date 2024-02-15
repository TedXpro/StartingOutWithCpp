#include <iostream>
#include <vector>

using namespace std;

long long fib(int n){
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int start = 0; start + 1 < dp.size(); start++){
        dp[start + 1] += dp[start];
        if(start + 2 < dp.size())
            dp[start + 2] += dp[start];
    }
    return dp[n];
}

int main(){
    long long answer = fib(6);
    cout << answer << endl;

    answer = fib(7);
    cout << answer << endl;

    answer = fib(8);
    cout << answer << endl;

    answer = fib(50);
    cout << answer << endl;
}