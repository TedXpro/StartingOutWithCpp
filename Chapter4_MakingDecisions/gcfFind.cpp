#include <iostream> 

using namespace std;

int main()
{
    // program that can find the gcf of a number
    
    int number1, number2, min, max, rem;

    cout << "Enter number1: ";
    cin >> number1;
    cout << "Enter number2: ";
    cin >> number2;

    min = (number1 < number2)? number1: number2;
    max = (number1 > number2)? number1: number2;

    int leftNumber = min;
    int rightNumber = max;
    while (true)
    {
        rem = rightNumber % leftNumber;
        if (rem == 0)
        {
            cout << "the gcf is " << leftNumber << endl;
            break;
        }
        rightNumber = leftNumber;
        leftNumber = rem;
    }
    return 0;
}