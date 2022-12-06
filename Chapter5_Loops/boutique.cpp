#include <iostream>

using namespace std;

int main () 
{
    double price_1 = 15.95, price_2 = 24.95, price_3 = 6.95, price_4 = 12.95, price_5 = 3.95, taxed, total, sub_total;
    const double tax = 0.07;

    sub_total = price_1 + price_2 + price_3 + price_4 +price_5;
    taxed = sub_total*tax;
    total = sub_total + taxed;

    cout << "the price of the items purchased are: " << endl;  
    cout << price_1 << endl << price_2 << endl << price_3 <<endl << price_4 <<endl << price_5 << endl;
    cout << "the price before tax is " << sub_total <<endl;
    cout << "the amount of tax is " << tax << "\nthe taxed amount is " << taxed <<endl;
    cout << "the total amount of the purchase is " << total;


    return 0;
}