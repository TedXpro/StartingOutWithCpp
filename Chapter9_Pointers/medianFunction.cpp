/*Programming Challenge - Chapter 9, Question 9, Page 546.
This Program accepts a set of integers and find the median.*/
#include <iostream>

using namespace std;

int *acceptNumbers(int);
int *sortNumbers(int *, int);
double findMedian(int *, int);
void displayAnswer(int *, int, int);

int main()
{
    char ch;
    do
    {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        int *arr = nullptr;
        arr = acceptNumbers(size);
        arr = sortNumbers(arr, size);

        double answer;
        answer = findMedian(arr, size);

        displayAnswer(arr, size, answer);

        delete[] arr;
        arr = nullptr;

        cout << "\nDo you want to continue (Y/n): ";
        cin >> ch;
    } while (ch != 'N' & ch != 'n');
}

/**
 * This Function will accept the elements of the array.
 */
int *acceptNumbers(int n)
{
    int *numbers = nullptr;
    numbers = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> numbers[i];
    }
    return numbers;
}

/**
 * This Function will sort the numbers array in ascending order.
 */
int *sortNumbers(int *nums, int n)
{
    int minValue, minIndex;

    for (int i = 0; i < (n - 1); i++)
    {
        minValue = nums[i];
        minIndex = i;
        for (int j = i + 1; j < n; j++)
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
    return nums;
}

/**
 * This function will find the median from the set of given numbers.
 */
double findMedian(int *nums, int n)
{
    double ans;
    if (n % 2 == 0)
    {
        int element, nextElement;
        element = (n / 2) - 1;
        nextElement = (n / 2);

        ans = (nums[element] + nums[nextElement]) / 2.0;
    }
    else
    {
        int element;
        element = n / 2;

        ans = nums[element];
    }
    return ans;
}

/**
 * This Function will display the median along with the given set in ascending order.
 */
void displayAnswer(int *nums, int n, int ans)
{
    cout << "The median of the numbers- {";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << nums[i] << "} is:" << endl;
        else
            cout << nums[i] << ", ";
    }
    cout << "Median = " << ans << endl;
}