#include <iostream>
#include "Grade.h"

using namespace std;

int main()
{
    double score;

    cout << "Enter your numeric Score: ";
    cin >> score;

    while (score > 100 || score < 0)
    {
        cout << "The Numeric Score must be between 0 - 100!!!!\n";
        cout << "Please Enter again: ";
        cin >> score;
    }

    Grade grade(score);

    cout << "The letter Grade for the Score "
         << grade.getScore() << " is: "
         << grade.getLetterScore() << endl;
}