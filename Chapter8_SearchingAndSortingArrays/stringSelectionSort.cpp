/*This program sorts nammes in ascending order using vectors.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This function assigns the names onto the vector.
*/
void assignVector(vector<string> &peopleNames)
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"};

    for (int i = 0; i < NUM_NAMES; i++)
    {
        peopleNames.push_back(names[i]);
    }
}

/**
 * This function sorts the vector in ascending order.
*/
void sortString(vector<string> &peoplesNames)
{
    int size = peoplesNames.size();
    string minString;
    int i;
    for (int i = 0; i < (size - 1); i++)
    {
        minString = peoplesNames[i];
        int minIndex = i;
        for (int j = minIndex + 1; j < size; j++)
        {
            if (peoplesNames[j] < minString)
            {
                minString = peoplesNames[j];
                minIndex = j;
            }
        }
        peoplesNames[minIndex] = peoplesNames[i];
        peoplesNames[i] = minString;
    }
}

/**
 * This function displays the names that are ordered.
*/
void displayNames(vector<string> peoplesNames)
{
    int NUM_NAMES = peoplesNames.size();
    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << peoplesNames[i] << endl;
    }
}

int main()
{
    vector<string> names;

    assignVector(names);
    sortString(names);
    displayNames(names);

    return 0;
}