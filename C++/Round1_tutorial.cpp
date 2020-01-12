// Boolean data type
#include <iostream>
int main(void) {
    bool flag;
    flag = true;
    if (flag) {
        std::cout << "Flag is true" << std::endl;
    }
    flag = 8 > 9;
    std::cout << "Flag: " << flag << std::endl;
}
// Reference variables
#include <iostream>

int main(void) {
   int someA = 10;
   int& someB = someA;
   someB = 20;
   std::cout << "someA: " << someA << "  someB: " << someB << std::endl;
}
//
#include <iostream>
void multiply(int& value, int mul)
{
    value *= mul;
}
int main(void) {
    int someA = 10;
    multiply(someA, 3);
    std::cout << "someA: " << someA << std::endl;
}
// auto type
#include <iostream>
int main(void) {
    double someD = 2.54;
    auto copyD = someD;
    auto number = 10;  // this will be int
    std::cout << "copyD: " << copyD << "  number: " << number << std::endl;
}
// Overlaoding
#include <iostream>
void multiply(int& value, int mul)
{
    value *= mul;
}
void multiply(double& value, int mul)
{
    value *= mul;
}
int main(void) {
    int someA = 10;
    double someB = 2.54;
    multiply(someA, 3);
    multiply(someB, 4);
    std::cout << "someA: " << someA << "  someB: " << someB << std::endl;
}
//
#include<iostream>
void multiply(double& value, int mul = 2)
{
    value *= mul;
}
int main()
{
    double val = 3;
    multiply(val);
    std::cout << val << std::endl;
    multiply(val, 3);
    std::cout << val << std::endl;
}
//String
#include<iostream>
#include<string>
int main(void)
{
    std::string s1 = "Hello";
    std::string s2;
    std::string s3;

    s2 = "world";
    s3 = s1 + " " + s2;
    std::cout << s3 << std::endl;
}
//
#include <string>
#include <iostream>
int longerLength(const std::string& a, const std::string& b)
{
    if (a.size() > b.size())
        return a.size();
    else
        return b.size();
}
int main(void)
{
    std::string s1 = "Hei";
    std::string s2 = "Hello";
    std::cout << longerLength(s1, s2);
}
//Vector
#include <vector>
#include <iostream>
int main(void)
{
    std::vector<int> numbers;

    numbers.push_back(5);
    numbers.push_back(7);

    std::cout << "Size: " << numbers.size() << std::endl;
}
//
#include <vector>
#include <iostream>
int largest_number(const std::vector<int>& v)
{
    int largest = -1000;  // hmm... -1000 is the smallest number
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i] > largest)
            largest = v[i];
    }
    return largest;
}
int main(void)
{
    std::vector<int> numbers = { 1, 2, 3 };

    numbers.push_back(5);
    numbers.push_back(7);

    std::cout << "Size: " << numbers.size() << std::endl
          << "Largest: " << largest_number(numbers) << std::endl;
}

// Class and Object
//Car.hpp
#include <string>

class Car
{
public:
    Car(const std::string& reg); // construct a brand new car
    void drive(double distance);

    const std::string& getRegNro() const;
    double getKM() const;

private:
    std::string regnro;
    double km;  // distance the car has travelled
};

//Car.cpp
#include "Car.hpp"

Car::Car(const std::string& reg)
{
    regnro = reg;
    km = 0;
}


void Car::drive(double distance)
{
    km += distance;
}


const std::string& Car::getRegNro() const
{
    return regnro;
}


double Car::getKM() const
{
    return km;
}

//main.cpp
int main()
{
    Car toyota("ABC-313");
    Car mazda("XXX-666");
    toyota.drive(10.5);  // drive a bit
    toyota.drive(4.1);  // drive some more
    std::cout << toyota.getRegNro() << " has driven "
          << toyota.getKM() << " km" << std::endl;
    return 0;
}

#include <vector>
#include "Car.hpp"

class Garage
{
public:
    Garage() { }
    void driveIn(Car& car);
    void printCars();

private:
    std::vector<Car> cars;
};
// Garage.cpp
#include <iostream>
#include "Garage.hpp"

void Garage::driveIn(Car& car)
{
    cars.push_back(car);
}

void Garage::printCars()
{
    std::vector<Car>::size_type i;
    for (i = 0; i < cars.size(); i++) {
    std::cout << cars[i].getRegNro() << " (" << cars[i].getKM()
          << " km)" << std::endl;
    }
}
//main.cpp
int main()
{
    Car toyota("ABC-313");
    Car mazda("XXX-666");
    toyota.drive(10.5);  // drive a bit
    toyota.drive(4.1);  // drive some more

    Garage talli;
    talli.driveIn(toyota);
    talli.driveIn(mazda);
    talli.printCars();

    return 0;
}
// 5.3 References,pointers and classes

