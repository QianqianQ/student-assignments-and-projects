title: References and pointers
task_id: M1-CONSTPR
points: 1

**Objective:** Defining your own function interfaces with references
  and pointers, understanding the use of const parameters.

As a difference to previous exercises, here you will need to specify
also the function interfaces according to the instructions given in
inline comments in *constpr.cpp* and *constpr.hpp*. You will need to
specify and implement the following functions:

  * `str_print` that takes an unmodifiable string s as a parameter and
    prints it to standard output (use a reference!). The function does
    not return anything.
  
  * `str_modifier` that takes a string as a parameter and changes it
    to "This string has been changed." The function does not return
    anything.

  * `vector_add` that takes a reference to a vector v that contains
    double - type values, and appends value 10.0 to the end of the
    vector. The function returns nothing.

  * `vector_add2` that takes an unmodifiable pointer to a vector v
    that contains integers, and appends value 9 to the end of the
    vector (even though the pointer is unmodifiable, the vector that
    it points to is not). This function does not return anything.

**Hint:** Remember to check the FAQ on [const correctness](https://isocpp.org/wiki/faq/const-correctness).
