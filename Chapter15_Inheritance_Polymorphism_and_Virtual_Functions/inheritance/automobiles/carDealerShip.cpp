#include <iostream>
#include "Car.h"
#include "Suv.h"
#include "PickUps.h"

using namespace std;

int main()
{
    Car car1("BMW", 2018, 50000, 9000000, 4);
    Car car2("Tesla", 2019, 40000, 10000000, 4);
    Car car3("Mercedes EQS", 2019, 38000, 12000000, 4);

    PickUp pickUp1("Rivian R2", 2020, 26000, 8500000, "Four Wheeled");
    PickUp pickUp2("Revo", 2015, 87000, 7000000, "Four Wheeled");

    Suv suv1("V8", 2018, 60000, 9000000, 7);

    cout << "The Cars that are in the inventory are:\n";
    cout << car1.getYearModel() << " " << car1.getMake() << " with "
         << car1.getDoors() << " doors and " << car1.getMileage() << " miles.\n";
    cout << "Price: " << car1.getPrice() << endl;
    cout << car2.getYearModel() << " " << car2.getMake() << " with "
         << car2.getDoors() << " doors and " << car2.getMileage() << " miles.\n";
    cout << "Price: " << car2.getPrice() << endl;
    cout << car3.getYearModel() << " " << car3.getMake() << " with "
         << car3.getDoors() << " doors and " << car3.getMileage() << " miles.\n";
    cout << "Price: " << car3.getPrice() << endl;

    cout << "The PickUps that are in the inventory are:\n";
    cout << pickUp1.getYearModel() << " " << pickUp1.getMake() << " with "
         << pickUp1.getType() << " wheeled dive type and " << pickUp1.getMileage() << " miles.\n";
    cout << "Price: " << pickUp1.getPrice() << endl;
    cout << pickUp2.getYearModel() << " " << pickUp2.getMake() << " with "
         << pickUp2.getType() << " wheeled dive type and " << pickUp2.getMileage() << " miles.\n";
    cout << "Price: " << pickUp2.getPrice() << endl;

    cout << "The SUV's that are in the inventory are:\n";
    cout << suv1.getYearModel() << " " << suv1.getMake() << " with "
         << suv1.getPassengers() << " Passenget Capacity and " << suv1.getMileage() << " miles.\n";
    cout << "Price: " << suv1.getPrice() << endl;
}