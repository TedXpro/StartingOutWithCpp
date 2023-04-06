#include <iostream>
#include "Date.h"

using namespace std;

void Date::displayDate()
{
    cout << month << "/" << date << "/" << year << endl;
}

void Date::displayLongDate()
{
    determineMonth();
    cout << date << ", " << year << endl;
}

void Date::displayLongDate2()
{
    cout << date << " ";
    determineMonth();
    cout << year << endl;
}