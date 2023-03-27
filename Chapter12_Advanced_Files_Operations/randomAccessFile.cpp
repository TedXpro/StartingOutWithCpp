#include <iostream>
#include <fstream>

using namespace std;

struct Circle
{
    int radius;
    int diameter;
    double area;
};

int main()
{
    Circle myCircle;

    Circle *cirPtr = &myCircle;

    (*cirPtr).radius = 10; // myCircle.radius = 10;   cirPtr -> radiuds = 10
    (*cirPtr).diameter = 20;
    (*cirPtr).area = 314.15;

    cirPtr.radius
    cout << (*cirPtr).radius << endl;
    cout << cirPtr->area << endl;   // (*cirPtr).area    myCircle.area
}

// ifstream readData("randomAccess.txt");

// int curPosition;
// char str;

// curPosition = readData.tellg();
// cout << "Current Read Position is at " << curPosition << endl;   //

// // readData.seekg(5L, ios::beg);
// // readData >> str;
// // cout << str << endl;  //

// // curPosition = readData.tellg();
// // cout << "Current Read Position is at " << curPosition << endl;  //

// // readData.seekg(0L, ios::end);
// // curPosition = readData.tellg();
// // cout << "Current Read Position is at " << curPosition << endl;  //
// // readData >> str;
// // cout << str << endl; //

// readData.close();
// readData.seekg(0L, ios::end);
// curPosition = readData.tellg();
// cout << "Current Read Position is at " << curPosition << endl; //
// readData >> str;
// cout << str << endl; //    // ifstream readData("randomAccess.txt");

    // int curPosition;
    // char str;

    // curPosition = readData.tellg();
    // cout << "Current Read Position is at " << curPosition << endl;   //

    // // readData.seekg(5L, ios::beg);
    // // readData >> str;
    // // cout << str << endl;  //

    // // curPosition = readData.tellg();
    // // cout << "Current Read Position is at " << curPosition << endl;  //

    // // readData.seekg(0L, ios::end);
    // // curPosition = readData.tellg();
    // // cout << "Current Read Position is at " << curPosition << endl;  //
    // // readData >> str;
    // // cout << str << endl; //


    // readData.close();
    // readData.seekg(0L, ios::end);
    // curPosition = readData.tellg();
    // cout << "Current Read Position is at " << curPosition << endl; //
    // readData >> str;
    // cout << str << endl; //

// string str;
// ifstream ReadData("randomAccess.txt", ios::app);   // READING
// ReadData.seekg(10L, ios::)
// ios::beg  from the beginning
// ios::end  from the end
// ios::cur  form the current postion.

// getline(ReadData, str);

// fstream readData("randomAccess.txt", ios::in);

// char ch;
// readData.seekg(10L, ios::beg);
// readData >> ch;
// cout << ch << endl;
// int byte;
// byte = readData.tellg();
// cout << "current position is at " << byte << endl;
// readData >> ch;
// cout << ch << endl;

// fstream writeData("randomAccess.txt", ios::out | ios::app);
// byte = writeData.tellp();
// cout << "current postion is at " << byte << endl;
// readData >> ch;

// byte = writeData.tellp();
// cout << "currrent write postion is at " << byte << endl;
// byte = readData.tellg();
// cout << "current read postion is at " << byte << endl;

// cout << ch << endl;

// readData >> ch;
// cout << ch << endl;

// // writeData.put('k');
// byte = writeData.tellp();
// cout << "current position is at " << byte << endl;

// readData.seekg(0L, ios::beg);
// byte = readData.tellg();
// cout << "current Read position is at " << byte << endl;

// readData >> ch;
// cout << ch << endl;
// byte = readData.tellg();
// cout << "current read position is at " << byte << endl;
// readData >> ch;
// cout << ch << endl;
// byte = readData.tellg();
// cout << "current read position is at " << byte << endl;

// readData.seekg(0L, ios::end);
// byte = readData.tellg();
// cout << "current read position is at " << byte << endl;
// readData >> ch;
// cout << ch << endl;
// byte = writeData.tellp();
// cout << "currrent write postion is at " << byte << endl;