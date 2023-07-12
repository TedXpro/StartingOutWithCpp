#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
private:
    string name;
    string guess;
    int points;
public:
    Player(string);
    void makeGuess();
    void addPoints(int);
    string getname()
    {
        return name;
    }
    string getGuess()
    {
        return guess;
    }
    int getPoints()
    {
        return points;
    }
};

#endif