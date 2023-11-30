/*
**************************************
** This program solves an equation  **
** using GaussJacobi method         **
** This solution works on c++11     **
**************************************
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_ITERATIONS = 100;
const double TOLERANCE = 1e-2;

/**
 * This function prints the Solution vector.
 */
void printVector(const vector<double> &vec)
{
    for (double element : vec)
    {
        cout << element << "\t";
    }
    cout << endl;
}

// /**
//  *
//  */
// void printMatrix(const vector<vector<double>> &matrix)
// {
//     for (const auto &row : matrix)
//     {
//         for (double element : row)
//         {
//             cout << element << "\t";
//         }
//         cout << endl;
//     }
// }

vector<double> gaussJacobi(const vector<vector<double>> &A, const vector<double> &B, int maxIterations, double tolerance)
{
    int n = A.size();
    vector<double> X(n, 0.0); // Initial guess

    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        vector<double> newX(n, 0.0);

        for (int i = 0; i < n; ++i)
        {
            double sum = 0.0;

            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                    sum += A[i][j] * X[j];
            }

            newX[i] = (B[i] - sum) / A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; ++i)
            error += abs(newX[i] - X[i]);

        if (error < tolerance)
        {
            cout << "Converged in " << iteration + 1 << " iterations." << endl;
            return newX;
        }

        X = newX;
    }

    cout << "Did not converge within the specified number of iterations." << endl;
    return X;
}

/**
 * This method accepts the coefficient for the set of equations.
*/
vector<vector<double>> acceptNumbers()
{
    vector<vector<double>> numbers;
    for (int i = 0; i < 3; i++)
    {
        vector<double> nums;
        int n;
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter the coefficient of x" << j + 1 << " for equation " << i + 1 << ": ";
            cin >> n;
            nums.push_back(n);
        }
        numbers.push_back(nums);
    }
    return numbers;
}

/**
 * This method accepts the solution vector fro the given set of equations.
*/
vector<double> acceptSolutions()
{
    vector<double> num;
    for (int i = 0; i < 3; i++)
    {
        int n;
        cout << "Enter the solution for equation " << i + 1 << ": ";
        cin >> n;
        num.push_back(n);
    }
    return num;
}

int main()
{
    // Example system of linear equations:
    // 10x + 3y + z = 14
    // 2x + -10y + 3z = -5
    // 1x + 3y + 10z = 14

    // vector<vector<double>> A = {
    //     {10, 3, 1},
    //     {2, -10, 3},
    //     {1, 3, 10}};

    // vector<double> B = {14, -5, 14};

    vector<vector<double>> A = acceptNumbers();
    vector<double> B = acceptSolutions();

    vector<double> solution = gaussJacobi(A, B, MAX_ITERATIONS, TOLERANCE);

    cout << "Solution:" << endl;
    printVector(solution);

    return 0;
}
