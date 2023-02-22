/*Programming Challenge Question 9 stringReverser*/
#include <iostream>

using namespace std;

void reverseString(string, int, int);

int main()
{
    string sentence;
    cout << "Enter the string to be reversed: ";
    getline(cin, sentence);
    int SentSize = sentence.length();
    cout << SentSize << endl;

    cout << "The reverse is\n";
    reverseString(sentence, 0, SentSize);
    cout << endl;
}

/**
 * This Function will reverse a given string.
 *
 * @param str holds the string.
 * @param pos holds the position of the string.
 * @param strSize holds the size of the string.
 *
 * @return the reversed string.
 */
void reverseString(string str, int pos, int strSize)
{
    if (pos < strSize)
    {
        reverseString(str, pos + 1, strSize);
        cout << str[pos];
    }
}