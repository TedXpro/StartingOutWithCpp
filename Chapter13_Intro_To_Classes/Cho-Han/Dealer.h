#ifndef DEALER_H
#define DEALER_H
#include <string>
#include "Die.h"

using namespace std;

class Dealer
{
private:
    Die die1;
    Die die2;
    int die1Value;
    int die2Value;
public:
    Dealer()
    {
        die1Value = 0;
        die2Value = 0;
    }
    void rollDice();
    string getChoOrHan();
    int getDie1Value()
    {
        return die1Value;
    }
    int getDie2Value()
    {
        return die2Value;
    }
};

#endif