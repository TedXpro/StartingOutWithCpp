/*Programming Challenge - Question 12 page 654
This Program accepts test scores from students,
calculates the average and ranks based on high scores.
It uses Structures to accept informations.*/
#include <iostream>

using namespace std;

struct Studentinfo
{
    string name;     // name of students.
    string idNum;    // id number of students.
    double tests[5]; // test scores of students.
    double average;  // average test score of students.
    char grade;      // grade of students (A - F).
    int rank;        // rank of students based on their average (1, 2, 3...).
};

void getNames(Studentinfo *);
void acceptTestScores(Studentinfo *);
void calAverage(Studentinfo *);
void gradeResults(Studentinfo *);
void displayResults(Studentinfo *);

int main()
{
    Studentinfo students[10];

    getNames(students);
    acceptTestScores(students);
    calAverage(students);
    gradeResults(students);
    displayResults(students);
}

/**
 * This function will accept the names of the students.
 */
void getNames(Studentinfo *nameOfStudets)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the name of student " << (i + 1) << ": ";
        cin >> nameOfStudets[i].name;
        cout << "Enter Id Number of student " << (i + 1) << ": ";
        cin >> nameOfStudets[i].idNum;
    }
}

/**
 * This function will accept all the test scores of each student.
 */
void acceptTestScores(Studentinfo *testScores)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the test Scores of " << testScores[i].name << ":\n";
        for (int j = 0; j < 5; j++)
        {
            cout << "Test #" << (j + 1) << ": ";
            cin >> testScores[i].tests[j];
        }
    }
}

/**
 * This function will calculate the average of the testscores.
 */
void calAverage(Studentinfo *averageScores)
{
    for (int i = 0; i < 10; i++)
    {
        double total = 0.0;
        for (int j = 0; j < 5; j++)
        {
            total += averageScores[i].tests[j];
        }
        averageScores[i].average = total / 5.0;
    }
}

/**
 * This function will grade the results of students from A - F.
 */
void gradeResults(Studentinfo *grades)
{
    for (int i = 0; i < 10; i++)
    {
        if (grades[i].average >= 91 && grades[i].average <= 100)
            grades[i].grade = 'A';
        else if (grades[i].average >= 81 && grades[i].average <= 90)
            grades[i].grade = 'B';
        else if (grades[i].average >= 71 && grades[i].average <= 80)
            grades[i].grade = 'C';
        else if (grades[i].average >= 61 && grades[i].average <= 70)
            grades[i].grade = 'D';
        else
            grades[i].grade = 'F';
    }
}

/**
 * This function will display the results.
 */
void displayResults(Studentinfo *studentsGrade)
{
    cout << "Enter 1 - 10 to see their respective scores:\n";
    cout << "#   Name\t\tAverage\t\tGrade\n";
    for (int i = 0; i < 10; i++)
    {
        cout << (i + 1) << ".  " << studentsGrade[i].name << "\t\t"
             << studentsGrade[i].average << "\t\t" << studentsGrade[i].grade << endl;
    }

    int choice;
    do
    {
        cout << "Enter '1-10' to see their respective grades and '11' to quit: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Name: " << studentsGrade[0].name << endl;
            cout << "Id Number: " << studentsGrade[0].idNum << endl;
            cout << "Test #1 " << studentsGrade[0].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[0].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[0].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[0].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[0].tests[4] << endl;
            cout << "Average " << studentsGrade[0].average << endl;
            cout << "Grade " << studentsGrade[0].grade << endl;
        }
        else if (choice == 2)
        {
            cout << "Name: " << studentsGrade[1].name << endl;
            cout << "Id Number: " << studentsGrade[1].idNum << endl;
            cout << "Test #1 " << studentsGrade[1].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[1].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[1].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[1].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[1].tests[4] << endl;
            cout << "Average " << studentsGrade[1].average << endl;
            cout << "Grade " << studentsGrade[1].grade << endl;
        }
        else if (choice == 3)
        {
            cout << "Name: " << studentsGrade[2].name << endl;
            cout << "Id Number: " << studentsGrade[2].idNum << endl;
            cout << "Test #1 " << studentsGrade[2].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[2].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[2].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[2].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[2].tests[4] << endl;
            cout << "Average " << studentsGrade[2].average << endl;
            cout << "Grade " << studentsGrade[2].grade << endl;
        }
        else if (choice == 4)
        {
            cout << "Name: " << studentsGrade[3].name << endl;
            cout << "Id Number: " << studentsGrade[3].idNum << endl;
            cout << "Test #1 " << studentsGrade[3].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[3].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[3].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[3].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[3].tests[4] << endl;
            cout << "Average " << studentsGrade[3].average << endl;
            cout << "Grade " << studentsGrade[3].grade << endl;
        }
        else if (choice == 5)
        {
            cout << "Name: " << studentsGrade[4].name << endl;
            cout << "Id Number: " << studentsGrade[4].idNum << endl;
            cout << "Test #1 " << studentsGrade[4].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[4].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[4].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[4].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[4].tests[4] << endl;
            cout << "Average " << studentsGrade[4].average << endl;
            cout << "Grade " << studentsGrade[4].grade << endl;
        }
        else if (choice == 6)
        {
            cout << "Name: " << studentsGrade[5].name << endl;
            cout << "Id Number: " << studentsGrade[5].idNum << endl;
            cout << "Test #1 " << studentsGrade[5].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[5].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[5].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[5].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[5].tests[4] << endl;
            cout << "Average " << studentsGrade[5].average << endl;
            cout << "Grade " << studentsGrade[5].grade << endl;
        }
        else if (choice == 7)
        {
            cout << "Name: " << studentsGrade[6].name << endl;
            cout << "Id Number: " << studentsGrade[6].idNum << endl;
            cout << "Test #1 " << studentsGrade[6].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[6].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[6].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[6].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[6].tests[4] << endl;
            cout << "Average " << studentsGrade[6].average << endl;
            cout << "Grade " << studentsGrade[6].grade << endl;
        }
        else if (choice == 8)
        {
            cout << "Name: " << studentsGrade[7].name << endl;
            cout << "Id Number: " << studentsGrade[7].idNum << endl;
            cout << "Test #1 " << studentsGrade[7].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[7].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[7].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[7].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[7].tests[4] << endl;
            cout << "Average " << studentsGrade[7].average << endl;
            cout << "Grade " << studentsGrade[7].grade << endl;
        }
        else if (choice == 9)
        {
            cout << "Name: " << studentsGrade[8].name << endl;
            cout << "Id Number: " << studentsGrade[8].idNum << endl;
            cout << "Test #1 " << studentsGrade[8].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[8].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[8].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[8].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[8].tests[4] << endl;
            cout << "Average " << studentsGrade[8].average << endl;
            cout << "Grade " << studentsGrade[8].grade << endl;
        }
        else if (choice == 10)
        {
            cout << "Name: " << studentsGrade[9].name << endl;
            cout << "Id Number: " << studentsGrade[9].idNum << endl;
            cout << "Test #1 " << studentsGrade[9].tests[0] << endl;
            cout << "Test #2 " << studentsGrade[9].tests[1] << endl;
            cout << "Test #3 " << studentsGrade[9].tests[2] << endl;
            cout << "Test #4 " << studentsGrade[9].tests[3] << endl;
            cout << "Test #5 " << studentsGrade[9].tests[4] << endl;
            cout << "Average " << studentsGrade[9].average << endl;
            cout << "Grade " << studentsGrade[9].grade << endl;
        }
    } while (choice != 11);
}