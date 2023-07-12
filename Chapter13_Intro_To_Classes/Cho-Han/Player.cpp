#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

Player::Player(string playerName)
{
    srand(time(0));

    name = playerName;
    guess = "";
    points = 0;
}

void Player::makeGuess()
{
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 1;

    int guessNumber;

    guessNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    if (guessNumber == 0)
        guess = "Cho (eve)";
    else
        guess = "Han (odd)";
}
void Player::addPoints(int newPoints)
{
    points += newPoints;
}
