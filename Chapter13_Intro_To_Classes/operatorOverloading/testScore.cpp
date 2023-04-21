#include <iostream>
#include "StudentTestScores.h"

using namespace std;

void displayStudent(StudentTestScores);

int main()
{
    StudentTestScores student1("Kelly Thorton", 3);
    student1.setTestScore(100.0, 0);
    student1.setTestScore(95.0, 1);
    student1.setTestScore(80, 2);

    StudentTestScores student2("Yohannes Belay", 5);
    StudentTestScores student3("Menilik Belay", 10);

    student3 = student2 = student1;

    displayStudent(student1);
    displayStudent(student2);
    displayStudent(student3);

    return 0;
}

void displayStudent(StudentTestScores s)
{
    cout << "Name: " << s.getStudentname() << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < s.getNumTestScores(); i++)
        cout << s.getTestScore(i) << " ";
    cout << endl;
}