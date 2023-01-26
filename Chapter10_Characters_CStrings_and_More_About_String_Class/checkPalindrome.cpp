/*This program checks whether a string is spelled
 the same front and back, which is called Palindrome.*/
#include <iostream>
#include <string>

using namespace std;

string acceptString();
string invertString(string);
bool checkPalindrome(string, string);

int main()
{
    string word = acceptString(); // holds the value the user enters.

    string invertedWord = invertString(word); // holds the inverted string.

    if (checkPalindrome(word, invertedWord))
        cout << "The string " << word << " is a PALINDROME.\n";
    else
    {
        cout << "The string " << word << " is not a PALINDROME.\n";
        cout << "The Inverted string is: " << invertedWord << endl;
    }
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
    cin >> str;

    return str;
}

/**
 * This function will invert the string entered by the user.
 *
 * @param str will hold the string to be inverted.
 *
 * @return the inverted string.
 */
string invertString(string str)
{
    string invStr;
    for (int i = (str.size() - 1); i >= 0; i--)
    {
        invStr += str[i];
    }
    return invStr;
}

/**
 * This function will compare the string and the inverted string.
 *
 * @param str holds the string entered by the user.
 * @param invStr holds the inverted string.
 *
 * @return 1 if the inverted and the normal string are the same.
 * @return 0 if the inverted and the normal string are not the same.
 */
bool checkPalindrome(string str, string invStr)
{
    int counter = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == invStr[i])
            counter++;
    }
    if (counter == str.size() && counter == invStr.size())
        return true;
    else
        return false;
}