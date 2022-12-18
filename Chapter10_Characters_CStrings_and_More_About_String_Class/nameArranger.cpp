/*This Program will accept a fullname and rearranges it.*/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    const char SPACE = ' ';
    string fullName, firstName, secondName, lastName, reName;

    cout << "Enter your name: ";
    getline(cin, fullName);

    int size = fullName.length();
    int count = 0;
    while (count != (size) && fullName[count] != SPACE)
    {
        firstName += fullName[count];
        count++;
    }
    count++;
    while (count != (size) && fullName[count] != SPACE)
    {
        secondName += fullName[count];
        count++;
    }
    count++;
    while (count != (size) && fullName[count] != SPACE)
    {
        lastName += fullName[count];
        count++;
    }
    reName = lastName + ", " + firstName + " " + secondName;
    cout << reName << endl;
}