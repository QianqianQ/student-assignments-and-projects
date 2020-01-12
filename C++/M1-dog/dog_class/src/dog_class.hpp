#ifndef AALTO_ELEC_CPP_DOG_CLASS
#define AALTO_ELEC_CPP_DOG_CLASS

#include <string>

//Definition of simple class with some errors

class Dog {
public:
    Dog(int, std::string);
    void setAge(int);
    int getAge();
    void setName(std::string);
    std::string getName();
private:
    int age;
    std::string name;
};
#endif

