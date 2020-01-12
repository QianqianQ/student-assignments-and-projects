#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"

Library::Library(std::string const& input_name)
{
    name=input_name;
}

std::string Library::getName() const
{
    return name;
}

std::vector<Book>& Library::getBooks()
{
    return books;
}

std::vector<Customer>& Library::getCustomers()
{
    return customers;
}

Book Library::findBookByName(std::string const& s)
{
    unsigned int i;
    for(i=0;i<books.size();i++)
    {
        if(s == books[i].getName())
            return books[i];
        else
            continue;
    }
    throw std::invalid_argument("Not fonud!");
}

std::vector<Book> Library::findBooksByAuthor(std::string const& s)
{
    std::vector<Book> A_Book;
    unsigned int i;
    for(i=0;i<books.size();i++)
    {
        if(s == books[i].getAuthor())
            A_Book.push_back(books[i]);
        else
            continue;
    }
    return A_Book;

}

std::vector<Book> Library::findAllLoanedBooks()
{
    std::vector<Book> loadedBooks;
    unsigned int i;
    for(i=0;i<books.size();i++)
    {
        if(books[i].getStatus())
            loadedBooks.push_back(books[i]);
        else
            continue;
    }
    return loadedBooks;
}

Customer Library::findCustomer(std::string const& s)
{
    unsigned int i;
    for(i=0;i<customers.size();i++)
    {
        if(!s.compare(customers[i].getID()))
            return customers[i];
        else
            continue;
    }
}
