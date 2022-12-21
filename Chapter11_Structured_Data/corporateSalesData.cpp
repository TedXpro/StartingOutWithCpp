#include <iostream>

using namespace std;

struct CompanyDivision
{
    string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalQuarterSales;
    double averageQuarterSales;
};

CompanyDivision acceptData();
CompanyDivision calData(CompanyDivision);
void displayData(CompanyDivision);

int main()
{
    CompanyDivision eastInfo, westInfo, northInfo, southInfo;

    eastInfo = acceptData();
    eastInfo = calData(eastInfo);

    westInfo= acceptData();
    westInfo= calData(westInfo);
    
    northInfo = acceptData();
    northInfo = calData(northInfo);

    southInfo = acceptData();
    southInfo = calData(southInfo);

    displayData(eastInfo);
    displayData(westInfo);
    displayData(northInfo);
    displayData(southInfo);
}

CompanyDivision acceptData()
{
    CompanyDivision info;

    cout << "Enter the company division name: ";
    cin >> info.divisionName;

    cout << "Enter the first quarterly sale: ";
    cin.ignore();
    cin >> info.firstQuarterSales;

    cout << "Enter the second quarterly sale: ";
    cin >> info.secondQuarterSales;

    cout << "Enter the third quarterly sale: ";
    cin >> info.thirdQuarterSales;

    cout << "Enter the fourth quarterly sale: ";
    cin >> info.fourthQuarterSales;
    cout << endl;

    return info;
}

CompanyDivision calData(CompanyDivision info)
{
    info.totalQuarterSales = info.firstQuarterSales + info.secondQuarterSales + info.thirdQuarterSales + info.fourthQuarterSales;

    info.averageQuarterSales = info.totalQuarterSales / 4.0;

    return info;
}

void displayData(CompanyDivision info)
{
    cout << "Here are the info of " << info.divisionName << ":\n";
    cout << "Division name: " << info.divisionName << endl;
    cout << "First quarter sale: " << info.firstQuarterSales << endl;
    cout << "Second quarter sale: " << info.secondQuarterSales << endl;
    cout << "Third quarter sale: " << info.thirdQuarterSales << endl;
    cout << "Fourth quarter sale: " << info.fourthQuarterSales << endl;
    cout << "Total sales: " << info.totalQuarterSales << endl;
    cout << "Average Sales: " << info.averageQuarterSales << endl;
    cout << endl;
}