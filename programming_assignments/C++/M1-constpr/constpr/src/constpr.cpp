#include "constpr.hpp"
#include<iostream>
//TODO: First complete the header file constpr.hpp

/* Write a function that
- has name 'str_print'
- takes an unmodifiable string s as a parameter and prints it (use a reference!)
- does not return anything
*/
void str_print(const std::string& s)
{
    std::cout<<s<<std::endl;
}

/* Write a function that
- has name 'str_modifier'
- takes a string s as a parameter and changes it to "This string has been changed."
- does not return anything
*/
void str_modifier(std::string& s)
{
    std::string m="This string has been changed.";
	s.assign(m);
}

/* Write a function that
- has name 'vector_add'
- takes a reference to a vector v that contains doubles
- appends value 10.0 to the end of the vector
- return nothing
*/
void vector_add(std::vector<double>& v)
{
    v.push_back(10.0);
}

/* Write a function that
- has name 'vector_add2'
- takes an unmodifiable pointer to a vector v that contains integers
- make sure that function handles the situation where v is nullptr
- appends value 9 to the end of the vector
- returns nothing
*/
void vector_add2(std::vector<int>* const v)
{
    if(v)
        v->push_back(9);
}

