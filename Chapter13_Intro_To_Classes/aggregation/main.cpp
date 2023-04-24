#include "Course.h"

using namespace std;

int main()
{
    Course myCourse("Intro to Computer Science ", "Kramer",
                    "Shawn", "RH3010",
                    "Starting Out with C++", "Gaddis", "Addison-Wesley");
    myCourse.print();
}