/*Chapter 7 - Programming Challenge Question 9: Pay Roll.
page 450
This program takes in hours and hourly payrate and calculates
their wages.*/
#include <iostream>

using namespace std;

int main()
{
    const int arraySize = 7;
    long empId [arraySize] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};

    int hours[arraySize];
    double payRate [arraySize];
    double wages[arraySize];

    for (int index = 0; index < arraySize; index++)
    {
        cout << "Enter the hours worked by employee " << empId[index] << ": ";
        cin >> hours[index];
        cout << "Enter the pay rate of employee " << empId[index] << ": ";
        cin >> payRate[index];
    }

    for (int index = 0; index < arraySize; index++)
    {
        wages[index] = (hours[index] * payRate[index]);
    }

    for (int index = 0; index < arraySize; index++)
    {
        cout << empId[index] << ": " << wages[index] << endl;
    }
}