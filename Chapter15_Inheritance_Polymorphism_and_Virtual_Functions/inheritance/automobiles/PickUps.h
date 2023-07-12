#ifndef PICKUP_H
#define PICKUP_H
#include "Automobile.h"
#include <string>

using namespace std;

class PickUp : public Automobile
{
private:
    string driveType;

public:
    PickUp() : Automobile()
    {
        driveType = "";
    }

    PickUp(string pickUpMake, int pickUpYear, int pickUpMile, double pickUpPrice,
           string type) : Automobile(pickUpMake, pickUpYear, pickUpMile, pickUpPrice)
    {
        driveType = type;
    }

    string getType() const
    {
        return driveType;
    }
};
#endif