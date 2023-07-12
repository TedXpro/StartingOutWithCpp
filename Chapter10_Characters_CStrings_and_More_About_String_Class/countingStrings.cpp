#include <iostream>
#include <string>

using namespace std;

string acceptString();

int main()
{
    string sentence;
    sentence = acceptString();
    cout << sentence << endl;
}

/**
 * This function will accept the string from the user.
 * 
 * @return the string accepted from the user.
*/
string acceptString()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    
    return str;
}