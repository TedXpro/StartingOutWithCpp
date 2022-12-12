#include <iostream>

using namespace std;

void selectionSort(int numbers[], int size)
{
    int minValue, minIndex, i;

    for (i = 0; i < (size - 1); i++)
    {
        minValue = numbers[i];
        minIndex = i;
        for (int index = i + 1; index < size; index++)
        {
            if (numbers[index] < minValue)
            {
                minValue = numbers[index];
                minIndex = index;
            }
        }
        numbers[minIndex] = numbers[i];
        numbers[i] = minValue;
    }
}

void showArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
}

int main()
{
    int size = 6;
    int numbers[size] = {5, 7, 2, 8, 9, 1};

    cout << "The array before being sorted is: ";
    showArray(numbers, size);

    selectionSort(numbers, size);

    cout << "\nThe array after being sorted is:  ";
    showArray(numbers, size);
}