#include <iostream>

using namespace std;

int main()
{
    // Math tutor 
    // displays two rarndom numbers and aks the user to find their sum and check it.
    
    int num1, num2;
    int  ans, sum;
    unsigned seed = time (0);
    srand (seed);

    num1 = rand();
    num2 = rand();

    sum = num1 + num2;
    if (num1 > num2)
    {
        cout << "what do u think is the sum of the numbers\n";
        cout << " " << num1 << endl;
        cout << "+" << num2 << endl;
        cout << "-----------------\n";

        cout << "= ";
        cin >> ans;
    }
    else 
    {
    cout << "what do u think is the sum of the numbers\n";
    cout << " " << num2 << endl;
    cout << "+" << num1 << endl;
    cout << "-----------------\n";

    cout << "= ";
    cin >> ans;
    }


    if (ans == sum)
    {
        cout << "congratulation u have got the right answer: " << endl;
    }
    else
    {
        cout << "ohhh that is not the right answer. The correct answer is " << sum << endl;
    }
    return 0;
}