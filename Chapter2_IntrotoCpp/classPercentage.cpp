#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Male and Female Percentages
    // Write a program that asks the user for the number of males and the number of females
    // registered in a class. The program should display the percentage of males and females
    // in the class.

    int male, female, total_students;
    double per_male, per_female, percentage_female, percentage_male;

    cout << "enter the number of MALE students in the classroom: ";
    cin >> male;
    cout << "enter the number of FEMALE students in the classroom: ";
    cin >> female;

    total_students = male + female;

    per_male = static_cast <double> (male) / total_students;
    per_female = static_cast <double> (female) /total_students;

    percentage_female = per_female * 100;
    percentage_male = per_male * 100;

    cout << "the percentage of male students in " << total_students << " students is " << setprecision(4) << per_male 
    << " or " << setprecision(4) << percentage_male << endl;
    cout << "the percentage of female students in " << total_students << " students is " << setprecision(4) << per_female 
    << " or " << setprecision(4) << percentage_female << endl;  
}