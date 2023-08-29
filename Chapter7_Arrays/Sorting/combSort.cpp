#include <iostream>
#include <vector>

using namespace std;

void combSort(vector<int>&);
void display(vector<int>);

int main()
{

    vector<int> numbers = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0, -100, -42, 90,-2,3,6};

    cout << "Before CombSort\n";
    display(numbers);

    combSort(numbers);

    cout << "After CombSort\n";
    display(numbers);
}

void combSort(vector<int> &numbers)
{
    int gap = numbers.size();
    bool swapped = true;

    while (gap != 1 && swapped == true)
    {
        swapped = false;

        gap = gap / 1.3;

        for (int i = 0; i < (numbers.size() - gap); i++)
        {
            if (numbers[i] > numbers[i + gap])
            {
                swap(numbers[i], numbers[gap + i]);
                swapped = true;
            }
        }
    }
}

void display(vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    cout << endl;
}