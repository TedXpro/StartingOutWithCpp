#ifndef GRADE_H
#define GRADE_H

#include <string>

using namespace std;

class Grade
{
private:
    double score;

public:
    Grade()
    {
        score = 0.0;
    }

    Grade(double s)
    {
        score = s;
    }

    void setScore(double s)
    {
        score = s;
    }

    double getScore() const
    {
        return score;
    }

    string getLetterScore() const;
};

#endif