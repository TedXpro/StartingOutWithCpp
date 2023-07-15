#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
private:
    struct ListNode
    {
        T value;
        ListNode *next;
    };

    ListNode *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList();

    void appendNode(T);
    void deleteNode(T);
    void insertNode(T);
    void displayList() const;
};

#endif