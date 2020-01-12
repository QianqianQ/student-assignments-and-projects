#include "book.hpp"
#include <ctime>
#include <iostream>

Book::Book(std::string const& name, std::string const& author, std::string const& isbn, bool loaned, Date due_date)
    : name(name), author(author), isbn(isbn), loaned(loaned), due_date(due_date) { }

std::string Book::getName() const
{
    return name;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getISBN() const
{
    return isbn;
}

bool Book::getStatus() const
{
    return loaned;
}

std::string Book::getDueDate() const
{
    return std::to_string(due_date.day)+"-"+std::to_string(due_date.month)+"-"+std::to_string(due_date.year);
}

int Book::loan()
{
    if(loaned)
        return 0;
    loaned=true;
    std::time_t t = time(0);
    struct tm * now = localtime(&t);
    due_date.day=now->tm_mday;
    due_date.month=now->tm_mon+2;
    due_date.year=now->tm_year+1900;
    return 1;
}

void Book::restore()
{
    loaned=false;
    due_date.day=0;
    due_date.month=0;
    due_date.year=0;
}

void Book::print() const
{
    std::cout << "Book: " << name << ", author: " << author << ", ISBN: " << isbn << ", loaned " << loaned << ", due date: " << getDueDate() << std::endl;
}

