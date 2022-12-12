/*This program is focused on selection sorting using a case
study from the book Starting Out With C++.*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * This function calculates the sales of the products.
 */
void calSales(const int units[], const double prices[], double sales[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        sales[i] = units[i] * prices[i];
}

/**
 * This fucntion sorts the sales values in descending order.
 */
void sortSales(int units[], double prices[], double sales[], int id[], int size)
{
    int minIndex, i;
    int maxValue, unit, price, proId;

    for (i = 0; i < (size - 1); i++)
    {
        minIndex = i;
        maxValue = sales[i];

        for (int j = minIndex + 1; j < size; j++)
        {
            if (sales[j] > maxValue)
            {
                maxValue = sales[j];
                minIndex = j;
            }
        }
        // swaps the sales values.
        sales[minIndex] = sales[i];
        sales[i] = maxValue;

        // swaps the units value.
        double temp = units[minIndex];
        units[minIndex] = units[i];
        units[i] = temp;

        // swaps the prices value.
        temp = prices[minIndex];
        prices[minIndex] = prices[i];
        prices[i] = temp;

        // swaps the id value.
        temp = id[minIndex];
        id[minIndex] = id[i];
        id[i] = temp;
    }
}

/**
 * This function calculates the total sales and units.
 */
void calTotal(int units[], double sales[], double total[2], int size)
{
    double totalUnits = 0;
    double totalSales = 0;
    for (int i = 0; i < size; i++)
    {
        totalSales += sales[i];
        totalUnits += units[i];
    }
    total[0] = totalUnits;
    total[1] = totalSales;
}

/**
 * This function displays the sales, units, id, prices, total units sold, and total sales.
 */
void display(int id[], int units[], double prices[], double sales[], double total[], int size)
{
    cout << "Product Number"
         << "\t\tUnit sold"
         << "\t\tUnitPrice"
         << "\t\tsales" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << setprecision(2) << fixed << showpoint;
    for (int i = 0; i < size; i++)
    {
        cout << id[i] << "\t\t\t"
             << units[i] << "\t\t\t"
             << "$" << prices[i] << "\t\t\t"
             << "$" << sales[i] << endl;
    }

    cout << "Total Units sold: " << total[0] << endl;
    cout << "Total Sales: " << total[1] << endl;
}

int main()
{
    int size = 9;
    int id[size] = {914, 915, 916, 917, 918, 919, 920,
                    921, 922};

    int units[size] = {842, 416, 127, 514, 437, 269, 97,
                       492, 212};

    double prices[size] = {12.95, 14.95, 18.95, 16.95, 21.95,
                           31.95, 14.95, 14.95, 16.95};
    double sales[size];

    calSales(units, prices, sales, size);
    sortSales(units, prices, sales, id, size);
    double total[2];
    calTotal(units, sales, total, size);
    display(id, units, prices, sales, total, size);
}