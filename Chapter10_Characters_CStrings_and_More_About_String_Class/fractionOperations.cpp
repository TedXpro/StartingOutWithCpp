#include <iostream>
#include <vector>

using namespace std;

string acceptStrings();
vector<string> separateStrings(string);
vector<double> checkOperation(vector<string>, vector<string>);
vector<double> findSum(vector<string>, vector<string>);
vector<double> findProduct(vector<string>, vector<string>);
void displayResult(vector<double>);

int main()
{
    string number1, number2;
    number1 = acceptStrings();
    // number2 = acceptStrings();

    vector<string> num1;
    // vector<string> num2;
    num1 = separateStrings(number1);
    // num2 = separateStrings(number2);

    for (int i = 0; i < num1.size(); i++)
        cout << num1[i] << endl;

    // vector<double> summation;
    // summation = findSum(num1, num2);

    // displayResult(summation);
}

/**
 * This function will accept the numbers from the user.
 *
 * @return the number in string form.
 */
string acceptStrings()
{
    string number;
    cout << "Enter the number in a/b+c/d form: ";
    cin >> number;

    return number;
}

/**
 * This function will separate the string given by the user.
 *
 * @param num is the string that contains the number.
 *
 * @return string vector that contains the separated string.
 */
vector<vector<string>> separateStrings(string num)
{
    vector<vector<string>> number;
    vector<string> number1;
    vector<string> number2;
    char ch = '/', plus = '+', times = '*';
    int count = 0;
    bool passedSign = false; // before the plus sign.
    while (count < num.size())
    {

        // 2/3+40/5  2/3  40/5
        /*
            n = 2
            number1(n)
            n = 3
            number1(n)
            n = 40
            number2(n)
        */

        string n;
        while (num[count] != ch)
        {
            if (num[count] == plus || num[count] == times)
            {
                count++;
                passedSign = true;
                
            }
            n += num[count];
            count++;
            if (count == num.size())
                break;
        }
        count++;
        if (passedSign)
            number2.push_back(n);
        else
            number1.push_back(n);
    }
    return number;
}

/**
 * This function will check the symbol and carry out
 * operation based on the sumbol.
 *
 * @param num1 will hold the value of the first fraction.
 * @param num2 will hold the vlaue of the second fraction.
 */
// vector<double> checkOperation(vector<string> num1, vector<string> num2)
// {
//     // check if it is + or *
//     /*
//         2/3+4/5
//         2,3
//         4,5

//         if it is +
//         call find sum
//     */
// }

/**
 * This function will find the sum of the two numbers in a/b form.
 *
 * @param n1 is the vector that holds the first number.
 * @param n2 is the vector that holds the second number.
 *
 * @return the sum of the two numbers in a over b form.
 */
vector<double> findSum(vector<string> n1, vector<string> n2)
{
    vector<double> sum;
    double a = stod(n1[0]);
    double b = stod(n1[1]);
    double c = stod(n2[0]);
    double d = stod(n2[1]);

    double nume, denom;
    if (b == d)
    {
        nume = a + c;
        denom = b;
    }
    else
    {
        nume = (a * d) + (c * b);
        denom = (b * d);
    }

    sum.push_back(nume);
    sum.push_back(denom);
    return sum;
}

/**
 * This function will find the product of the two numbers.
 *
 * @param n1 is a vector that holds the first number.
 * @param n2 is a vector that holds the second number.
 *
 * @return the product of the two fractions.
 */
vector<double> findProduct(vector<string> n1, vector<string> n2)
{
    vector<double> pro;
    double a = stod(n1[0]);
    double b = stod(n1[1]);
    double c = stod(n2[0]);
    double d = stod(n2[1]);

    double nume = a * c;
    double denom = b * d;

    pro.push_back(nume);
    pro.push_back(denom);
    return pro;
}

/**
 * This function will display the result.
 *
 * @param sum is the vector that holds the value of the sum
 * of the two fractions.
 */
void displayResult(vector<double> sum)
{
    cout << "The sum of the fractions is:\n";
    cout << sum[0] << "/" << sum[1] << " = ";
    cout << sum[0] / sum[1] << endl;
}