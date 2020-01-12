#ifndef ELEC_AS_CPP_BOOK
#define ELEC_AS_CPP_BOOK

#include <string>

typedef struct date {
    int day;
    int month;
    int year;
} Date;

class Book
{
    public:
        /* Book:
         * the constructor of the Book class, takes the following parameters:
         * the book's name (string const&), 
         * the book's author (string const&), 
         * the book's ISBN number (string const&) 
         * the status of the book, loaned or not (bool), which is by default false
         * and due date as a Date structure (Date), which is by default 0-0-0
         */ 
        Book(std::string const& name, std::string const& author, std::string const& isbn, bool loaned=false, Date due_date=Date{0,0,0});

        /* getName:
         * returns the Book's name as a string, takes no parameters.
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        std::string getName() const;

        /* getAuthor:
         * returns the Book's author as a string, takes no parameters. 
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        std::string getAuthor() const;

        /* getISBN:
         * returns the Book's ISBN as a string, takes no parameters.
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        std::string getISBN() const;

        /* getStatus:
         * returns the Book's status as a bool, takes no parameters.
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        bool getStatus() const;

        /* getDueDate:
         * returns the Book's due date as a string (DD-MM-YYYY), takes no parameters.
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        std::string getDueDate() const;

        /* loan:
         * sets the due date to current date + 1 month, e.g. loaned on 1.9. => due date 1.10.
         * sets the status to true
         * returns 1 if loaning was succesful and 0 if it was not
         */
        int loan();

        /* restore:
         * sets the due date to 0-0-0
         * sets the status to false
         * returns nothing
         */
        void restore();

        /* print:
         * prints the book's information to the standard output stream.
         * The function takes no parameters and returns nothing. 
         * The output format should be like the following:
Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <date>\n
         * This function should not alter the Book object's state, in other words the function should be const.
         */
        void print() const;

    private:
        std::string name;
        std::string author;
        std::string isbn;
        bool loaned;
        Date due_date;
};


#endif
