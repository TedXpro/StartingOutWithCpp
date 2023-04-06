#include <iostream>
#include "Account.h"

using namespace std;

void displayMenu();
void makeDeposit(Account &);
void withdrawal(Account &);

int main()
{
    Account savings;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        while (choice > 7 || choice < 1)
        {
            cout << "Please make a choice in the range of 1 - 7: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "The current balance is $";
            cout << savings.getBalance() << endl;
            break;
        case 2:
            cout << "There have benn ";
            cout << savings.getTransactions()
                 << "Transactions./n";
            break;
        case 3:
            cout << "Interest earned for this period: $";
            cout << savings.getInterest() << endl;
            break;
        case 4:
            makeDeposit(savings);
            break;
        case 5:
            withdrawal(savings);
            break;
        case 6:
            savings.calInterest();
            cout << "Interest added.\n";
            break;
        }

    } while (choice != 7);
    cout << "Thank you for banking with us!\n";
}

/**
 * This function displays the Menu for the user.
 */
void displayMenu()
{
    cout << "\t\tMenu\n";
    cout << "----------------------------------------------\n";
    cout << "1. Display the Account balance\n";
    cout << "2. Display the numbe rof transactions\n";
    cout << "3. Display the interest earned for this period\n";
    cout << "4. Make a deposit\n";
    cout << "5. Make a Withdrawal\n";
    cout << "6. Add interest for this period\n";
    cout << "7. Exit the program\n\n";
    cout << "Enter your choice: ";
}

/**
 * This function will make deposit amount of money to the bank account.
 *
 * @param savingAcc holds the users account.
 */
void makeDeposit(Account &savingAcc)
{
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    savingAcc.makeDeposit(amount);
}

/**
 * This function will make withdrawal of given amount of money.
 *
 * @param savingAcc holds the users account.
 */
void withdrawal(Account &savingAcc)
{
    double amount;
    cout << "Enter the amount to be withdrawn: ";
    cin >> amount;

    if (!savingAcc.withdrawal(amount))
        cout << "ERROR: Withdrawal amount too large.\n\n";
}