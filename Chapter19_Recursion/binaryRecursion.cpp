#include <iostream>

using namespace std;

const int SIZE = 20;
int binaryRecursion(int[], int, int, int);

int main()
{
    int tests[SIZE] = {101, 142, 147, 189, 199, 207, 222,
                       234, 289, 296, 310, 319, 388, 394,
                       417, 429, 447, 521, 536, 600};
    int value;
    cout << "Enter the value to be searched: ";
    cin >> value;

    int position = binaryRecursion(tests, 0, SIZE - 1, value);

    if (position == -1)
        cout << "The number " << value << " does not exist in the list.\n";
    else
        cout << "The number " << value << " is at position " << position << endl;
}

/**
 * This function will find a number in an array.
 *
 * @param arr[] holds the array of the numbers.
 * @param first holds the first position of an array.
 * @param last holds the last position of the array.
 * @param val holds the value to be searched.
 */
int binaryRecursion(int arr[], int first, int last, int val)
{
    int middle;
    if (first > last)
        return -1;
    middle = (first + last) / 2;

    if (arr[middle] == val)
        return middle;
    else if (arr[middle] > val)
        return binaryRecursion(arr, first, middle - 1, val);
    else
        return binaryRecursion(arr, middle + 1, last, val);
}