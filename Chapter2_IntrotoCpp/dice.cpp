#include <iostream>

using namespace std;

int main ()
{
    const int min = 1 , max = 6;

    int die_1, die_2;

    unsigned seed = time (0);
    srand (seed);
    die_1 = (rand() % ((max - min) + 1)) + min;
    die_2 = (rand() % ((max -min) + 1)) + min;

    cout << die_1 << endl;
    cout << die_2 << endl;
}