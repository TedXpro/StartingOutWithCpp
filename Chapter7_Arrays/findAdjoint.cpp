/*This program will find the adjoint of a given matrix.*/
#include <iostream>
#include <vector>

using namespace std;

// GLOBAL CONSTANTS
int ROW = 3;
int COL = 3;

vector<vector<int>> acceptMatrix();
vector<vector<int>> findCofactor(vector<vector<int>>);
vector<vector<int>> findNums(vector<vector<int>>, int, int);
int findDeterminants(vector<vector<int>>);
vector<vector<int>> findTranspose(vector<vector<int>>);
void displayAdjoint(vector<vector<int>>, vector<vector<int>>);

int main()
{
    vector<vector<int>> matrix;
    matrix = acceptMatrix();

    vector<vector<int>> cofactor;
    cofactor = findCofactor(matrix);

    vector<vector<int>> adjoint;
    adjoint = findTranspose(cofactor);

    displayAdjoint(matrix, adjoint);
}

/**
 * This function will accept the elements of the matrix from the user.
 */
vector<vector<int>> acceptMatrix()
{
    vector<vector<int>> numbers;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> nums;
        for (int j = 0; j < COL; j++)
        {
            int n;
            cout << "Enter element #" << i << " " << j << ": ";
            cin >> n;
            nums.push_back(n);
        }
        numbers.push_back(nums);
    }
    return numbers;
}

/**
 * This function will find the cofactor of the matrix.
 *
 * @param cofactor is the matrix that holds the cofactor of the matrix.
 *
 * @return the cofactor of the given matrix.
 */
vector<vector<int>> findCofactor(vector<vector<int>> matrice)
{
    vector<vector<int>> cofactor;
    vector<vector<int>> co;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> rowVector;
        for (int j = 0; j < COL; j++)
        {
            co = findNums(matrice, i, j);
            if ((i + j) % 2 == 0)
                rowVector.push_back(findDeterminants(co));
            else
                rowVector.push_back(-findDeterminants(co));
        }
        cofactor.push_back(rowVector);
    }
    return cofactor;
}

/**
 * This function will find the two by two matrix.
 *
 * @param matrice holds the elements.
 * @param rows will hold the ith element.
 * @param cols will hold the jth element.
 *
 * @return a 2 by 2 matrix from matrice.
 */
vector<vector<int>> findNums(vector<vector<int>> matrice, int rows, int cols)
{
    vector<vector<int>> nums;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> rowVector;
        for (int j = 0; j < COL; j++)
        {
            if (i == rows || j == cols)
                continue;
            else
                rowVector.push_back(matrice[i][j]);
        }
        if (rowVector.size() != 0)
            nums.push_back(rowVector);
    }
    return nums;
}

/**
 * This function will find the determinant of a matrix.
 *
 * @param det will hold the 2 by 2 matrix.
 *
 * @return the determinant of the 2 by 2 matrix.
 */
int findDeterminants(vector<vector<int>> det)
{
    int determinant;
    determinant = ((det[0][0] * det[1][1]) - (det[1][0] * det[0][1]));
    return determinant;
}

/**
 * This function will find the transpose of the cofactor.
 *
 * @param
 */
vector<vector<int>> findTranspose(vector<vector<int>> cofactor)
{
    vector<vector<int>> transpose;
    for (int i = 0; i < ROW; i++)
    {
        vector<int> trans;
        for (int j = 0; j < COL; j++)
        {
            trans.push_back(cofactor[j][i]);
        }
        transpose.push_back(trans);
    }
    return transpose;
}

/**
 * This function will display the adjoint of the matrix.
 *
 * @param adjoint is the matrix that holds the adjoint of the given matrix.
 */
void displayAdjoint(vector<vector<int>> matrix, vector<vector<int>> adjoint)
{
    cout << "\t   ANSWER:\n";
    cout << "Matrix\t\t\tAdjoint\n";
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << matrix[i][j] << " ";

        cout << "\t\t\t";
        for (int j = 0; j < COL; j++)
            cout << adjoint[i][j] << " ";

        cout << endl;
    }
}