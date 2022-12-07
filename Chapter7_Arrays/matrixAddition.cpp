#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows of the matrix: ";
    cin >> rows;
    while (rows <= 1)
    {
        cout << "Enter a number greater than 1: ";
        cin >> rows;
    }
    cout << "Enter the number of cols of the matrix: ";
    cin >> cols;
    while (cols <= 1)
    {
        cout << "Enter a number greater than 1: ";
        cin >> cols;
    }

    int matrix1[rows][cols], matrix2[rows][cols];
    int sum[rows][cols];

    // Accepting elemtns of the first matrix
    cout << "Enter the elements of the first matrix." << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter the " << i << " " << j << " element: ";
            cin >> matrix1[i][j];
        }
    }

    // Accepting elements of the second matrix
    cout << "Enter the elements of the second matrix." << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter the " << i << " " << j << " element: ";
            cin >> matrix2[i][j];
        }
    }

    // Adding each corresponding elements of the two matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            sum[i][j] = (matrix1[i][j] + matrix2[i][j]);
    }

    // displaying the elements of the Sum Matrix
    cout << "The sum of the two matrix is " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << sum[i][j] << "  ";
        }
        cout << endl;
    }
}
