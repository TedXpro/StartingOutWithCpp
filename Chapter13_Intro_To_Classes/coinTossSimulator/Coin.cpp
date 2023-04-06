#include <iostream>
#include "Coin.h"

void Coin::toss()
{
    int side = random();
    if (side == 1)
        sideUp = "HEAD";
    else
        sideUp = "TAIL";
}