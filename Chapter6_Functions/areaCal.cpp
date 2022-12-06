#include <iostream>

using namespace std;

// rectangle area      fuction question2

double getLength()
{
    double length;
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    return length;
}

double getWidth()
{
    double width;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    return width;
}

double getArea(double length, double width)
{
    double area;
    area = length * width;

    return area;
}

void displayMessage(double length, double width, double area)
{
    cout << "The length of the rectangle: " << length << endl;
    cout << "The width of the rectangle: " << width << endl;
    cout << "The area of the rectangle: " << area << endl;
}

int main()
{
    int width, length, area;

    length = getLength();
    width = getWidth();

    area = getArea(length, width);

    displayMessage(length, width, area);

    return 0;
}