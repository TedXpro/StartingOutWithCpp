#include <iostream>

using namespace std;

int main()
{
    double meal_cost = 88.67, taxed_bill, before_tip, tipped_bill, total_bill;
    const double tax = 0.0675, tip = 0.2;

    taxed_bill = meal_cost*tax;
    before_tip = meal_cost + taxed_bill;
    tipped_bill = before_tip *tip;
    total_bill = meal_cost + taxed_bill + tipped_bill;

    cout << "meal cost " << meal_cost << endl;
    cout << "tax " << taxed_bill;
    cout << "\ntip " << tipped_bill << endl;  
    cout << "the bill for tonight is " << total_bill << endl;

    return 0;
}