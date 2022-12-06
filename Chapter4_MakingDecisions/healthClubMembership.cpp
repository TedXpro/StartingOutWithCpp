#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int choice, month;
    double price;

    const double ADULT = 40.0, SENIOR = 30.0, CHILD = 20.0;

    const int   ADULT_CHOICE = 1,
                CHILD_CHOICE = 2,
                SENIOR_CHOICE = 3,
                QUIT_CHOICE = 4;

    cout    << "\t\tHealth Club Membership Menu\n\n"
            << "1. Standard Adult Membership\n"
            << "2. Child Membership\n"
            << "3. Senior Citizen Membership\n"
            << "4. Quit the Program\n\n"
            << "Enter your choice: ";
    cin >> choice;

    cout << fixed << showpoint << setprecision(2);
    
    if (choice == ADULT_CHOICE)
    {
        cout << "how many months: ";
        cin >> month;
        
        price = month * ADULT;
        cout << "The price of the membership is " << price << endl;

    }
    else if (choice == CHILD_CHOICE)
    {
        cout << "how many months: ";
        cin >> month;
        
        price = month * CHILD;
        cout << "The price of the membership is " << price << endl;        
    }
    else if (choice == SENIOR_CHOICE)
    {
        cout << "how many months: ";
        cin >> month;
        
        price = month * SENIOR;
        cout << "The price of the membership is " << price << endl;  
    }
    else if (choice == QUIT_CHOICE)
    {
        cout << "program ending" << endl;
    }
    else
    {
        cout << "the input u entered arent in between 1 and four" << endl;
    }
}