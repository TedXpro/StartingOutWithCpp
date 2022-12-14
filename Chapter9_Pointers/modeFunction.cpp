/*Programming Challenge -- chapter 9, Page 545, Question 8.
This program will accept a set of integers and will find
out the mode of the set of integers.*/
#include <iostream>

using namespace std;

int *acceptNumbers(int *);
int *sortIntegers(int *, int *);
int *findMode(int *, int *);
void displayResult(int *, int *, int *);

int main()
{
    char ch;
    do
    {
        int size;
        cout << "Enter the number of integers that will be given: ";
        cin >> size;

        int *numbers = nullptr;
        numbers = acceptNumbers(&size);
        numbers = sortIntegers(numbers, &size);

        int *result = nullptr;
        result = findMode(numbers, &size);

        displayResult(result, numbers, &size);

        delete[] numbers;
        numbers = nullptr;

        cout << "Do you want the program to quit (Y/n): ";
        cin >> ch;
    } while (ch != 'Y' && ch != 'y');
}

/**
 * This function will accept the numbers.
 */
int *acceptNumbers(int *size)
{
    int *integers = nullptr;
    integers = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        cout << "Enter integer #" << (i + 1) << ": ";
        cin >> integers[i];
    }
    return integers;
}

/**
 * This function will sort the numbers using Selective Sorting.
 */
int *sortIntegers(int *arr, int *size)
{
    int minScore;
    int minIndex;

    // Sorting in Ascending Order using Selective Sorting.
    for (int i = 0; i < (*size - 1); i++)
    {
        minScore = arr[i];
        minIndex = i;
        for (int j = i + 1; j < *size; j++)
        {
            if (arr[j] < minScore)
            {
                minScore = arr[j];
                minIndex = j;
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = minScore;
    }
    return arr;
}

/**
 * This Function will find the mode of the numbers given.
 */
int *findMode(int *numbers, int *size)
{
    int modeCounter = -1; // To count the number of times the mode occured.
    int mostNum;          // To hold numbers that occured once,
    int mode;             // To hold the mode of the numbers.
    for (int i = 0; i < (*size - 1); i++)
    {
        int k = i; //  To change to the next different number
        int num = numbers[i];
        int counter = 0; // To count the number of times a number occured.
        for (int j = i + 1; j < *size; j++)
        {
            if (numbers[j] == num)
            {
                counter++; //  To count how many times each different number occured.
                mostNum = numbers[j];
                k++;
            }
            else
                break;
        }
        i = k;
        if (++counter > modeCounter)
        {
            modeCounter = counter;
            mode = mostNum;
        }
    }
    int *result = nullptr;
    result = new int[2]; // To hold the mode and the modeCounter.

    result[0] = modeCounter;
    result[1] = mode;

    return result;
}

/**
 * This Function will display the result.
 */
void displayResult(int *mode, int *nums, int *size)
{
    if (mode[0] == -1)
    {
        cout << "The numbers {";
        for (int i = 0; i < *size; i++)
        {
            if (i == *size - 1)
            {
                cout << nums[i] << "} ";
            }
            else
                cout << nums[i] << ", ";
        }
        cout << "all appear once and doesnt have a mode." << endl;
    }
    else
    {
        cout << "The mode of the numbers {";
        for (int i = 0; i < *size; i++)
        {
            if (i == *size - 1)
            {
                cout << nums[i] << "} ";
            }
            else
                cout << nums[i] << ", ";
        }
        cout << "is: " << endl;
        cout << "Mode: " << mode[1] << endl;
        cout << "Number of times it appeared: " << mode[0] << endl;
    }
}
