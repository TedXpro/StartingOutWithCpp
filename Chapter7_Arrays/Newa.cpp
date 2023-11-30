
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
