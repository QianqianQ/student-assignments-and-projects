#ifndef AALTO_ELEC_CPP_CONSTPR
#define AALTO_ELEC_CPP_CONSTPR

#include<string>
#include<vector>
// Write you function definitions here:

/* Write a function that
- has name 'str_print'
- takes an unmodifiable string s as a parameter and prints it (use a reference!)
- does not return anything
*/
void str_print(const std::string& s);

/* Write a function that
- has name 'str_modifier'
- takes a string s as a parameter and changes it to "This string has been changed."
- does not return anything
*/
void str_modifier(std::string& s);

/* Write a function that
- has name 'vector_add'
- takes a reference to a vector v that contains doubles
- appends value 10.0 to the end of the vector
- return nothing
*/
void vector_add(std::vector<double>& v);

/* Write a function that
- has name 'vector_add2'
- takes an unmodifiable pointer to a vector v that contains integers
- make sure that function handles the situation where v is nullptr
- appends value 9 to the end of the vector
- returns nothing
*/
void vector_add2(std::vector<int>* const v);

#endif
