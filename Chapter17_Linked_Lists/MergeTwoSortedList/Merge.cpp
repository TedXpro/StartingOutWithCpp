#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void mergeSort(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode();
    ListNode *nodeptr = head;

    ListNode *node1 = l1;
    ListNode *node2 = l2;
    ListNode *temp = nullptr;

    while(node1 != nullptr || node2 != nullptr)
    {
        if(node1->val > node2->val){
            nodeptr->val = node2->val;
            nodeptr->next = nullptr;

            temp = node2;
            node2 = node2->next;
        }
        else if(node1->val < node2->val){
            nodeptr->val = node1->val;
            nodeptr->next = nullptr;

            temp = node1;
            node1 = node1->next;
        }
        else 
        {
            nodeptr->val = node1->val;
            nodeptr->next->val = node2->val;
            nodeptr->next->next = nullptr;

            temp = node1;
            node1 = node1->next;

            temp = node2;
            node2 = node2->next;
        }


        delete temp;
    }
}

int main(){

    ListNode *head

}