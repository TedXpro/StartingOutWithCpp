/*This is a simple program that duplicates arrays using
pointers as return values for dynamic memories.*/
#include <iostream>

using namespace std;

int *duplicateArray(const int *, int);
void displayArray(const int[], int);

int main()
{
    const int SIZE1 = 5, SIZE2 = 7, SIZE3 = 10;

    int array1[SIZE1] = {100, 200, 300, 400, 500};
    int array2[SIZE2] = {10, 20, 30, 40, 50, 60, 70};
    int array3[SIZE3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Assigns pointes to nullptr.
    int *dup1 = nullptr, *dup2 = nullptr, *dup3 = nullptr;

    cout << "Here are the arrays before duplicating them: " << endl;
    displayArray(array1, SIZE1);
    displayArray(array2, SIZE2);
    displayArray(array3, SIZE3);

    // Calls in the duplicateArray and assigns the addresses of the dynamic memo to the pointers.
    dup1 = duplicateArray(array1, SIZE1);
    dup2 = duplicateArray(array2, SIZE2);
    dup3 = duplicateArray(array3, SIZE3);

    cout << "Here are the arrays after duplicating them: " << endl;
    displayArray(dup1, SIZE1);
    displayArray(dup2, SIZE2);
    displayArray(dup3, SIZE3);

    // Deletes the dynamic memories after using them.
    delete[] dup1;
    delete[] dup2;
    delete[] dup3;

    dup1 = nullptr;
    dup2 = nullptr;
    dup3 = nullptr;
}

/**
 * This function duplicates the arrays and returns the address of the dynamic memory.
 */
int *duplicateArray(const int *arr, int size)
{
    int *newArray = nullptr;

    if (size <= 0)
        return nullptr;

    // Creates a dynamic memory.
    newArray = new int[size];

    // Assigns values to the dynamic memory.
    for (int i = 0; i < size; i++)
        newArray[i] = arr[i];

    // Returns the dynamic memory.
    return newArray;
}

/**
 * This function displays the arrays that are passed on to it.
 */
void displayArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}