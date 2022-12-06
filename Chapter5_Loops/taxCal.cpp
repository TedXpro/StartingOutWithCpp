#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    const double state_tax = 0.04, country_tax = 0.02, num = 1.06;  
    double total_collected, sales, country_sales_tax, state_sales_tax, total_sales_tax;
    string mon;

    cout << "enter the month: ";
    cin >> mon;
    cout << "enter the amount of salse made: ";
    cin >> total_collected;

    sales = total_collected / num;
    country_sales_tax = sales * country_tax;
    state_sales_tax = sales * state_tax;
    total_sales_tax = state_sales_tax + country_sales_tax;

    cout << "Month: " << mon;
    cout << "------------------\n";
    cout << "Total Collected:    $" << setprecision(2) << fixed << total_collected << endl;
    cout << "Sales:              $" << setprecision(2) << fixed << sales << endl;
    cout << "Country sales tax:  $" << setprecision(2) << fixed << country_sales_tax << endl;
    cout << "State Sales tax:    $" << setprecision(2) << fixed << state_sales_tax << endl;
    cout << "Total Sales Taz:    $" << setprecision(2) << fixed << total_sales_tax << endl;

    return 0;
}