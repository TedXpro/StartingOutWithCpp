#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> &wordDict, unordered_map<string, vector<vector<string>>> &memo){
    if(memo.find(target) != memo.end())
        return memo[target];
    if (target.empty())
        return {{}};

    vector<vector<string>> result;

    for (const string &word : wordDict) {
        if (target.find(word) == 0) {
            string suffix = target.substr(word.length());
            vector<vector<string>> suffixWays = allConstruct(suffix, wordDict, memo);

            for (vector<string> &way : suffixWays){
                way.insert(way.begin(), word);
                result.push_back(way);
            }
        }
    }

    memo[target] = result;
    return result;
}

int main()
{
    string target = "purple";
    vector<string> words = {"purp", "p", "ur", "le", "purpl"};
    unordered_map<string, vector<vector<string>>> memo;
    vector<vector<string>> result = allConstruct(target, words, memo);

    cout << "{\n";
    for (const vector<string> &way : result)
    {
        cout << "   [ ";
        for (int i = 0; i < way.size(); i++){
            cout << way[i];
            if(i < way.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}\n\n";

    result.clear();
    memo.clear();

    words = {"ab", "abc", "cd", "def", "ef", "c", "abcd"};
    target = "abcdef";
    // unordered_map<string, bool> memo;

    result = allConstruct(target, words, memo);
    cout << "{\n";
    for (const vector<string> &way : result)
    {
        cout << "   [ ";
        for (int i = 0; i < way.size(); i++)
        {
            cout << way[i];
            if (i < way.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}\n\n";
    result.clear();
    memo.clear();

    words = {"sk", "ate", "boar", "skate", "rd"};
    target = "skateboard";
    result = allConstruct(target, words, memo);
    cout << "{\n";
    for (const vector<string> &way : result)
    {
        cout << "   [ ";
        for (int i = 0; i < way.size(); i++)
        {
            cout << way[i];
            if (i < way.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}\n\n";
    result.clear();

    memo.clear();

    words = {"abe", "eb", "be", "a", "abeb"};
    target = "abebe";
    result = allConstruct(target, words, memo);
    cout << "{\n";
    for (const vector<string> &way : result)
    {
        cout << "   [ ";
        for (int i = 0; i < way.size(); i++)
        {
            cout << way[i];
            if (i < way.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}\n\n";
    result.clear();
    memo.clear();

    words = {"e", "ee", "eee", "eeeeeeeeee", "eeeeeeeeeeeeeeeeeeee"};
    target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    result = allConstruct(target, words, memo);
    cout << "{\n";
    for (const vector<string> &way : result)
    {
        cout << "   [ ";
        for (int i = 0; i < way.size(); i++)
        {
            cout << way[i];
            if (i < way.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "}\n\n";
    result.clear();

    memo.clear();
}
