#include <string>
#include "Grade.h"

using namespace std;

string Grade::getLetterScore() const
{
    string letterGrade;
    if (score >= 90)
        letterGrade = "A+";
    else if (score >= 83 && score < 90)
        letterGrade = "A";
    else if (score >= 80 && score < 83)
        letterGrade = "A-";
    else if (score >= 75 && score < 80)
        letterGrade = "B+";
    else if (score >= 70 && score < 75)
        letterGrade = "B";
    else if (score >= 65 && score < 70)
        letterGrade = "B-";
    else if (score >= 60 && score < 65)
        letterGrade = "C";
    else if (score >= 50 && score < 60)
        letterGrade = "D";
    else
        letterGrade = "F";

    return letterGrade;
}