/*Programming Challenge 12:Coin Toss Simulator*/
#include <iostream>
#include "Coin.h"

using namespace std;

int main()
{
    Coin nickel;
    cout << "Current Position of the coin: ";
    cout << nickel.getSideUp() << endl;

    int head = 0, tail = 0;
    for (int i = 1; i <= 20; i++)
    {
        nickel.toss();
        cout << nickel.getSideUp() << endl;
        if (nickel.getSideUp() == "HEAD")
            head++;
        else
            tail++;
    }
    cout << "The number of time Head came up is: " << head << endl;
    cout << "And the number of times Tails came up is: " << tail << endl;
}