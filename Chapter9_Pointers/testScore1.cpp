/*Programming Challenge Chpater 9, page 544 Question 2.
This program accepts test socres, sorts them in Ascending
order and calculates the average.*/
#include <iostream>

using namespace std;

double *acceptTestScores(int *);
double *sortArrays(double *, int *);
double calAverage(double *, int *);
void displayScores(double *, double *, int *);

int main()
{
    int arraySize;
    cout << "Enter the amount of test scores to be averaged: ";
    cin >> arraySize;

    double *testScores = nullptr;

    testScores = acceptTestScores(&arraySize);
    testScores = sortArrays(testScores, &arraySize);

    double Average;
    Average = calAverage(testScores, &arraySize);

    displayScores(testScores, &Average, &arraySize);

    delete[] testScores;
    delete[] testScores;

    testScores = nullptr;
}

/**
 * This function accepts test scores on to a dynamic memory and returns the arrays address.
 */
double *acceptTestScores(int *size)
{
    double *arr = nullptr;
    arr = new double[*size]; // Creating a dynamic array.

    for (int i = 0; i < *size; i++)
    {
        cout << "Enter test score #" << (i + 1) << ": ";
        cin >> arr[i];
        while (arr[i] > 100 || arr[i] < 0)
        {
            cout << "Enter the test scores between 0 and 100." << endl;
            cout << "Enter test score#" << (i + 1) << ": ";
            cin >> arr[i];
        }
    }
    return arr;
}

/**
 * This function will sort the array in ascending order and returns the address.
 */
double *sortArrays(double *arr, int *size)
{
    double minScore;
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
 * This function will calculate the average of the scores.
 */
double calAverage(double *arr, int *size)
{
    double total = 0, ave;

    // Adding every score in the array to find the total.
    for (int i = 0; i < *size; i++)
    {
        total += arr[i];
    }
    ave = total / (*size);
    return ave;
}

/**
 * This function will display the scores, total, and Average
 .
 */
void displayScores(double *arr, double *ave, int *size)
{
    double total;
    cout << "Test Scores: " << endl;
    for (int i = 0; i < (*size); i++)
    {
        cout << "Test Score # " << (i + 1) << ": ";
        cout << arr[i] << endl;
    }

    total = *ave * (*size); // Calculating the total.
    cout << "\nThe total of the socres: " << total << endl;
    cout << "The average of the socres: " << *ave << endl;
}
