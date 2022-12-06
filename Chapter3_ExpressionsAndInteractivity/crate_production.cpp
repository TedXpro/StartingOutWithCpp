#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    const double COST_PER_CUBIC_FOOT = 0.23, CHARGE_PER_CUBIC_FOOT = 0.5;
    double volume, length, width, height, cost, charge, profit;

    cout << "calculating the volume, cost, charge and profit of crates.\n";
    
    cout << "enter the dimension of the crate (in feet):\n";
    cout << "length: ";
    cin >> length;
    cout << "height: ";
    cin >> height;
    cout << "width: ";
    cin >> width;

    volume = height * length * width;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;

    profit = charge - cost;

    cout << "the volume of the crate produced is: " << volume << "cubic feet" << endl;
    cout << "the cost of the crate produced is: " << cost << "birr" << endl;
    cout << "the price of the crate produced is: " << charge  << "birr" << endl;
    cout << "the profit of the crate produced is: " << profit << "birr" << endl;
    
    return 0;
}