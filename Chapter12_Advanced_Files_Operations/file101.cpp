#include <iostream>
#include <fstream>

using namespace std;

bool openFileIn(fstream & file, string name)
{
    bool status;
    file.open(name, ios::in);
    if (file.fail())
        status = false;
    else
        status = true;
    return status;
}

void ReadData(fstream & file)
{
    string name;
    while (file)
    {
        getline(file, name, '\n');
        cout << name << endl;
    }
        
}

int main()
{
    fstream dataFile;

    if (openFileIn(dataFile, "text101.txt"))
    {
        cout << "file Successfully opened.\n";
        ReadData(dataFile);
        dataFile.close();
    }
}