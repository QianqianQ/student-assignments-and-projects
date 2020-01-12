#include "list.hpp"
#include <iostream>

std::istream& getLines(std::istream& is, std::list<std::string>& list) {
    std:: string line;
    while(std::getline(is,line))
    {
        list.push_back(line);
    }
    return is;
}

void print(std::list<std::string> const& list) {
    std::list<std::string>::const_iterator i;
    for(i=list.begin();i!=list.end();i++)
    {
        std::cout<<*i<<std::endl;
    }
}

void sortAndUnique(std::list<std::string>& list) {
    list.sort();
    list.unique();
}


