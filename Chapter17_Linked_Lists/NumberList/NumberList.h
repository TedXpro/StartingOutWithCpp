#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    struct ListNode
    {
        double value;
        ListNode *next;
    };

    ListNode *head;

public :
    NumberList(){
        head = nullptr;
    }

    ~NumberList();

    void appendNode(double);
    void deleteNode(double);
    void insertNode(double);
    void displayList() const;
};

#endif