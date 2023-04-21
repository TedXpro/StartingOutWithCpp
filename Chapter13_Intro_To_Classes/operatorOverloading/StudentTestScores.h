#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <iostream>

using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
private:
    string studentName;
    double *testScores;
    int numTestScores;

    void createTestScoresArray(int size)
    {
        numTestScores = size;
        testScores = new double[size];
        for (int i = 0; i < size; i++)
            testScores[i] = DEFAULT_SCORE;
    }

public:
    StudentTestScores(string name, int numScores)
    {
        studentName = name;
        createTestScoresArray(numScores);
    }

    StudentTestScores(const StudentTestScores &obj)
    {
        studentName = obj.studentName;
        numTestScores = obj.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = obj.testScores[i];
    }

    ~StudentTestScores()
    {
        delete[] testScores;
    }

    void setTestScore(double score, int index)
    {
        testScores[index] = score;
    }

    void setStudentName(string name)
    {
        studentName = name;
    }

    string getStudentname() const
    {
        return studentName;
    }

    int getNumTestScores()
    {
        return numTestScores;
    }

    double getTestScore(int index) const
    {
        return testScores[index];
    }

    // void operator=(const StudentTestScores &right)
    // {
    //     delete[] testScores;
    //     studentName = right.studentName;
    //     numTestScores = right.numTestScores;
    //     testScores = new double[numTestScores];
    //     for (int i = 0; i < numTestScores; i++)
    //         testScores[i] = right.testScores[i];
    // }

    const StudentTestScores operator=(const StudentTestScores &right)
    {
        delete[] testScores;
        studentName = right.studentName;
        numTestScores = right.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = right.testScores[i];
        return *this;
    }
};
#endif