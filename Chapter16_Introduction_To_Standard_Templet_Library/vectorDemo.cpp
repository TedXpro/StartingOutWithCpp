#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 
    // vector<int> vect;
    // int count;

    // cout << "the vector has " << vect.size() << " elements\n";

    // for (count = 0; count < 10; count++){
    //     vect.push_back(count);
    // }

    // cout << "The vector has " << vect.size() << " elements\n";

    // for (count = 0; count < vect.size(); count++)
    //     cout << vect[count] << " ";

    // cout << endl;
    // for (count = 0; count < 10; count++)
    // {
    //     cout << "Removing: " << vect[count] << endl;
    //     vect.pop_back();
    // }

    // using iterators for vectors.

    vector<int> vect;
    int count;
    vector<int>::iterator iter;

    for (count = 0; count < 10; count++){
        vect.push_back(count);
    }

    cout << "Here are the values in the vector.\n";
    for (iter = vect.begin(); iter < vect.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Here are the values in backward:\n";
    for (iter = vect.end() - 1; iter >= vect.begin(); iter--){
        cout << "hello";
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}