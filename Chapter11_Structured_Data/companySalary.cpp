/*This program will accept employee information such as
name, id, salary and tenure and calculates the average salary,
finds the highest paid and total salary the company pays for the 
employees per month.*/
#include <iostream>

using namespace std;

struct EmpInfo
{
    string firstName;
    string secondName;
    int empId;
    double salary;
    int tenure;
};

void acceptInfo(EmpInfo[], int);
double calAverage(EmpInfo[], int);
int findHighestPaid(EmpInfo[], int);
double findAmountToPay(EmpInfo[], int);
void displayResult(EmpInfo[], int, double, int, double);

int main()
{
    const int size = 10;
    EmpInfo employees[size];

    acceptInfo(employees, size);

    double average; // To find the average salary of the employees.
    average = calAverage(employees, size);

    int index; // To hold the index of the highest paid employee.
    index = findHighestPaid(employees, size);

    double totalSalary;
    totalSalary = findAmountToPay(employees, size);

    displayResult(employees, size, average, index, totalSalary);
}

/**
 * This function will accept all the employees information.
 */
void acceptInfo(EmpInfo emps[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "Enter information of empoyee #" << (i + 1) << endl;
        cout << "Enter the employees first name: ";
        cin >> emps[i].firstName;
        cout << "Enter the employees second name: ";
        cin >> emps[i].secondName;
        cout << "Enter the empoyees Id: ";
        cin >> emps[i].empId;
        cout << "Enter the employees salary: ";
        cin >> emps[i].salary;
        cout << "How long has the employee been working?: ";
        cin >> emps[i].tenure;
    }
}

/**
 * This function will calculate the average salary of all the employees.
 */
double calAverage(EmpInfo emps[], int arrSize)
{
    double ave;
    double total = 0.0;
    for (int i = 0; i < arrSize; i++)
    {
        total += emps[i].salary;
    }
    ave = total / arrSize;
    return ave;
}

/**
 * This function will find the highest paid employee in the company
 * and returns the position in the array.
 */
int findHighestPaid(EmpInfo emps[], int arrSize)
{
    int maxIndex;
    int i = 0;
    int max = emps[i].salary;
    for (i; i < (arrSize - 1); i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (emps[j].salary > max)
            {
                max = emps[j].salary;
                maxIndex = j;
            }
        }
    }
    return maxIndex;
}

/**
 * This function will find the amount the company needs to pay for the employees.
 */
double findAmountToPay(EmpInfo emps[], int arrSize)
{
    double totSalary = 0.0;
    for (int i = 0; i < arrSize; i++)
    {
        totSalary += emps[i].salary;
    }
    return totSalary;
}

/**
 * This function will display the informations.
 */
void displayResult(EmpInfo emps[], int arrSize, double ave, int HighPaid, double totSalary)
{
    cout << "The Highest paid person in the company is:\n";
    cout << "Name: " << emps[HighPaid].firstName << " " << emps[HighPaid].secondName << endl;
    cout << "Employee Id: " << emps[HighPaid].empId << endl;
    cout << "Salary: " << emps[HighPaid].salary << endl;
    cout << "Been at the company for " << emps[HighPaid].tenure << " years." << endl;

    cout << "The companys average salary is: " << ave << endl;
    cout << "The company will have to pay " << totSalary << " for the 10 employees.\n";
}