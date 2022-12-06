#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double volume, radius, height;
    const double pi = 3.141592;

    cout << "This program will tell you the volume of\n";
    cout << "a cylinder-shaped fuel tank.\n";
    cout << "How tall is the tank? ";
    cin >> height;
    cout << "What is the radius of the tank? ";
    cin >> radius;

    volume = pi * pow(radius, 2.0) * height;

    cout << "The volume of the tank is " << volume <<endl;
}