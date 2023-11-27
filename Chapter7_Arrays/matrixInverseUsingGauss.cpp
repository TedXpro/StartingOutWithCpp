#include <iostream>
#include <vector>

// Function to print a matrix
void printMatrix(const std::vector<std::vector<double>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (double value : row)
        {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

// Function to perform Gaussian elimination for finding the inverse
void invertMatrix(std::vector<std::vector<double>> &matrix)
{
    const int n = matrix.size();
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));

    // Augment the matrix with the identity matrix
    for (int i = 0; i < n; ++i)
    {
        augmentedMatrix[i][i + n] = 1.0;
        for (int j = 0; j < n; ++j)
        {
            augmentedMatrix[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination
    for (int i = 0; i < n; ++i)
    {
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j)
        {
            augmentedMatrix[i][j] /= pivot;
        }
        for (int k = 0; k < n; ++k)
        {
            if (k != i)
            {
                double factor = augmentedMatrix[k][i];
                for (int j = 0; j < 2 * n; ++j)
                {
                    augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                }
            }
        }
    }

    // Copy the right half (inverse) of the augmented matrix back to the original matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = augmentedMatrix[i][j + n];
        }
    }
}

int main()
{
    // Example usage for a 3x3 matrix
    std::vector<std::vector<double>> matrix = {
        {2, 1, 3},
        {1, 0, 2},
        {4, 1, 8}};

    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix);

    invertMatrix(matrix);

    std::cout << "\nInverse matrix:" << std::endl;
    printMatrix(matrix);

    return 0;
}
