#include <iostream>

using namespace std;

void moveDisks(int, char, char, char);

int main()
{
    const char fromPeg = 'A', tempPeg = 'B', toPeg = 'C';
    int numberOfDisks;
    cout << "Enter the number of Disks to move: ";
    cin >> numberOfDisks;


    moveDisks(numberOfDisks, fromPeg, toPeg, tempPeg);
}

/**
 * This function will output the steps to move the disks
 * from A to C using B as a temporary peg.
 * 
 * @param numofD holds the number of pegs to move.
*/
void moveDisks(int numofD, char fromPeg, char toPeg , char tempPeg)
{
    if (numofD > 0)
    {
        moveDisks(numofD - 1, fromPeg, tempPeg, toPeg);
        cout << "Move a Disk from PEG " << fromPeg << " to " << toPeg << endl;
        moveDisks(numofD - 1, tempPeg, toPeg, fromPeg);
    }
}