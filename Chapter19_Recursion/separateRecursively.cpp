#include <iostream>
#include <vector>

using namespace std;

int acceptNumber();
void extract(int, vector<int> *);
void display(vector<int> *);

int main()
{
    int number = acceptNumber();

    vector<int> separate;

    extract(number, &separate);
    display(&separate);
}

/**
 * This function will accept the number from the user.
 * 
 * @return the number the user entered. 
*/
int acceptNumber()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    return num;
}

/**
 * This function will separate the number.
 * 
 * @param num holds the number to be separated.
 * @param sep holds the numbers that are separated.
*/
void extract(int num, vector<int> *sep)
{
    if (num < 10)
        (*sep).push_back(num);
    else
    {
        (*sep).push_back(num % 10);
        extract(num / 10, sep);
    }
}

/**
 * This function will display the result.
 * 
 * @param sep holds the separated numbers. 
*/
void display(vector<int> *sep)
{
    for (int i = (*sep).size()- 1; i >= 0; i--)
        cout << (*sep)[i] << " ";
    cout << endl;
}