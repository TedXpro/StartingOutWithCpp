#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>

using namespace std;

class Automobile
{
private:
    string make;
    int yearModel;
    int mileage;
    double price;
public:
    Automobile()
    {
        make = "";
        yearModel = 0;
        mileage = 0;
        price = 0.0;
    }
    Automobile(string m, int y, int mi, double p)
    {
        make = m;
        yearModel = y;
        mileage = mi;
        price = p;
    }

    // void setMake(string m)
    // {
    //     make = m;
    // }

    // void setYearModel(int y)
    // {
    //     yearModel = y;
    // }

    // void setMileage(int m)
    // {
    //     mileage = m;
    // }

    // void setPrice(double p)
    // {
    //     price = p;
    // }

    string getMake() const
    {
        return make;
    }

    int getYearModel() const
    {
        return yearModel;
    }

    int getMileage() const
    {
        return mileage;
    }

    double getPrice() const
    {
        return price;
    }

};

#endif