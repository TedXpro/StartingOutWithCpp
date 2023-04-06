#ifndef COIN_H
#define COIN_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Coin
{
private:
    string sideUp;
    int random()
    {
        int side = 1 + (rand() % 2);
        return side;
    }
public:
    Coin()
    {
        srand(time(NULL));
        int s = random();
        if (s == 1)
            sideUp = "HEAD";
        else
            sideUp = "TAIL";
    }
    void toss();
    string getSideUp() const
    {
        return sideUp;
    }
};

#endif