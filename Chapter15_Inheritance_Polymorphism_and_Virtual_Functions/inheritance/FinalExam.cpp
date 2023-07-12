#include <iostream>
#include "Final.h"

using namespace std;

int main()
{
    int questions;
    int missed;

    cout << "How many questions are on the final exam: ";
    cin >> questions;
    cout << "How many questions did the student miss: ";
    cin >> missed;

    Final test(questions, missed);

    cout << "Each question counts " << test.getPointsEach()
         << " points.\n";
    cout << "The exam score is " << test.getScore() << endl;
    cout << "The exam grade is " << test.getLetterScore() << endl;

    return 0;
}