/*
**************************************
** This program solves an equation  **
** using NewtonRalphsonMethod method**
** This solution works on c++11     **
**************************************
*/

#include <iostream>
#include <cmath>
using namespace std;

/**
 * This method defines the first equation.
 */
double equationA(double x, double y) {
    return x * x + y * y - 16;
}

/**
 * This method defines the second equation.
 */
double equationB(double x, double y) {
    return x - y + 2;
}

/**
 * This method differentiates X from the second equation.
 */
double diff_X_fromEquationA(double x, double y)
{
    return 2 * x;
}

/**
 * This method differentiates Y from the second equation.
 */
double diff_Y_fromEquationA(double x, double y) {
    return 2 * y;
}

/**
 * This method differentiates X from the second equation.
 */
double diff_X_fromEquationB(double x, double y) {
    return 1;
}

/**
 * This method differentiates Y from the second equation.
 */
double diff_Y_fromEquationB(double x, double y) {
    return -1;
}

// Define the Newton-Raphson method
void newtonRaphsonMethod(double x, double y) {
    double epsilon = 0.0001;
    double dx, dy, det, inv_det, new_x, new_y;

    do {
        dx = -(equationA(x, y) * diff_Y_fromEquationB(x, y) - equationB(x, y) * diff_Y_fromEquationA(x, y));
        dy = -(equationB(x, y) * diff_X_fromEquationA(x, y) - equationA(x, y) * diff_X_fromEquationB(x, y));

        det = diff_X_fromEquationA(x, y) * diff_Y_fromEquationB(x, y) - diff_Y_fromEquationA(x, y) * diff_X_fromEquationB(x, y);
        inv_det = 1 / det;

        new_x = x + dx * inv_det;
        new_y = y + dy * inv_det;

        x = new_x;
        y = new_y;
    } while (abs(dx) > epsilon && abs(dy) > epsilon);

    cout << "Solution: x = " << x << ", y = " << y << endl;
}

int main() {
    double initial_x = 1.0;
    double initial_y = 1.0;

    newtonRaphsonMethod(initial_x, initial_y);

    return 0;
}