#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <string>

using namespace std;

class Instructor
{
private:
    string lName;
    string fName;
    string officeNumber;

public:
    Instructor()
    {
        set("", "", "");
    }

    Instructor(string ln, string fn, string on)
    {
        set(ln, fn, on);
    }

    void set(string lN, string fN, string offN) 
    {
        lName = lN;
        fName = fN;
        officeNumber = offN;
    }
    
    void print() const
    {
        cout << "Last name: " << lName << endl;
        cout << "First Name: " << fName << endl;
        cout << "Office Number: " << officeNumber << endl;
    }
};

#endif