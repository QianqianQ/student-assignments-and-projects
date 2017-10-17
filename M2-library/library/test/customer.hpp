#ifndef ELEC_AS_CPP_CUSTOMER
#define ELEC_AS_CPP_CUSTOMER

#include <string>
#include <vector>
#include "book.hpp"

class Customer
{
    public:
        /* Customer:
         * the constructor of the Customer class, takes the following parameters:
         * the customer's name (string const&), 
         * the customer number (string const&).
         * Remember to initialize loans and the amount of loans in the constructor!
         */ 
        Customer(std::string const& name, std::string const& id);

        /* getName:
         * returns the Customer's name as a string, takes no parameters.
         * This function should not alter the Customer object's state, in other words the function should be const.
         */
        std::string getName() const;

        /* getID:
         * returns the Customer's customer number as a string, takes no parameters. 
         * This function should not alter the Customer object's state, in other words the function should be const.
         */
        std::string getID() const;

        /* getLoanAmount:
         * returns the Customer's number of loans as an int, takes no parameters.
         * This function should not alter the Customer object's state, in other words the function should be const.
         */
        int getLoanAmount() const;

        /* getLoans:
         * returns the Customer's loans as a vector<Book>, takes no parameters.
         * This function should not alter the Customer object's state, in other words the function should be const.
         */
        std::vector<Book> getLoans() const;

        /* loanBook:
         * loans a book for the customer
         * takes a reference to a book as a parameter and returns the result of loaning (from Book loan-function).
         */
        int loanBook(Book& b);

        /* returnBook:
         * returns a book from the customer
         * takes a reference to a book as a parameter and returns nothing.
         */
        void returnBook(Book& b);

        /* print:
         * prints the customer's information to the standard output stream.
         * The function takes no parameters and returns nothing. 
         * The output format should be like the following (for 2 loans):
Customer: <name>, <customer_id>, has <number_of_loans> books on loan:
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <date>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <date>\n
         * This function should not alter the Customer object's state, in other words the function should be const.
         */
        void print() const;

    private:
        /* Make variables for:
         * name (string)
         * customer id (string)
         * amount of loans (int)
         * vector of loans (vector<Book>)
         */
        std::string name;
        std::string id;
        int ln;
        std::vector<Book> loans;
};

#endif
