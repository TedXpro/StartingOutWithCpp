/*Programming Challenge 1: Date*/
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    int date, month, year;

    cout << "Enter date: ";
    cin >> date;
    while (date < 1 || date > 31)
    {
        cout << "Enter a correct date 1 - 31: ";
        cin >> date;
    }

    cout << "Enter Month: ";
    cin >> month;
    while (month < 1 || month > 12)
    {
        cout << "Enter a correct Month 1 - 12: ";
        cin >> month;
    }

    cout << "Enter Year: ";
    cin >> year;

    int choice;
    cout << "\t\tMenu\n";
    cout << "1. 12/25/2022\n";
    cout << "2. December 25, 2022\n";
    cout << "3. 25 December 2022\n";
    cout << "\nEnter Your choice: ";
    cin >> choice;

    while (choice > 3 || choice < 1)
    {
        cout << "Enter the correct choice 1 - 3: ";
        cin >> choice;
    }

    Date currentDate (date, month, year);

    if (choice == 1)
        currentDate.displayDate();
    else if (choice == 2)
        currentDate.displayLongDate();
    else
        currentDate.displayLongDate2();
}