#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "TextBook.h"
#include "Instructor.h"

using namespace std;

class Course
{
private:
    string courseName;
    TextBook textBook;
    Instructor instructor;

public:
    Course(string cName, string instLName,
           string instFName, string instOffNumber,
           string textName, string textAutName, string textPubName)
    {
        courseName = cName;
        instructor.set(instLName, instFName, instOffNumber);
        textBook.set(textName, textPubName, textAutName);
    }

    void print() const
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor Information:\n";
        instructor.print();
        cout << "\nTextBook Information:\n";
        textBook.print();
        cout << endl;
    }
};

#endif