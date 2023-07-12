#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList list;

    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(5);
    list.appendNode(7);
    list.appendNode(10);

    cout << "Displaying the elements of the linked list:\n";
    list.displayList();
    cout << endl<< endl;

    cout << "Inserting numbers 6, 4, and 3 in the list.\n";
    list.insertNode(6);
    list.insertNode(4);
    list.insertNode(3);
    list.displayList();

    cout << endl
         << endl;

    cout << "Deleting the number 2, 7, 10 and 3\n";
    list.deleteNode(10);
    list.deleteNode(2);
    list.deleteNode(7);
    list.deleteNode(3);
    
    list.displayList();

    cout << endl
         << endl;
    

}