#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countConstruct(string target, vector<string> &words, unordered_map<string, int> &memo){
    if(target == "")
        return 1;
    if(memo.find(target) != memo.end())
        return memo[target];

    int total = 0;
    for(string word : words){
        if(target.find(word) == 0){
            int current = countConstruct(target.substr(word.length()), words, memo);
            total += current;
        }
    }

    memo[target] = total;
    return memo[target];
}

int main(){
    vector<string> words = {"ab", "abc", "def", "de", "abcd"};
    string target = "abcdef";
    unordered_map<string, int> memo;
    int num = countConstruct(target, words, memo); 
    if (num != 0)
        cout << "Possible to construct a string: " << num << " ways.\n";
    else
        cout << "Impossible to construct a string: " << num << " ways.\n";
    memo.clear();

    words = {"sk", "ate", "boar", "skate", "rd"};
    target = "skateboard";
    num = countConstruct(target, words, memo); 
    if (num != 0)
        cout << "Possible to construct a string: " << num << " ways.\n";
    else
        cout << "Impossible to construct a string: " << num << " ways.\n";
    memo.clear();

    words = {"abe", "eb", "be", "a", "abeb"};
    target = "abebe";
    num = countConstruct(target, words, memo); 
    if (num != 0)
        cout << "Possible to construct a string: " << num << " ways.\n";
    else
        cout << "Impossible to construct a string: " << num << " ways.\n";
    memo.clear();

    words = {"e", "ee", "eee", "eeeeeeeeee", "eeeeeeeeeeeeeeeeeeee"};
    target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    num = countConstruct(target, words, memo); 
    if (num != 0)
        cout << "Possible to construct a string: " << num << " ways.\n";
    else
        cout << "Impossible to construct a string: " << num << " ways.\n";
    memo.clear();
}