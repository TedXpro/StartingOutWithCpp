/*Programming Challenge Question 4: Recursive Array Sum.
This program will find the sum of the elements of an 
array recursively.*/
#include <iostream>

using namespace std;

void acceptNumbers(int[], int);
int sumRecursively(int[], int);

int main()
{
    int size;
    cout << "Enter the number of elements of the array: ";
    cin >> size;
    int numbers[size];

    acceptNumbers(numbers, size);
    cout << "The sum of the numbers is: " << sumRecursively(numbers, size) << endl;
}

/**
 * This function will accept the elements of the array.
 *
 * @param nums holds the elements.
 * @param arrSize holds the size of the array.
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
 * This function will find the sum of the elements of the array.
 *
 * @param nums holds the numbers.
 * @param arrSize holds the size of the array.
 *
 * @return the sum of the array elements.
 */
int sumRecursively(int nums[], int arrSize)
{
    if (arrSize < 0)
        return 0;
    return nums[arrSize - 1] + sumRecursively(nums, arrSize - 1);
}