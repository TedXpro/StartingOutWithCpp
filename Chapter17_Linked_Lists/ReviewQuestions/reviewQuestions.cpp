#include <iostream>

using namespace std;

class LinkedList
{
private:
    struct ListNode
    {
        int value;
        ListNode *next;
    };

    ListNode *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    LinkedList(const LinkedList &);

    ~LinkedList();

    void displayValues() const;
    void addValue(int);
    void deleteValue(int);
};

LinkedList::~LinkedList()
{
    ListNode *nodeptr = head;
    ListNode *temp;

    while (nodeptr != nullptr)
    {
        temp = nodeptr->next;
        delete nodeptr;
        nodeptr = temp;
    }
}

void LinkedList::deleteValue(int number)
{
    ListNode *nodePtr;
    ListNode *prevNode;

    if (!head)
    {
        cout << "There is nothing to delete\n";
        return;
    }

    if (head->value == number)
    {
        cout << "deleting " << head->value << endl;
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->next != nullptr && nodePtr->value != number)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr->next != nullptr || nodePtr->value == number)
        {
            cout << "deleting " << number << endl;
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
        else
            cout << number << " doesnt exist in the List.\n";
    }
}

void LinkedList::addValue(int number)
{
    ListNode *nodePtr;
    ListNode *previousNode;
    ListNode *newNode = new ListNode;
    newNode->value = number;

    if (head == nullptr)
    {

        cout << "Adding " << number << endl;
        head = newNode;
        newNode->next = nullptr;
        return;
    }

    if (head->value > number) // if the first value in the list is lessthan the new node;
    {
        cout << "Adding " << number << endl;
        nodePtr = new ListNode;
        nodePtr->value = head->value;

        newNode->next = nodePtr;
        nodePtr->next = head->next;

        delete head;
        head = newNode;
    }
    else
    {
        nodePtr = head;
        cout << "Adding " << number << endl;

        while (nodePtr != nullptr)
        {
            if (number < nodePtr->value)
                break;
            else
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
        }

        previousNode->next = newNode;
        newNode->next = nodePtr;
    }

    // ListNode *newNode = new ListNode;

    // newNode->value = number;
    // newNode->next = nullptr;
    // if (head == nullptr)
    // {
    //     head = newNode;
    // }
    // else
    // {
    //     ListNode *nodePtr = head;
    //     while (nodePtr->next != nullptr)
    //         nodePtr = nodePtr->next;
    //     nodePtr->next = newNode;
    // }
}

void LinkedList::displayValues() const
{
    ListNode *nodePtr = head;

    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

int main()
{
    LinkedList numberList;

    numberList.addValue(10);
    numberList.displayValues();

    numberList.addValue(9);
    numberList.displayValues();

    numberList.addValue(5);
    numberList.displayValues();

    numberList.addValue(13);
    numberList.displayValues();

    numberList.addValue(11);
    numberList.displayValues();

    numberList.addValue(2);
    numberList.displayValues();

    numberList.addValue(2);
    numberList.displayValues();
    numberList.addValue(20);
    numberList.displayValues();
    numberList.addValue(23);
    numberList.displayValues();
    numberList.addValue(12);
    numberList.displayValues();
    numberList.addValue(2);
    numberList.displayValues();
    numberList.addValue(8);
    numberList.displayValues();
    numberList.addValue(0);
    numberList.displayValues();
    numberList.addValue(1);
    numberList.displayValues();
    numberList.addValue(0);
    numberList.displayValues();
    // numberList.deleteValue(100);
    // numberList.displayValues();

    // numberList.deleteValue(10);
    // numberList.displayValues();

    // numberList.deleteValue(4);
    // numberList.displayValues();
}