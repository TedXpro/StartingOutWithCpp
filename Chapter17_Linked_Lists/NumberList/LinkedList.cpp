#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * destroying the linked list
 * deleting all the elements of the linked list.
*/
template<class T>
LinkedList<T>::~LinkedList(){
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;

    while(nodePtr != nullptr){
        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
}

/**
 * This function appends a new node to the linked list.
 * @param number holds the value of the new element.
 */
template<class T>
void LinkedList<T>::appendNode(T number)
{
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->value = number;
    newNode->next = nullptr;

    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;

        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
    }
}

/**
 * this function displays all the elements of the linked list;
 */
template <class T>
void LinkedList<T>::displayList() const
{
    ListNode *nodePtr;

    nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

/**
 * This function inserts value while preserving
 * the order of the numbers in the linked list.
 * @param number holds the new number to be inserted to the linked list.
 */
template <class T>
void LinkedList<T>::insertNode(T number)
{
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;

    newNode = new ListNode;
    newNode->value = number;

    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;
        previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value < number)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/**
 * this function deletes a node from the linked list
 * @param number holds the number to be deleted from the linked list.
 */
template <class T>
void LinkedList<T>::deleteNode(T number)
{
    ListNode *previousNode;
    ListNode *nodePtr;

    if (!head)
        return;
    if(head->value == number){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while(nodePtr != nullptr && nodePtr->value != number){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}