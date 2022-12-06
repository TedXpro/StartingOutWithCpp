#include <iostream>

using namespace std;

int main () 
{
    const int   A_score = 90,
                B_score = 80,
                C_score = 65,
                D_score = 40;
    double num;

    cout << "enter ur test score: ";
    cin >> num;

    if (num >= A_score && num <= 100)
    {
        cout << "ur grade is A";
    }
    else if (num >= B_score && num <= 89)
    {
        cout << "ur grade is B" << endl;
    }
    else if (num >= C_score && num <= 79)
    {
        cout << "ur grade is C" << endl;
    }
    else if (num >= D_score && num <= 64)
    {
        cout << "ur grade is D" << endl;
    }
    else if (num >= 0 && num <=39)
    {
       cout << "ur grade is F" << endl;
    }
    else
    {
        cout << "invalid test score" << endl;
        cout << "ur score shld be in b/n 0 and 100" << endl;
    }

}
