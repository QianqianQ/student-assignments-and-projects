#include "tostring.hpp"
#include <iostream>
#include <set>
#include <string>
int main() {
	std::string s = "foobar";
	std::cout << "toString(s) = " << toString<std::string>(s) << std::endl;
	std::cout << "toString(s.begin(), s.end()) = " << toString(s.begin(), s.end()) << std::endl;
	std::set<double> v;
	v.insert(1.23);
	v.insert(4.56);
	v.insert(7.89);
	std::cout << "toString(v) = " << toString(v) << std::endl;
	std::cout << "toString(v.begin(), v.end()) = " << toString(v.begin(), v.end()) << std::endl;
}

