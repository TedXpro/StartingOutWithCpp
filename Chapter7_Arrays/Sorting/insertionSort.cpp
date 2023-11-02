#include <iostream>

using namespace std;

void insertionSort(int[], int);
void display(int[], int);

int main()
{
    int size = 8;
    int numbers[size] = {9, 4, 5, 7, 2, 3, 8, 1};

    cout << "Before Sort!\n";
    display(numbers, size);

    insertionSort(numbers, size);
    cout << "After Iteration Sort!\n";
    display(numbers, size);
}

void insertionSort(int  numbers[], int size)
{
    int temp;
    for (int i = 1, j; i < size; i++){
    
        temp = numbers[i];
        cout << temp << endl;
        for (j = i; j > 0 && temp < numbers[j - 1]; j--)
            numbers[j] = numbers[j - 1];
        numbers[j] = temp;
    }
}

void display(int numbers[], int size){
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    cout << endl;
}