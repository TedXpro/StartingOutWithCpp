#ifndef SUV_H
#define SUV_H
#include <string>
#include "Automobile.h"

using namespace std;

class Suv : public Automobile
{
private:
    int passengers;

public:
    Suv() : Automobile()
    {
        passengers = 0;
    }

    Suv(string suvMake, int suvYear, int suvMile,
        double suvPrice, int numPas) : Automobile(suvMake, suvYear, suvMile, suvPrice)
    {
        passengers = numPas;
    }

    int getPassengers() const
    {
        return passengers;
    }
};

#endif