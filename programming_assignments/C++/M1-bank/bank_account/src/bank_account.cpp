#include "bank_account.hpp"

#include <iostream>
BankAccount::BankAccount(std::string const& i_owner, std::string const& i_accountNumber, double i_balance)
{
    owner=i_owner;
    accountNumber=i_accountNumber;
    balance=i_balance;
}

std::string BankAccount::getOwner() const
{
    return owner;
}

std::string BankAccount::getNumber() const
{
    return accountNumber;
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::deposit(double amount)
{
    balance+=amount;
}

bool BankAccount::withdraw(double amount)
{
    if(amount>balance)
        return false;
    else{
        balance-=amount;
        return true;
    }
}

void BankAccount::print() const
{
    std::cout<<"Account num: "<<accountNumber<<", owned by: "<<owner<<", balance: "<<balance<<" eur."<<std::endl;
}

bool transfer(BankAccount& sourceAccount, BankAccount& targetAccount, double amount)
{
    double source_balance=sourceAccount.getBalance();
    if(amount>source_balance)
        return false;
    if(amount>0 && source_balance >= amount)
    {
        sourceAccount.withdraw(amount);
        targetAccount.deposit(amount);
    }
    return true;
}
