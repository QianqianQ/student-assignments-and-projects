#ifndef ELEC_AS_CPP_BANK
#define ELEC_AS_CPP_BANK

#include <string>

class BankAccount
{
    public:
        /* BankAccount:
         * the constructor of the BankAccount class, takes the following parameters:
         * the account's owner (string const&), 
         * the account's number (string const&) 
         * and the account's balance (double). 
         */ 
        BankAccount(std::string const& owner, std::string const& accountNumber, double balance =0.0);

        /* getOwner:
         * returns the BankAccount's owner as a string, takes no parameters. 
         */
        std::string getOwner() const;

        /* getNumber:
         * returns the BankAccount's number as a string, takes no parameters. 
         */
        std::string getNumber() const;

        /* getBalance:
         * returns the BankAccount's balance as a double, takes no parameters.
         */
        double getBalance() const;

        /* deposit:
         * deposits (stores) the parameter amount <i>(double)</i> to the BankAccount, returns nothing.
         */
        void deposit(double amount);

        /* withdraw:
         * withdraws the parameter amount from the BankAccount. 
         * If the parameter amount is bigger than the BankAccount's current balance, 
         * no withdraw is made and the function returns false. 
         * If the amount is smaller or equal to the current balance 
         * the balance is reduced by the parameter amount and the function returns true.
         */
        bool withdraw(double amount);

        /* print:
         * prints the account information to the standard output stream.
         * The function takes no parameters and returns nothing. 
         * The output format should be like the following:
         Account num: <accountNumber>, owned by: <owner>, balance: <balance> eur.\n
         */
        void print() const;

    private:
        std::string owner;
        std::string accountNumber;
        double balance;
};

/* transfer:
 * transfers money from the source account to the target account. 
 * If the parameter amount is bigger than the current balance of the source account, 
 * the function returns false and no transfer is made. 
 * If the amount is valid, that is smaller than the source account's current balance, 
 * the function adds the parameter amount to the target account's balance, 
 * reduces the amount from the source account's balance and returns true.
 */
bool transfer(BankAccount& sourceAccount, BankAccount& targetAccount, double amount);

#endif
