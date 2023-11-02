#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *nodeptr1;
    ListNode *nodeptr2;
    nodeptr1 = l1; // nodeptr.next = l1.next = 4
    nodeptr2 = l2;
    int rem = 0;
    ListNode *head = nullptr;

    while (nodeptr1 != nullptr || nodeptr2 != nullptr)
    {
        cout << "Loop done" << endl;
        ListNode *node = new ListNode;
        node->val = (rem + nodeptr1->val + nodeptr2->val) % 10;

        cout << node->val << endl;

        if (head == nullptr)
            head = node;

        rem = (nodeptr1->val + nodeptr2->val) / 10;
        nodeptr1 = nodeptr1->next;
        nodeptr2 = nodeptr2->next;
    }

    cout << "out of loop done" << endl;
    return head;
}

ListNode *addValue(int val)
{
    ListNode *newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

int main()
{
    ListNode *l1 = addValue(2);
    l1->next = addValue(5);
    l1->next->next = addValue(5);

    ListNode *l2 = addValue(3);
    l2->next = addValue(4);
    l2->next->next = addValue(6);

    ListNode *answer = addTwoNumbers(l1, l2);

    cout << answer->val << endl;
    cout << "asas\n";
    cout << answer->next->val << endl;
    // cout << answer->next->next->val << endl;
    cout << "done";
}

// bool checkIfCircular(ListNode *head)
// {

//     if (head == nullptr)
//         return false;

//     ListNode *nodePtr = head->next;

//     while (nodePtr != NULL && nodePtr != head)
//         nodePtr = nodePtr->next;

//     return nodePtr == head;
// }

// int main()
// {
//     ListNode *head = addValue(2);
//     head->next = addValue(3);
//     head->next->next = addValue(4);
//     head->next->next->next = addValue(5);

//     bool status = checkIfCircular(head);
//     if (status == true)
//         cout << "Its circular\n";
//     else
//         cout << "Its not circular\n";

//     delete head;

//     head = addValue(2);
//     head->next = addValue(3);
//     head->next->next = addValue(4);
//     head->next->next->next = addValue(5);
//     head->next->next->next->next = head;

//     status = checkIfCircular(head);
//     if (status == true)
//         cout << "Its circular\n";
//     else
//         cout << "Its not circular\n";
// }
