#include <iostream>

using namespace std;

int main()
{
    // time calculator 
    // asks the user to input they want to be converted to either mins, hours or days.
    double x;

    cout << "enter the number of seconds: ";
    cin >> x;

    if (x >=0 && x < 60)
    {
        cout << "the number of secs is " << x << endl; 
    }
    else if (x >=60 && x < 3600)
    {
        double min;
        min = x / 60;

        cout << x << " seconds is " << min << " minutes.\n"; 
    }
    else if (x >= 3600 && x < 86400)
    {
        double hour;
        hour = x / 3600;
        cout << x << " seconds is " << hour << " hours.\n";
    }
    else if (x >= 86400)
    {
        double day;
        day = x / 86400;
        cout << x << " seconds is " << day << " days.\n";
    }
}