#include <iostream>
#include <vector>
#include "vector_strings.hpp"

void adder(std::vector<std::string>& names) {
    std::string name;
    std::cout<<"Enter a name:"<<std::endl;
    std::cin>>name;
    names.push_back(name);
    std::cout<<"Number of names in the vector:"<<std::endl<<names.size()<<std::endl;
}

void remover(std::vector<std::string>& names) {
    std::cout<<"Removing the last element:"<<std::endl;
    std::cout<<names[names.size()-1]<<std::endl;
    names.pop_back();
}

void printer(std::vector<std::string>& names) {
    for(auto i=names.begin();i!=names.end();i++){
        std::cout<<*i<<std::endl;
    }
}

void cmdReader() {
    std::vector<std::string> names;
    std::string command;
    std::cout<<"Commands: ADD, PRINT, REMOVE, QUIT"<<std::endl;
    std::cout<<"Enter command:"<<std::endl;
    std::cin>>command;
    while(command!="QUIT"){
        if (command=="ADD")
            adder(names);
        if(command=="REMOVE")
            remover(names);
        if(command=="PRINT")
            printer(names);
        std::cout<<"Enter command:"<<std::endl;
        std::cin>>command;
    }
}

