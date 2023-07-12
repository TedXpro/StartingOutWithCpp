#include "Dealer.h"
#include "Die.h"
#include <iostream>
#include <string>

using namespace std;

void Dealer::rollDice()
{
    die1.roll();
    die2.roll();

    die1Value = die1.getValue();
    die2Value = die2.getValue();
}

string Dealer::getChoOrHan()
{
    string result;

    int sum = die1Value + die2Value;

    if (sum % 2 == 0)
        result = "Cho (even)";
    else
        result = "Han(odd)";

    return result;
}