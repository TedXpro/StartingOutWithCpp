#include <iostream>

using namespace std;

class LinkedList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode *head;

public:
    void addToHead(int);
    void addToTail(int);
    void removeElement(int);
    void displayElements();

    LinkedList()
    {
        head = nullptr;
    }
};

void LinkedList::addToHead(int num)
{
    ListNode *newNode = new ListNode();
    newNode->val = num;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode;
    else
    {
        ListNode *temp = nullptr;
        temp = head;
        head = newNode;
        newNode->next = temp;
        delete temp;
    }
}

void LinkedList::addToTail(int num)
{
    ListNode *newNode = new ListNode();
    newNode->val = num;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode;
    else
    {
        ListNode *nodeptr = nullptr;
        nodeptr = head;

        while (nodeptr != nullptr)
            nodeptr = nodeptr->next;

        nodeptr->next = newNode;
    }
}

void LinkedList::removeElement(int num)
{
    ListNode *nodeptr = nullptr;
    ListNode *preNode = nullptr;

    if (head == nullptr)
    {
        cout << "Not Found!\n";
        return;
    }
    if (head->val == num)
    {
        nodeptr = head->next;
        delete head;
        head = nodeptr;
        cout << "Successfully Deleted\n";
        return;
    }
    else
    {
        nodeptr = head;

        while (nodeptr != nullptr && nodeptr->val != num)
        {
            preNode = nodeptr;
            nodeptr = nodeptr->next;
        }

        if (nodeptr != nullptr)
        {
            preNode->next = nodeptr->next;
            delete nodeptr;
            cout << "Successfully Deleted\n";
            return;
        }
        else
        {
            cout << "Not Found!\n";
        }
    }
}

void LinkedList::displayElements()
{
    ListNode *nodeptr = nullptr;
    nodeptr = head;
    while (nodeptr->next != nullptr)
    {
        cout << nodeptr->val << " -> ";
        nodeptr = nodeptr->next;
    }
    cout << endl;
}

int main()
{
    LinkedList llist;

    llist.addToHead(1);
    llist.addToHead(2);
    llist.addToHead(4);
    llist.addToHead(6);
    llist.addToHead(3);
    llist.addToHead(0);

    llist.displayElements(); // expected => 036421

    llist.addToTail(9);
    llist.addToTail(8);
    llist.addToTail(7);

    llist.displayElements(); // 036421987

    llist.removeElement(1);
    llist.removeElement(10);
    llist.removeElement(2);
    llist.removeElement(4);

    llist.displayElements(); // 036987
}