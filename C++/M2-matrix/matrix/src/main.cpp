#include <iostream>
#include "matrix.hpp"

int main(void) {
    Matrix m;
    int n;
    std::cout << "Give dimension for n x n matrix: " << std::endl;
    std::cin >> n;
    m = readMatrix(n);
    std::cout << "Rotating by 90 degrees!" << std::endl;
    m = rotate90deg(m);
    print(m);
    return 0;
}
