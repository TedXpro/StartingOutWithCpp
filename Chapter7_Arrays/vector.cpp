/*This program does a vector dot product and vector addition using arrays*/
#include <iostream>
#include <cmath>

using namespace std;

void dotProduct(int vec1[], int vec2[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += (vec1[i] * vec2[i]); 
    }

    cout << "The dot product of the vectors is: " << total << endl;
}
void vectorAddition(int vec1[], int vec2[], int size)
{
    cout << "The vector addition of the two vectors is: " << endl;
    cout << "(";
    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            cout << (vec1[i] + vec2[i]);
            break;
        }
        cout << (vec1[i] + vec2[i]) << ", ";
    }
    cout << ")" << endl;
}

int main()
{   
    char ch;
    cout << "\t\t\tVector Addition and Dot Product" << endl;
    cout << "Welcome" << endl;
    cout << "This program calculates Vector Addition and Dot product of two vectors based on your input.\n\n";
    do
    {
        int choice;
        cout << "Please Enter your choice from the following:" << endl;
        cout << "1. vector Addition" << endl;
        cout << "2. Dot Product" << endl;
        cout << "3. Both" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice > 3 && choice < 1)
        {
            cout << "Enter the right choice based on the above preferences: ";
            cin >> choice;
        }

        if (choice == 1)
        {
            int arraySize;
            cout << "Enter the size of the vectors: ";
            cin >> arraySize;

            int vector1 [arraySize], vector2 [arraySize];

            cout << "Enter the elements of the first vector." << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector1[index];
            }

            cout << "Enter the elements of the second vector: " << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector2[index];   
            }
            vectorAddition(vector1, vector2, arraySize);
        }

        if (choice == 2)
        {
            int arraySize;
            cout << "Enter the size of the vectors: ";
            cin >> arraySize;

            int vector1 [arraySize], vector2 [arraySize];

            cout << "Enter the elements of the first vector." << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector1[index];
            }

            cout << "Enter the elements of the second vector: " << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector2[index];   
            }

            dotProduct(vector1, vector2, arraySize);        
        }

        if (choice == 3)
        {
            int arraySize;
            cout << "Enter the size of the vectors: ";
            cin >> arraySize;

            int vector1 [arraySize], vector2 [arraySize];

            cout << "Enter the elements of the first vector." << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector1[index];
            }

            cout << "Enter the elements of the second vector: " << endl;
            for (int index = 0; index < arraySize; index++)
            {
                cout << "Enter element # " << (index + 1) << ": ";
                cin >> vector2[index];   
            }

            dotProduct(vector1, vector2, arraySize);
            vectorAddition(vector1, vector2, arraySize);
        }

        cout << "Enter 'q' to quit: ";
        cin >> ch;
    } while (ch != 'q' && ch != 'Q');
    
    return 0;
}
