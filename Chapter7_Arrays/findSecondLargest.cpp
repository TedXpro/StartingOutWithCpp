#include <iostream>

using namespace std;

void acceptNumbers(int[], int);
int findSecondLargest(int[], int);
void displayResult(int[], int, int);

int main()
{
    int arrSize;
    cout << "Enter the size of the array: ";
    cin >> arrSize;
    while (arrSize < 0)
    {
        cout << "The size of the array must be greater than 1.\n";
        cout << "Enter the size of the array: ";
        cin >> arrSize;
    }

    int numbers[arrSize];
    acceptNumbers(numbers, arrSize);

    int answer;
    answer = findSecondLargest(numbers, arrSize);

    displayResult(numbers, arrSize, answer);
}

/**
 * This function will accept the numbers from the user.
 */
void acceptNumbers(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> nums[i];
    }
}

/**
 * This function will find the second largest number
 * from the set of given numbers.
 */
int findSecondLargest(int nums[], int size)
{
    int counter;
    int secondLargest;
    for (int i = 0; i < size; i++)
    {
        counter = 0;
        secondLargest = nums[i];
        for (int j = 0; j < size; j++)
        {
            if (secondLargest < nums[j])
                counter++;
        }
        if (counter == 1)
            break;
    }
    return secondLargest;
}

/**
 * This function will display the result.
 */
void displayResult(int nums[], int size, int ans)
{
    cout << "The second largest number form the set:\n";
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "Second largest number: " << ans << endl;
}