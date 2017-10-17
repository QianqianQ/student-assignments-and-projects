#include <iostream>
#include "rectangle.hpp"

// Write you function here and test it.

void rectangle() {
    float base,height;
    std::cout<<"Please enter base and height"<<std::endl;
    std::cin>>base;
    std::cin>>height;
    float Area=base*height;
    float Circum=(base+height)*2;
    std::cout<<"Area: "<<Area<<std::endl;
    std::cout<<"Circumference: "<<Circum<<std::endl;
}