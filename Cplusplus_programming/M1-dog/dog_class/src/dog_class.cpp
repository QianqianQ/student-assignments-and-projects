#include "dog_class.hpp"

//Definitions of class functions with some errors

Dog::Dog(int a, std::string n){
    age=a;
    name=n;
}

void Dog::setAge(int a){
    age=a;
}

int Dog::getAge(){
    return age;
}

void Dog::setName(std::string n){
    name=n;
}

std::string Dog::getName(){
    return name;
}


