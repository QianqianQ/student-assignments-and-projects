#include <iostream>
#include <string>

class Mammal {
public:
    Mammal(double w) : weight(w) { }
    double getWeight() { return weight; }

private:
    double weight;
};

class Dog: public Mammal {
public:
    Dog(const std::string& n,double w):Mammal(w)
    {
        name = n;
    }
    
    const std::string getName() const {
        return name;
    }
    
    static std::string makeSound(){
        return "Wuff!";
    }
    
private:
    std::string name;
};

class Cat: public Mammal {
public:
    Cat(const std::string& n,double w):Mammal(w)
    {
        name = n;
    }
    
    const std::string getName() const {
        return name;
    }
    
    static std::string makeSound(){
        return "Meouw";
    }
    
private:
    std::string name;
};

int main(void)
{
    Mammal m(10.5);
    std::cout << "Mammal's weight is " << m.getWeight() << std::endl;

    Dog ransu("Ransu", 23.1);
    std::cout << ransu.getName() << " weighs " << ransu.getWeight()
          << " and says: " << ransu.makeSound() << std::endl;
    if (dynamic_cast< Mammal* >(&ransu)) {
        std::cout << ransu.getName() << " is a Mammal" << std::endl;
    }

    Cat garfield("Garfield", 16.5);
    std::cout << garfield.getName() << " weighs " << garfield.getWeight()
          << " and says: " << garfield.makeSound() << std::endl;
    if (dynamic_cast< Mammal* >(&garfield)) {
        std::cout << garfield.getName() << " is a Mammal" << std::endl;
    }

    std::cout << "In fact, all dogs say " << Dog::makeSound() << std::endl;
}