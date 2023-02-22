/*This program will find the sum of numbers upto 
the given number using recursion.*/
#include <iostream>

using namespace std;

int findSum(int);

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;

    cout << "The sum of the numbers from 1 upto " << number << " is " << findSum(number) << endl;
}

/**
 * This function will find the sum of the numbers.
 * 
 * @param num holds the last number.
 * 
 * @return the sum of the numbers upto num.
*/
int findSum(int num)
{
    if (num <= 0)
        return 0;
    return findSum(num - 1) + num;
}