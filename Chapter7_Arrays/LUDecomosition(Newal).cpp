/*
**************************************
** This program solves an equation  **
** using LU decomposition method    **
** This solution works on c++11     **
**************************************
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to perform LU decomposition
void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Initialize L and U matrices
    L = vector<vector<double>>(n, vector<double>(n, 0.0));
    U = vector<vector<double>>(n, vector<double>(n, 0.0));

    // LU decomposition
    for (int i = 0; i < n; i++) {
        // Upper triangular matrix
        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular matrix
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal elements of L are 1
            else {
                double sum = 0.0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to solve a system of linear equations using LU decomposition
vector<double> solveSystem(const vector<vector<double>>& L, const vector<vector<double>>& U, const vector<double>& B) {
    int n = L.size();

    vector<double> y(n, 0.0);
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (B[i] - sum) / L[i][i];
    }

    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}

// Function to display a matrix
void displayMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            cout << element << "\t";
        }
        cout << "\n";
    }
}

void displaySolution(vector<vector<double>> L, vector<vector<double>> U, vector<double> B)
{
	vector<double> solution = solveSystem(L, U, B);
    // Print the solution
    cout << "\nSolution:\n";
    for (int i = 0; i < solution.size(); i++) {
        cout << "x" << i + 1 << " = " << solution[i] << "\n";
    }
}

int main() {
    // Example usage
    vector<vector<double>> A = {{4, -1, 2}, {-1, 2, 3}, {5, -7, 9}};
	vector<double> B = {15, 5, 8};

    vector<vector<double>> L, U;
    luDecomposition(A, L, U);

    // Display the matrices
    cout << "Lower Triangular Matrix (L):\n";
    displayMatrix(L);

    cout << "\nUpper Triangular Matrix (U):\n";
    displayMatrix(U);
	
	displaySolution(L,U,B);
    

    return 0;
}



