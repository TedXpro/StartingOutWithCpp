// #include <iostream>
// #include <vector>

// // Function to print a matrix
// void printMatrix(const vector<vector<double>> &matrix)
// {
//     for (const auto &row : matrix)
//     {
//         for (double value : row)
//         {
//             cout << value << "\t";
//         }
//         cout << endl;
//     }
// }

// // Function to perform Gaussian elimination for finding the inverse
// void invertMatrix(vector<vector<double>> &matrix)
// {
//     const int n = matrix.size();
//     vector<vector<double>> augmentedMatrix(n, vector<double>(2 * n, 0.0));

//     // Augment the matrix with the identity matrix
//     for (int i = 0; i < n; ++i)
//     {
//         augmentedMatrix[i][i + n] = 1.0;
//         for (int j = 0; j < n; ++j)
//         {
//             augmentedMatrix[i][j] = matrix[i][j];
//         }
//     }

//     // Perform Gaussian elimination
//     for (int i = 0; i < n; ++i)
//     {
//         double pivot = augmentedMatrix[i][i];
//         for (int j = 0; j < 2 * n; ++j)
//         {
//             augmentedMatrix[i][j] /= pivot;
//         }
//         for (int k = 0; k < n; ++k)
//         {
//             if (k != i)
//             {
//                 double factor = augmentedMatrix[k][i];
//                 for (int j = 0; j < 2 * n; ++j)
//                 {
//                     augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
//                 }
//             }
//         }
//     }

//     // Copy the right half (inverse) of the augmented matrix back to the original matrix
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             matrix[i][j] = augmentedMatrix[i][j + n];
//         }
//     }
// }

// int main()
// {
//     // Example usage for a 3x3 matrix
//     vector<vector<double>> matrix = {
//         {1, 2, 5},
//         {1, -1, 3},
//         {3, -6, -1}};

//     cout << "Original matrix:" << endl;
//     printMatrix(matrix);

//     invertMatrix(matrix);

//     cout << "\nInverse matrix:" << endl;
//     printMatrix(matrix);

//     return 0;
// }
