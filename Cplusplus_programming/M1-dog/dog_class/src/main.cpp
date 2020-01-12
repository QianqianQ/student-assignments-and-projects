#include <iostream>

#include "dog_class.hpp"

int main(void)
{
    //Here we are using initializer list to initialize a new dog
    Dog dog(3, "Mr. Wuf");
    dog.setAge(5);
    
    std::cout << "The dog is called " << dog.getName() << " and it is " << dog.getAge() << " years old!" << std::endl;
    
    return 0;
}
