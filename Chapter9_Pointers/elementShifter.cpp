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

int *acceptelements(int size)
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> arr[i];
    }
    return arr;
}

int *shiftArray(int *arr, int size)
{
    int *shiftArr = new int[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        if (i == 0)
            shiftArr[i] = 0;
        else
            shiftArr[i] = arr[i - 1];
    }
    return shiftArr;
}

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