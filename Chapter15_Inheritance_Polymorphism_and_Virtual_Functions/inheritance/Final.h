#ifndef FINAL_H
#define Final_H

#include "Grade.h"

class Final : public Grade
{
private:
    int numQuestions;
    double pointsEach;
    int numMissed;

public:
    Final()
    {
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }
    Final(int questions, int missed)
    {
        set(questions, missed);
    }

    void set(int, int);

    double getNumeQuestions() const
    {
        return numQuestions;
    }

    double getPointsEach() const
    {
        return pointsEach;
    }

    int getNumMissed() const
    {
        return numMissed;
    }
};

#endif