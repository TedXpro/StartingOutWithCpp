/*This program compares the elements of an array to a number N
and displays those that are greater than the number.
Chapter 7, Programming Challenge Question 4: Larger than n*/
#include <iostream>

using namespace std;

void largerThan(const int nums[], int size, int number)
{
    for (int index = 0; index < size; index++)
    {
        if (nums[index] > number)
        {
            cout << nums[index] << " ";
        }
    }
}

int main()
{
    int arraySize;
    cout << "Enter the number of elements of the array: ";
    cin >> arraySize;

    int numbers[arraySize], n;
    for (int index = 0; index < arraySize; index++)
    {
        cout << "Enter element #" << (index + 1) << ": ";
        cin >> numbers[index];
    }
    cout << "Enter the number that will be compared with the elements in the array: ";
    cin >> n;

    largerThan(numbers, arraySize, n);
    return 0;
}