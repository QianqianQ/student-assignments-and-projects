#include "list.hpp"
#include <cstdlib>  // For EXIT_FAILURE macro
#include <fstream>
#include <iostream>

int main() {
    std::list<std::string> list;
    std::ifstream f("main.cpp");
    // Read the file into list
    if (!f.is_open() || !getLines(f, list).eof()) {
        std::cerr << "Error reading main.cpp" << std::endl;
        return EXIT_FAILURE;
    }
    // Print the contents
    print(list);
    std::cout << "---" << std::endl;
    // Sort and unique
    sortAndUnique(list);
    print(list);
    std::cout << "---" << std::endl;
    // Print again
    print(list);
}

