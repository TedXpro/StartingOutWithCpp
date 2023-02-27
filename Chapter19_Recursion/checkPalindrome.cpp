/*Programming Challenge Q11: Palindrome Detector.
This program checks the palindrome using recursive function.*/
#include <iostream>

using namespace std;

bool checkPalindrome(string, int, int);

int main()
{
    string palindrome;
    cout << "Enter a string and I will check if its Palindrome: ";
    cin >> palindrome;

    int paliSize = palindrome.length() - 1;
    int index = 0;

    if (checkPalindrome(palindrome, index, paliSize))
        cout << palindrome << " is a palindrome!\n";
    else
        cout << palindrome << " is not a palindrome!\n";
}

/**
 * This function will check is a string is a plindrome 
 * using recursion.
 * 
 * @param pali holds the string to be checked.
 * @param index holds the position of a letter from the left.
 * @param last holds the position of a letter from the right.
 * 
 * @return 1 if the string is Palindrome
 * @reutrn 0 if the string is not a palindrome.
*/
bool checkPalindrome(string pali, int index, int last)
{
    if (pali[index] == pali[last])
    {
        if (index == pali.length() - 1)
            return true;
        else
            return checkPalindrome(pali, ++index, --last);
    }
    else
        return false;
}