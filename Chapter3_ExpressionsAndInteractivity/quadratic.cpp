#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double a, b, c, x1, x2;
    cout << "enter a, b and c from the form of ax^2 + bx + c." << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    x1 = (-b + sqrt((b*b) - (4 * a * c)))/(2*a);
    x2 = (-b - sqrt((b*b) - (4 * a * c)))/(2*a);

    if (isnan(x1) || isnan(x2))
    {
        cout << "The equation has no real root" << endl;
    }
    else if (x1 == x2)
    {
        cout << "The real roots of " << a << "x^2 + " << b << "x + " << c;
        cout << " is " << x1 << endl; 
    }
    else
    {
        cout << "The real roots of " << a << "x^2 + " << b << "x + " << c;
        cout << " are " << x1 << " and " << x2 << endl; 
    }
}