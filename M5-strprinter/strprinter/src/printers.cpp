#include "printers.hpp"

#include <stdexcept>

//DiagonalPrinter::DiagonalPrinter(std::string first,std::string last,std::ostream& os):StringPrinter(os)
StringPrinter::StringPrinter(std::ostream& ios):os(ios){}

DiagonalPrinter* DiagonalPrinter::clone() const
{
    return new DiagonalPrinter(os);
}

DiagonalPrinter& DiagonalPrinter::operator()(const std::string& str)
{
    if(first_line!="")
    os<<first_line<<std::endl;
    for(unsigned int i=0;i<str.size();i++)
    {
         for(unsigned int j=0;j<str.size();j++)
    {
        if(j==i)
            os<<str[i];
        else
            os<<" ";}
    os<<std::endl;

    }
    if(last_line!="")
    os<<last_line<<std::endl;
    return *this;
}

Printers::Printers(){}

const std::map<std::string,StringPrinter*>& Printers::get_index() const
{
    return index;
}

Printers::Printers(const Printers& a)
{
    index = a.get_index();



}

void Printers::add(const std::string& s, StringPrinter* sp)
{
    if(index.find(s)!=index.end())
        throw std::invalid_argument("Duplicate index");
    if(sp==NULL)
        throw std::invalid_argument( "Invalid printer" );
    index[s]=sp;

}

StringPrinter& Printers::operator[](const std::string& s)
{
    auto i = index.find(s);
    if(i==index.end())
        throw std::invalid_argument("Unknown index");
    return *(i->second);

}

Printers& Printers::operator=(const Printers& a)
{
    index=a.get_index();
    return *this;
}



