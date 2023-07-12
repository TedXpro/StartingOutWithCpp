#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void doubleVal(int &);

int main()
{
    int i;
    vector<int> vect;
    vector<int>::iterator iter;

    for (i = 0; i < 10; i++)
        vect.push_back(i);

    cout << "The vector has " << vect.size() << " elements.\n";

    cout << "Before any algorithm is done on the vector\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    random_shuffle(vect.begin(), vect.end());

    cout << "After reshufling" << endl;

    for (iter = vect.begin(); iter < vect.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    sort(vect.begin(), vect.end());

    cout << "After sorting in decreasing order.\n";

    for (iter = vect.end() - 1; iter >= vect.begin(); iter--)
        cout << *iter << " ";
    cout << "\nAsscending order\n";
    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    if (binary_search(vect.begin(), vect.end(), 7))
        cout << "found seven in the vector\n";
    else
        cout << "Havent found seven in the vector\n";

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(99);
    vect.push_back(3);
    vect.push_back(3);
    vect.push_back(5);
    vect.push_back(7);

    for (iter = vect.begin(); iter < vect.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    for (iter = vect.begin(); iter < vect.end(); iter++)
    {
        cout << "the number of times the number " << *iter << " appeared in the vecor is " << count(vect.begin(), vect.end(), *iter) << endl;
    }

    iter = max_element(vect.begin(), vect.end());
    cout<< "The largest value in the vector is " << *iter << endl;

    iter = min_element(vect.begin(), vect.end());
    cout << "The smallest value in the vector is " << *iter << endl;

    cout << endl
         << endl;

    for_each(vect.begin(), vect.end(), doubleVal);

    sort(vect.begin(), vect.end());

    cout << "The values after being doubled is\n";
    for (iter = vect.begin(); iter < vect.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void doubleVal(int &val){
    val *= 2;
}