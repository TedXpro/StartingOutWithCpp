#include <iostream>
#include <string>
#include "Dealer.h"
#include "Player.h"

using namespace std;
void roundResults(Dealer &, Player &, Player &);
void checkGuess(Player &, Dealer &);
void displayGrandWinner(Player, Player);

int main()
{
    const int MAX_ROUNDS = 5;
    string player1Name;
    string player2Name;

    cout << "Enter the first Player's Name: ";
    cin >> player1Name;
    cout << "Enter the Second Player's Name: ";
    cin >> player2Name;

    Dealer dealer;

    Player player1(player1Name);
    Player player2(player2Name);

    for (int round = 0; round < MAX_ROUNDS; round++)
    {
        cout << "---------------------------\n";
        cout << "Now playing round " << (round + 1) << endl;

        dealer.rollDice();

        player1.makeGuess();
        player2.makeGuess();

        roundResults(dealer, player1, player2);
    }

    displayGrandWinner(player1, player2);

    return 0;
}

void roundResults(Dealer &dealer, Player &player1, Player &player2)
{
    cout << "The dealer rolled " << dealer.getDie1Value()
         << " and " << dealer.getDie2Value() << endl;
    cout << "Result: " << dealer.getChoOrHan() << endl;

    checkGuess(player1, dealer);
    checkGuess(player2, dealer);
}

void checkGuess(Player &player, Dealer &dealer)
{
    const int POINTS_TO_ADD = 1;

    string guess = player.getGuess();

    string choHanResult = dealer.getChoOrHan();

    cout << "The Player " << player.getname()
         << " guessed " << player.getGuess() << endl;

    if (guess == choHanResult)
    {
        player.addPoints(POINTS_TO_ADD);
        cout << "AWarding " << POINTS_TO_ADD
             << " point(s) to " << player.getname()
             << endl;
    }
}

void displayGrandWinner(Player player1, Player player2)
{
    cout << "--------------------------\n";
    cout << "Game over. Here are the results:\n";
    cout << player1.getname() << ": "
         << player1.getPoints() << " points\n";

    cout << player2.getname() << ": "
         << player2.getPoints() << " points\n";

    if (player1.getPoints() > player2.getPoints())
    {
        cout << player1.getname()
             << " is the Grand Winner!\n";
    }
    else if (player1.getPoints() < player2.getPoints())
    {
        cout << player2.getname()
             << " is the Grand Winner!\n";
    }
    else
    {
        cout << "Its a tie!\n";
    }
}