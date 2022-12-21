#include <iostream>

using namespace std;

void acceptNumbers(int[], int);
void copyNumbers(int[], int[], int);
void sortNumbers(int[], int);
int findSecondLargest(int[], int);
void displayAnswer(int[], int, int);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    while (size < 0)
    {
        cout << "Please Enter the size of the array greater than 1\n";
        cout << "Enter the size of the array: ";
        cin >> size;
    }
    int numbers[size], numbersCopy[size];

    acceptNumbers(numbers, size);
    copyNumbers(numbers, numbersCopy, size);
    sortNumbers(numbersCopy, size);

    int secondLargest;
    secondLargest = findSecondLargest(numbersCopy, size);

    displayAnswer(numbers, size, secondLargest);
}

/**
 * This function will accept the numbers from the user.
 */
void acceptNumbers(int numbers[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> numbers[i];
    }
}

/**
 * This function will copy the existing set of numbers into
 * another array.
 */
void copyNumbers(int nums[], int numsCopy[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        numsCopy[i] = nums[i];
}

/**
 * This function will sort the numbers in ascending order.
 */
void sortNumbers(int nums[], int arrSize)
{
    int minValue, minIndex;
    for (int i = 0; i < (arrSize - 1); i++)
    {
        minValue = nums[i];
        minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (nums[j] < minValue)
            {
                minValue = nums[j];
                minIndex = j;
            }
        }
        nums[minIndex] = nums[i];
        nums[i] = minValue;
    }
}

/**
 * This function will find the second largest number in the set.
 */
int findSecondLargest(int nums[], int arrSize)
{
    int max = nums[arrSize - 1];
    int secondLargest;
    for (int i = (arrSize - 2); i > 0; i--)
    {
        if (nums[i] < max)
        {
            secondLargest = nums[i];
            break;
        }
    }
    return secondLargest;
}

/**
 * This function will display the result of the program.
 */
void displayAnswer(int nums[], int arrSize, int secondLargest)
{
    cout << "The second largest number in the set:\n";
    for (int i = 0; i < arrSize; i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "Second Largest Number: " << secondLargest << endl;
}