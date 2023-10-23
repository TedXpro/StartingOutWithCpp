#include <iostream>

using namespace std;

struct LinkedNode
{
    int val;
    LinkedNode *next;
};

LinkedNode *addValue(int value)
{
    LinkedNode *newNode = new LinkedNode;
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

LinkedNode *addNumbers(LinkedNode *, LinkedNode *);
void display(LinkedNode *nodeptr);

int main()
{
    LinkedNode *l1 = addValue(2);
    l1->next = addValue(4);
    l1->next->next = addValue(3);
    cout << "L1 complete\n";

    LinkedNode *l2 = addValue(5);
    l2->next = addValue(6);
    l2->next->next = addValue(7);
    cout << "L2 complete\n";

    LinkedNode *answer = addNumbers(l1, l2);
    cout << "Answer Complete\n";

    display(l1);
    cout << "+\n";
    display(l2);
    cout << "=\n";
    display(answer);
}

LinkedNode *addNumbers(LinkedNode *l1, LinkedNode *l2)
{
    LinkedNode *answer = new LinkedNode;
    LinkedNode *ansPtr = answer;

    LinkedNode *ptr1 = l1;
    LinkedNode *ptr2 = l2;

    int rem = 0;

    while (ptr1 != nullptr || ptr2 != nullptr)
    {
        int ans;
        if (ptr1 == nullptr && ptr2 != nullptr)
        {
            cout << "if1\n";
            ans = ptr2->val + rem;
            if (ansPtr)
            {
                ansPtr->next = addValue(ans % 10);
                cout << ansPtr->next->val << " ";

                ansPtr = ansPtr->next;
            }
            else
            {
                ansPtr = addValue(ans % 10);
                cout << ansPtr->val << " ";
            }
            ptr2 = ptr2->next;
            rem = ans / 10;

            cout << rem << endl;
        }
        else if (ptr1 != nullptr && ptr2 == nullptr)
        {
            cout << "if2\n";

            ans = ptr1->val + rem;

            if (ansPtr)
            {
                ansPtr->next = addValue(ans % 10);
                cout << ansPtr->next->val << " ";

                ansPtr = ansPtr->next;
            }
            else
            {
                ansPtr = addValue(ans % 10);
                cout << ansPtr->val << " ";
            }
            ptr1 = ptr1->next;
            rem = ans / 10;

            cout << rem << endl;
        }
        else
        { // 2  5
            cout << "if3\n";

            ans = ptr1->val + ptr2->val + rem;
            if (ansPtr)
            {
                ansPtr->next = addValue(ans % 10);
                cout << ansPtr->next->val << " ";

                ansPtr = ansPtr->next;
            }
            else
            {
                ansPtr = addValue(ans % 10);
                cout << ansPtr->val << " ";
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            rem = ans / 10;

            cout << rem << endl;
        }
    }

    if (rem != 0)
    {
        ansPtr->next = addValue(rem);
        ansPtr = ansPtr->next;
    }

    LinkedNode *temp = answer;
    answer = answer->next;
    delete temp;
    return answer;
}

void display(LinkedNode *nodeptr)
{
    LinkedNode *ptr = nodeptr;

    while (ptr != nullptr)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}