/*This program will find the inverse of a matrix from
a matrix given by the user.*/
#include <iostream>
#include <vector>

using namespace std;

// Global Constant
const int COL = 3;
const int ROW = 3;

void acceptNumbers(int[ROW][COL]);
vector<vector<int>> findNums(int[][COL], int, int);
int findDeterminant(vector<vector<int>>);
void findTranspose(vector<vector<int>>);
void displayResult(vector<vector<int>>, int);

int main()
{
    int matrix[ROW][COL];

    acceptNumbers(matrix);

    // int determinant = 0;
    // vector<vector<int>> n;
    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COL; j++)
    //     {
    //         n = findNums(matrix, i, j);
    //         if ((i + j) / 2 == 0)

    //             determinant += (matrix[i][j] * findDeterminant(n));
    //         else

    //             determinant += (-1 * matrix[i][j] * findDeterminant(n));
    //     }
    //     break;
    // }
    // cout << determinant << endl;

    int determinant;
    int ele1 = (matrix[0][0]) * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
    int ele2 = -(matrix[0][1]) * ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
    int ele3 = (matrix[0][2]) * ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));
    determinant = ele1 + ele2 + ele3;

    if (determinant == 0)
    {
        cout << "The given matrix has no inverse since the determinant is " << determinant << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<int>> det;     // To hold the 2 by 2 matrix.
    vector<vector<int>> adjoint; // To hold the adjoint of the matrix.
    for (int i = 0; i < ROW; i++)
    {
        vector<int> adj; // To hold the row of the adjoint of the matrix.
        for (int j = 0; j < COL; j++)
        {
            det = findNums(matrix, i, j);
            if ((i + j) % 2 == 0)
                adj.push_back(findDeterminant(det));
            else
                adj.push_back(-findDeterminant(det));
        }
        adjoint.push_back(adj);
    }
    findTranspose(adjoint);
    displayResult(adjoint, determinant);
}

/**
 * This function will accept the elements of the matrix.
 *
 * @param nums will hold the matrix elements.
 */
void acceptNumbers(int nums[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << "Enter the " << i << " " << j << " element: ";
            cin >> nums[i][j];
        }
    }
}

/**
 * this function will find the submatrix.
 *
 * @param nums holds the matrix
 * @param rows is the variable for the ith number.
 * @param cols holds the value for the jth number.
 *
 * @return vector of the 2 by 2 matrix.
 */
vector<vector<int>> findNums(int nums[ROW][COL], int rows, int cols)
{
    vector<vector<int>> numbers;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> rowVector;
        for (int j = 0; j < COL; j++)
        {
            if (i == rows || j == cols)
                continue;
            else
                rowVector.push_back(nums[i][j]);
        }
        if (rowVector.size() != 0)
            numbers.push_back(rowVector);
    }
    return numbers;
}

/**
 * This function will find the determinant of a given 2 by 2 matrix.
 *
 * @param numbers holds the 2 by 2 matrix.
 * @return the determinant of the 2 by 2 matrix.
 */
int findDeterminant(vector<vector<int>> numbers)
{
    int det = (numbers[0][0] * numbers[1][1]) - (numbers[1][0] * numbers[0][1]);
    return det;
}

/**
 * This function will find the transpose of the matrix given.
 *
 * @param numbers holds the matrix.
 *
 * @return the transposed matrix.
 */
void findTranspose(vector<vector<int>> transpose)
{
    vector<vector<int>> numbers;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> nums;
        for (int j = 0; j < COL; j++)
            nums.push_back(transpose[i][j]);

        numbers.push_back(nums);
    }

    for (int i = 0; i < ROW; i++)
    {
        vector<int> trans;
        for (int j = 0; j < COL; j++)
            trans.push_back(numbers[j][i]);

        transpose.push_back(trans);
    }
}

/**
 * The function will display the result of the inverse matrix.
 *
 * @param inverse will hold the inverse matrix.
 * @param deter will hold the value of the determinant of the matrix.
 */
void displayResult(vector<vector<int>> inverse, int deter)
{
    cout << "The inverse of the matrix is:\n";
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << inverse[i][j] << "/" << deter << " ";
        cout << endl;
    }
}