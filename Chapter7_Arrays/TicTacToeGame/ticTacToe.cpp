/*Chapter 7 - Programming Challenge Question 18: Tic Tac Toe Game.
This program is game of tic tac toe.*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * This function displays the positions of the objects.
 */
void display(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * This function accpets the row and column from a player.
 */
void acceptPosition(int numbers[])
{
    int row, col;
    cout << "Enter the row of the matrix: ";
    cin >> row;
    cout << "Enter the column of the matrix: ";
    cin >> col;

    numbers[0] = row;
    numbers[1] = col;
}

/**
 * This function test the validity of the row and column that are entered by the player.
 */
bool testValidity(int numbers[])
{
    int row = numbers[0];
    int col = numbers[1];

    return ((row >= 0 && row < 3) && (col >= 0 && col < 3));
}

/**
 * This function test whether the row and column entered by the player was taken or not.
 */
bool isNotTaken(char objects[3][3], int positions[])
{
    return (objects[positions[0]][positions[1]] == '*');
}

/**
 * This function tests the positions of 'X' or 'O' diagonally on every round.
 */
bool testDiagonal(char objects[3][3])
{
    int fdCounter1 = 0, fdCounter2 = 0;    // forward counter
    int bkCounter1 = 0, bkCounter2 = 0;    // backward counter
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (objects[i][j] == 'X')
                    fdCounter1++;
                if (objects[i][j] == 'O')
                    fdCounter2++;
            }
            if ((i + j) == 2)
            {
                if (objects[i][j] == 'X')
                    bkCounter1++;
                if (objects[i][j] == 'O')
                    bkCounter2++;
            }
        }
        if ((fdCounter1 == 3) || (fdCounter2 == 3))
            return true;
        else if ((bkCounter1 == 3) || (bkCounter2 == 3))
            return true;
    }

    return false;
}

/**
 * This function test the position of 'X' or 'O' in a row on every round.
*/
bool testRow(char objects[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        int counter1 = 0;
        int counter2 = 0;
        for (int j = 0; j < 3; j++)
        {
            if (objects[i][j] == 'X')
                counter1++;
            if (objects[i][j] == 'O')
                counter2++;
        }
        if ((counter1 == 3) || (counter2 == 3))
            return true;
    }
    return false;
}

/**
 * This function test the position of 'X' or 'O' in a column on every round.
 */
bool testColumn(char objects[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        int counter1 = 0;
        int counter2 = 0;
        for (int j = 0; j < 3; j++)
        {
            if (objects[j][i] == 'X')
                counter1++;
            if (objects[j][i] == 'O')
                counter2++;
        }
        if ((counter1 == 3) || (counter2 == 3))
            return true;
    }
    return false;
}

/**
 * This function calls the three functions above and tries to find a winner.
*/
bool testWinner(char objects[3][3])
{
    return (testColumn(objects) || testDiagonal(objects) || testRow(objects));
}

int main()
{
    char ch;
    do
    {
        char objects[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
        int numbers[2];

        cout << "\t\tWelcome! to Tic Tac Toe." << endl;
        cout << "choose a row and column from 0 - 2 and insert your choice\n";
        cout << "There will be two players- player 1 will be 'X' and player 2 will be 'O'\n";

        display(objects);

        bool flag = true;
        int count = 1;

        while (flag)
        {
            if (count % 2 != 0)
                cout << "Player 1\n";

            else
                cout << "Player 2\n";

            int rows, cols;
            int position[2] = {rows, cols};
            acceptPosition(position);

            while (!testValidity(position))
            {
                cout << "The numbers you entered should be between 0 and 2.\n";
                acceptPosition(position);
            }

            while (!isNotTaken(objects, position))
            {
                cout << "The row column pair u entered is taken\n";
                cout << "enter a correct pair.\n";
                acceptPosition(position);
            }

            if (count % 2 != 0)
            {
                objects[position[0]][position[1]] = 'X';
                display(objects);

                if (testWinner(objects))
                {
                    cout << "player 1 wins." << endl;
                    flag = false;
                }
            }
            else
            {
                objects[position[0]][position[1]] = 'O';
                display(objects);

                if (testWinner(objects))
                {
                    cout << "player 2 wins." << endl;
                    flag = false;
                }
            }

            count++;
            if (count > 9)
            {
                cout << "This game is a draw\n";
                flag = false;
            }
            
        }
        cout << "Do u wish to continue (Y/N): ";
        cin >> ch;
    } while (ch != 'N' && ch != 'n');
    cout << "Thank you for playing!!" << endl;

    return 0;
}