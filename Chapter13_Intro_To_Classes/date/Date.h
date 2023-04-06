#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
private:
    int date;
    int month;
    int year;
    void determineMonth()
    {
        switch (month)
        {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        default:
            cout << "December ";
            break;
        }
    }

public:
    Date(int d, int m, int y)
    {
        date = d;
        month = m;
        year = y;
    }
    void displayDate();
    void displayLongDate();
    void displayLongDate2();
};

#endif