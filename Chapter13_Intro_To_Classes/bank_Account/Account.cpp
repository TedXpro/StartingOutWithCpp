#include <iostream>
#include "Account.h"

using namespace std;

void Account::setInterestRate(double rate)
{
    interestRate = rate;
}

void Account::makeDeposit(double amount)
{
    balance += amount;
    transactions++;
}

bool Account::withdrawal(double amount)
{
    if (amount > balance)
        return false;
    else
    {
        balance -= amount;
        transactions++;
        return true;
    }
}

void Account::calInterest()
{
    interest = balance * interestRate;
    balance += interest;
}

double Account::getInterestRate() const
{
    return interestRate;
}

double Account::getBalance() const
{
    return balance;
}

double Account::getInterest() const
{
    return interest;
}

int Account::getTransactions() const
{
    return transactions;
}