#include "customer.hpp"

#include <ctime>
#include <iostream>

Customer::Customer(std::string const& name, std::string const& id)
    : name(name), id(id), ln(0), loans() { }

std::string Customer::getName() const 
{ 
    return name; 
}

std::string Customer::getID() const 
{ 
    return id;
}

int Customer::getLoanAmount() const 
{ 
    return ln;
}

std::vector<Book> Customer::getLoans() const
{
    return loans;
}

int Customer::loanBook(Book& b)
{
    int t = b.loan();
    if(t){
        loans.push_back(b);
        ln++;
    }
    return t;
}

void Customer::returnBook(Book& b)
{
    for(size_t i=0; i<loans.size(); i++)
        if(loans[i].getISBN()==b.getISBN()){
            loans[i].restore();
            ln--;
            loans.erase(loans.begin()+i);
        }
}

void Customer::print() const
{
    std::cout << "Customer: " << name << ", " << id << ", has " << ln << " books on loan:" << std::endl;
    for(auto& b: loans){
        std::cout << "* ";
        b.print();
    }
}

