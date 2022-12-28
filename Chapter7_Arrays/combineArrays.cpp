/*This program will accept two arrays from the user,
combines them, then sorts them in asccending order.*/
#include <iostream>

using namespace std;

void acceptNumbers(int[], int);
void addToTotalSet(int[], int[], int[], int, int);
void sortNumbers(int[], int);
void displayResult(int[], int);

int main()
{
    int size1, size2;
    cout << "Enter the size of set 1: ";
    cin >> size1;
    cout << "Enter the size of set 2: ";
    cin >> size2;

    int set1[size1], set2[size2];
    // Accepting elements of the sets.
    cout << "Enter elements of set 1:\n";
    acceptNumbers(set1, size1);
    cout << "Enter elements of set 2:\n";
    acceptNumbers(set2, size2);

    int totalSize = size1 + size2;
    int totalSet[totalSize];

    // Adding all the elements to the total set.
    addToTotalSet(totalSet, set1, set2, size1, size2);

    // Sorting
    sortNumbers(totalSet, totalSize);

    // Displaying the result.
    displayResult(totalSet, totalSize);
}

/**
 * This function will accept the elements.
 */
void acceptNumbers(int set[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> set[i];
    }
}

/**
 * This function will add all the elements to the total set.
 */
void addToTotalSet(int totSet[], int S1[], int S2[], int size1, int size2)
{
    int i = 0;
    for (i; i < size1; i++)
        totSet[i] = S1[i];

    for (int j = 0; j < size2; j++)
    {
        totSet[i] = S2[j];
        i++;
    }
}

/**
 * This function will sort the array in ascending order.
 */
void sortNumbers(int totSet[], int totSize)
{
    int minValue, minIndex;
    for (int i = 0; i < (totSize - 1); i++)
    {
        minValue = totSet[i];
        minIndex = i;
        for (int j = i; j < totSize; j++)
        {
            if (totSet[j] < minValue)
            {
                minValue = totSet[j];
                minIndex = j;
            }
        }
        totSet[minIndex] = totSet[i];
        totSet[i] = minValue;
    }
}

/**
 * This function will display the result after its sorted.
 */
void displayResult(int totSet[], int totSize)
{
    for (int i = 0; i < totSize; i++)
        cout << totSet[i] << " ";
}