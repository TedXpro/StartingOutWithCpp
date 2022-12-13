/*This program will find a companys product using binary search.*/
#include <iostream>

using namespace std;

const int ARRAYSIZE = 9;

int findProduct(int proNumber[ARRAYSIZE], int number)
{
    int first = 0;
    int last = ARRAYSIZE - 1;
    int middle;
    int position = -1;

    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (proNumber[middle] == number)
        {
            position = middle;
            found = true;
        }
        else if (proNumber[middle] > number)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

void displayInfo(string title[], string description[], double price[], int number)
{
    cout << "Title: " << title[number] << endl;
    cout << "Description: " << description[number] << endl;
    cout << "Price: " << price[number] << endl;
}

int main()
{
    char ch;
    do
    {
        string title[ARRAYSIZE] = {"Six Steps to Leadership",
                                   "Six Steps to Leadership",
                                   "The Road to Excellence",
                                   "Seven Lessons of Quality",
                                   "Seven Lessons of Quality",
                                   "Seven Lessons of Quality",
                                   "Teams Are Made, Not Born",
                                   "Leadership for the Future",
                                   "Leadership for the Future"};

        string description[ARRAYSIZE] = {"Book", "Audio CD", "DVD",
                                         "Book", "Audio CD", "DVD",
                                         "Book", "Book", "Audio CD"};

        int productNumber[ARRAYSIZE] = {914, 915, 916, 917, 918, 919, 920, 921, 922};
        double prices[ARRAYSIZE] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95};

        int product;
        cout << "Enter product number: ";
        cin >> product;

        int result;
        result = findProduct(productNumber, product);

        if (result == -1)
            cout << "Sorry the product you entered is not in the array." << endl;
        else
        {
            displayInfo(title, description, prices, result);
        }

        cout << "Would you like to look up another product? (y/n): ";
        cin >> ch;
    } while (ch != 'N' && ch != 'n');
}