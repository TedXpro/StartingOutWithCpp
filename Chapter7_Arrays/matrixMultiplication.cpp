/*This program will take in two matrices from the user,
multiplies the matrices and displays the result*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "\t\tMatrix Multiplication\n";
    cout << "Welcome!!\n";
    cout << "This program multiplies two matrices and returns their product.\n\n";
    int rows_1, cols_1, rows_2, cols_2;

    cout << "Enter the number of rows of the first matrix: ";
    cin >> rows_1;
    cout << "Enter the number of columns of the first matrix: ";
    cin >> cols_1;

    cout << "Enter the number of rows of the second matrix: ";
    cin >> rows_2;
    cout << "Enter the number of columns of the second matrix: ";
    cin >> cols_2;

    while (cols_1 != rows_2)         
    {
        /*For matrix multiplication the number of columns of the first matrix
        and the number of rows of the second matrix MUST be the same.*/

        cout << "The number of columns of the first matrix and the number of rowss of the second matrix must be the same.\n";
        cout << "Enter the number of columns of the first matrix: ";
        cin >> cols_1;
        cout << "Enter the number of rows of the second matrix: ";
        cin >> rows_2;
    }

    int matrix1[rows_1][cols_1], matrix2[rows_2][cols_2], product[rows_1][cols_2];

    // Accept the elements of the first matrix.
    cout << "Enter the elements of the first matrix:\n";
    for (int i = 0; i < rows_1; i++)    //   Controls the rows of the matrix.
    {
        for (int j = 0; j < cols_1; j++)     //    Controls the columns of the matrix.
        {
            cout << "Enter the " << i << " " << j << " element: ";
            cin >> matrix1[i][j];
        }
    }

    // Accept the elements of the second matrix.
    cout << "Enter the elements of the second matrix:\n";
    for (int i = 0; i < rows_2; i++)           //   Controls the rows of the matrix.
    {
        for (int j = 0; j < cols_2; j++)       //   Controls the columns of the matrix.
        {
            cout << "Enter the " << i << " " << j << " element: ";
            cin >> matrix2[i][j];
        }
    }

    // Multiplying the two matrices
    for (int i = 0; i < rows_1; i++)   //  i controls the rows of the first matrix.
    {
        for (int j = 0; j < cols_2; j++)   //  j controls the columns of the second matrix.
        {
            product[i][j] = 0;    //    each element of the product is initiallized first.
            for (int k = 0; k < cols_1; k++)      //  k controls the COLUMNS of the first matrix and the ROWS of the second matrix.
            {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Displaying the product of the two matrices.
    cout << "(";
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    cout << ")";
}