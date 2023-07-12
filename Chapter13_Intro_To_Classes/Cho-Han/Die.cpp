#include <iostream> 
#include <ctime>
#include "Die.h"

using namespace std;

Die::Die(int numSides)
{
    unsigned seed = time(0);
    
    srand(seed);

    sides = numSides;

    roll();
}

void Die::roll()
{
    const int MIN_VALUE = 1;

    value = (rand() % (sides - MIN_VALUE + 1) + MIN_VALUE);
}