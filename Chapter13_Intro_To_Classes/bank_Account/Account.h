#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    double balance;
    double interestRate;
    double interest;
    int transactions;

public:
    Account(double b = 0, double rate = 0.045)
    {
        balance = b;
        interestRate = rate;
        interest = 0;
        transactions = 0;
    }
    void setInterestRate(double);
    void makeDeposit(double);
    bool withdrawal(double);
    void calInterest();
    double getInterestRate() const;
    double getBalance() const;
    double getInterest() const;
    int getTransactions() const;
};

#endif