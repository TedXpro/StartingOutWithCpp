#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

// Function to perform LU decomposition
void luDecomposition(const vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)
{
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {
        // U matrix
        for (int k = i; k < n; ++k)
        {
            double sum = 0.0;
            for (int j = 0; j < i; ++j)
            {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // L matrix
        for (int k = i; k < n; ++k)
        {
            if (i == k)
            {
                L[i][i] = 1; // Diagonal elements of L are always 1
            }
            else
            {
                double sum = 0.0;
                for (int j = 0; j < i; ++j)
                {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to solve a linear system using LU decomposition
vector<double> solveLinearSystemLU(const vector<vector<double>> &A, const vector<double> &B)
{
    int n = A.size();

    // Initialize L, U, and Y matrices
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(n, vector<double>(n, 0.0));
    vector<double> Y(n, 0.0);

    // Perform LU decomposition
    luDecomposition(A, L, U);

    // Solve LY = B for Y
    for (int i = 0; i < n; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < i; ++j)
        {
            sum += L[i][j] * Y[j];
        }
        Y[i] = B[i] - sum;
    }

    // Solve UX = Y for X
    vector<double> X(n, 0.0);
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j)
        {
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }

    return X;
}

// Function to print a vector
void printVector(const vector<double> &vec)
{
    for (double element : vec)
    {
        cout << element << "\t";
    }
    cout << endl;
}

// Function to calculate the Jacobian matrix of a system of nonlinear equations
vector<vector<double>> calculateJacobian(const vector<function<double(const vector<double> &)>> &equations, const vector<double> &x, double h = 1e-6)
{
    int n = equations.size();
    vector<vector<double>> jacobian(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // Perturb the j-th variable
            vector<double> x_perturbed = x;
            x_perturbed[j] += h;

            // Calculate the partial derivative using central differencing
            jacobian[i][j] = (equations[i](x_perturbed) - equations[i](x)) / h;
        }
    }

    return jacobian;
}

// Function to solve a system of nonlinear equations using the Newton-Raphson method
vector<double> newtonRaphson(const vector<function<double(const vector<double> &)>> &equations, const vector<double> &initialGuess, double tolerance = 1e-6, int maxIterations = 100)
{
    int n = equations.size();
    vector<double> x = initialGuess;

    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        // Calculate the Jacobian matrix
        vector<vector<double>> jacobian = calculateJacobian(equations, x);

        // Calculate the residual vector
        vector<double> residual(n);
        for (int i = 0; i < n; ++i)
        {
            residual[i] = -equations[i](x);
        }

        // Solve the linear system J * delta_x = -F using LU decomposition
        vector<double> delta_x = solveLinearSystemLU(jacobian, residual);

        // Update the solution
        for (int i = 0; i < n; ++i)
        {
            x[i] += delta_x[i];
        }

        // Check for convergence
        double maxResidual = *max_element(residual.begin(), residual.end());
        if (maxResidual < tolerance)
        {
            cout << "Converged in " << iteration + 1 << " iterations." << endl;
            return x;
        }
    }

    cout << "Did not converge within the specified number of iterations." << endl;
    return x;
}

int main()
{
    // Example system of nonlinear equations:
    //  x^2 + y^2 - 4 = 0
    //  x^2 - y^2 - 1 = 0

    vector<function<double(const vector<double> &)>> equations = {
        [](const vector<double> &x)
        { return x[0] * x[0] + x[1] * x[1] - 4; },
        [](const vector<double> &x)
        { return x[0] * x[0] - x[1] * x[1] - 1; }};

    vector<double> initialGuess = {1.0, 1.0};

    // Solve the system using the Newton-Raphson method
    vector<double> solution = newtonRaphson(equations, initialGuess);

    // Print the solution
    cout << "Solution:" << endl;
    printVector(solution);

    return 0;
}
