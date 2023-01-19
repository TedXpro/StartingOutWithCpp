#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> separateString(string);

int main()
{
    string str; // will hold the string but are numbers separated by comma.
    cout << "Enter the string: ";
    cin >> str; 

    vector<string> stringList;
    stringList = separateString(str);

    for (int i = 0; i < stringList.size(); i++)
        cout << stringList[i] << endl;
}

/**
 * This function will separate the strings upto the comma(,).
 *
 * @param answer holds the string entered by the user.
 *
 * @return a vector that holds separated numbers.
 */
vector<string> separateString(string answer)
{
    char ch = ',';
    vector<string> separate;
    int count = 0;
    while (count < answer.size() )
    {
        string ans;
        while (answer[count] != ch)
        {
            ans += answer[count];
            count++;
            if (count == answer.size() )
                break;
        }
        count++;
        separate.push_back(ans);
    return separate;
}