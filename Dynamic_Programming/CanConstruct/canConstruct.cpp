#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkPrefix(string target, vector<string> &words, unordered_map<string, bool> &memo)
{
    if(memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
        return true;

    for (int i = 0; i < words.size(); i++){
        if (target.find(words[i]) == 0){
            if(checkPrefix(target.substr(words[i].size()), words, memo)) {
                memo[target] = true;
                return true;
            }
        }
    }

    memo[target] = false;
    return false;
}

int main()
{
    vector<string> words = {"ab", "abc", "def", "de", "abcd"};
    string target = "abcdef";
    unordered_map<string, bool> memo;
    if (checkPrefix(target, words, memo))
        cout << "True\n";
    else
        cout << "False\n";
    memo.clear();

    words = {"sk", "ate", "boar", "skate", "rd"};
    target = "skateboard";
    if (checkPrefix(target, words, memo))
        cout << "True\n";
    else
        cout << "False\n";
    memo.clear();

    words = {"abe", "eb", "be", "a", "abeb"};
    target = "abebe";
    if (checkPrefix(target, words, memo))
        cout << "True\n";
    else
        cout << "False\n";
    memo.clear();

    words = {"e", "ee", "eee", "eeeeeeeeee", "eeeeeeeeeeeeeeeeeeee"};
    target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    if (checkPrefix(target, words, memo))
        cout << "True\n";
    else
        cout << "False\n";
    memo.clear();

}