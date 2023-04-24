#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include <iostream>
#include <string>

using namespace std;

class TextBook
{
private:
    string title;
    string publisher;
    string author;

public:
    TextBook()
    {
        set("", "", "");
    }
    TextBook(string tit, string pub, string aut)
    {
        set(tit, pub, aut);
    }
    void set(string t, string pub, string ath)
    {
        title = t;
        publisher = pub;
        author = ath;
    }

    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Author: " << author << endl;
    }
};

#endif