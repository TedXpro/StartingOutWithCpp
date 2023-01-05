/*This program will find numbers that can add up
and give the number the user wants.*/
#include <iostream>

using namespace std;

void acceptNumbers(int[], int);
bool checkNumbers(int, int, int);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size];
    acceptNumbers(numbers, size);

    int n;
    cout << "Enter the number: ";
    cin >> n;

    int counter = 0;
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (checkNumbers(numbers[i], numbers[j], n))
            {
                cout << numbers[i] << " " << numbers[j] << endl;
                counter++;
            }
        }
    }
    if (counter == 0)
        cout << "There is no number that can add up to give the number " << n << endl;
}

/**
 * Accept Numbers.
 *
 * @param arrSize is the size of the array.
 * @param nums is the array that will contain the numbers.
 */
void acceptNumbers(int nums[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> nums[i];
    }
}

/**
 * Check if the first two parameters add up to give the third parameter.
 *
 * @param f is the firstNumber to be summed.
 * @param l is the secondNumber to be summed.
 * @param num is the number to checked to.
 * @return 1 if the numbers add up or 0 if the numbers dont.
 */
bool checkNumbers(int f, int l, int num)
{
    if ((f + l) == num)
        return 1;
    return 0;
}