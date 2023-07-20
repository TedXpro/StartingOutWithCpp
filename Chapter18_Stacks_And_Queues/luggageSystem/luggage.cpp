#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<int>);
void display(vector<vector<int>>);

int main()
{
    vector<int> luggage = {10, 20, 30, 40,20,37,1,1,5,10,5,5,5,6,2,1,40};
    arrange(luggage);
}

void arrange(vector<int> luggages)
{
    // int i = 0, j = 0;
    vector<vector<int>> plane;
    cout << luggages.size() << endl;
        //         0  1  2  3
    // luggage = {10,20,30,40};
    for (int i = 0; i < luggages.size(); i++) // i = 3 < 4;
    {
        int sum = 0;
        vector<int> container;
        for (int j = i; j < luggages.size(); j++) // j = 3 < 4;
        {
            sum += luggages[j]; // sum += 40
            // cout << luggages[j] << endl; // 10
            if(sum <= 40) // 70 <= 40 XX  
            {
                container.push_back(luggages[j]); // container = {30,}
            }
            else 
            {
                i = j - 1; // i = 3 - 1 = 2
                break;
            }
        }
        plane.push_back(container); // plane = {{10,20}, {30}, {40}}
    }

    display(plane);
}

void display(vector<vector<int>> plane)
{
    cout << plane.size() << endl;
    for (int i = plane.size() - 1; i >= 0; i--)
    {
        vector<int> container = plane[i];
        cout << "container " << i + 1  << endl;

        for (int j = 0; j < container.size(); j++)
            cout << container[j] << " ";
        cout << endl;
    }
}