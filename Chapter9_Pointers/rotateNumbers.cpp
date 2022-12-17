/*This program will take in a set of numbers given by
the user and will rotate it a number of times as the user
wants.*/
#include <iostream>

using namespace std;

void acceptNumbers(int *, int);
void rotateNumbers(int *, int, int);
void displayResult(int *, int, int);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size]; // to hold the numbers that will be rotated.
    acceptNumbers(numbers, size);

    int rotate; // to hold the number of times the array is going to be rotated.
    cout << "How many times do you want to rotate the set: ";
    cin >> rotate;

    // rotate the numbers.
    rotateNumbers(numbers, size, rotate);
    // display the result.
    displayResult(numbers, size, rotate);

    return 0;
}

/**
 * This function will take the numbers array and its size
 * as its arguments and will accept the elements of the array.
 */
void acceptNumbers(int *numbers, int arrSize)
{
    for (int index = 0; index < arrSize; index++)
    {
        cout << "Enter element #" << (index + 1) << ": ";
        cin >> numbers[index];
    }
}

/**
 * This function will take the numbers array, the size of the array
 * and the number of times the array will be rotated as its arguments
 * and rotates the array.
 */
void rotateNumbers(int nums[], int arrSize, int n)
{
    for (int counter = 0; counter < n; counter++)
    {
        for (int i = 0; i < (arrSize - 1); i++)
        {
            int temp;
            temp = nums[i];
            nums[i] = nums[arrSize - 1];
            nums[arrSize - 1] = temp;
        }
    }
}

/**
 * This function will take in the rotated array and its size
 * as its arguments and displays the result.
 */
void displayResult(int *finalArray, int arrSize, int rotate)
{
    cout << "The set of numbers after " << rotate << " rotations is:\n";
    for (int i = 0; i < arrSize; i++)
        cout << finalArray[i] << " ";
}