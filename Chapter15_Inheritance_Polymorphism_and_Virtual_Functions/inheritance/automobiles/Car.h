#ifndef CAR_H
#define CAR_H
#include "Automobile.h"
#include <string>

using namespace std;

class Car : public Automobile
{
private:
    int numOfDoors;

public:
    Car() : Automobile()
    {
        numOfDoors = 0;
    }

    Car(string carMake, int carYear, int carMile, double carPrice,
        int carDoors) : Automobile(carMake, carYear, carMile, carPrice)
    {
        numOfDoors = carDoors;
    }

    int getDoors() const
    {
        return numOfDoors;
    }
};

#endif