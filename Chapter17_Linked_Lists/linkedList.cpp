#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode *next;
};

ListNode *addValue(int val)
{
    ListNode *newNode = new ListNode;
    newNode->value = val;
    newNode->next = nullptr;
    return newNode;
}

bool checkIfCircular(ListNode *head)
{

    if (head == nullptr)
        return false;

    ListNode *nodePtr = head->next;

    while (nodePtr != NULL && nodePtr != head)
        nodePtr = nodePtr->next;

    return nodePtr == head;
}

int main()
{
    ListNode *head = addValue(2);
    head->next = addValue(3);
    head->next->next = addValue(4);
    head->next->next->next = addValue(5);

    bool status = checkIfCircular(head);
    if (status == true)
        cout << "Its circular\n";
    else
        cout << "Its not circular\n";

    delete head;

    head = addValue(2);
    head->next = addValue(3);
    head->next->next = addValue(4);
    head->next->next->next = addValue(5);
    head->next->next->next->next = head;

    status = checkIfCircular(head);
    if (status == true)
        cout << "Its circular\n";
    else
        cout << "Its not circular\n";
}
