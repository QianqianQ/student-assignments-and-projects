#include <cstddef>
#include <iostream>
#include "constpr.hpp"

int main(void) {
    std::string s = "This is a test strings for const exercise.";
    str_print(s);
    str_modifier(s);
    str_print(s);

    std::vector<double> d;
    vector_add(d);
    
    std::cout << d[0] << std::endl;
 
    vector_add2(nullptr);
    std::vector<int> v;
    vector_add2(&v);
    
    std::cout << v[0] << std::endl;
    
    return 0;
}
