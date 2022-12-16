/*Programming Challenge- Chapter 9, Question 12 page 546.
This program accepts numbers and the size and shifts the
array to the left by one by assigning the first element to be zero.*/
#include <iostream>
#include <memory>

using namespace std;

int *acceptelements(int);
int *shiftArray(int *, int);
void displayArray(int *, int *, int);

int main()
{
    int arrSize;

    cout << "Enter the number of elements of the array: ";
    cin >> arrSize;

    int *ptr = nullptr;
    ptr = acceptelements(arrSize);

    int *shiftptr = nullptr;
    shiftptr = shiftArray(ptr, arrSize);

    displayArray(ptr, shiftptr, arrSize);

    delete[] ptr;
    delete[] shiftptr;
    ptr = nullptr;
    shiftptr = nullptr;
}

/**
 * This function will accept the numbers.
 */
int *acceptelements(int size)
{
    int *arr = new int[size]; // Initiallizing a dynamic array.
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> arr[i];
    }
    return arr;
}

/**
 * This function will shift the elements by one to the left.
 */
int *shiftArray(int *arr, int size)
{
    int *shiftArr = new int[size + 1]; // Initializing a dynamic array.
    for (int i = 0; i < size + 1; i++)
    {
        if (i == 0)
            shiftArr[i] = 0;
        else
            shiftArr[i] = arr[i - 1];
    }
    return shiftArr;
}

/**
 * This function will display both the original and the new array.
 */
void displayArray(int *arr, int *shiftArr, int size)
{
    // display the array before it was shifted.
    cout << "The array before it was shifted one element:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    // display the array after it was shifted.
    cout << "The array after it was shifted one element:\n";
    for (int i = 0; i < size + 1; i++)
        cout << shiftArr[i] << " ";
}