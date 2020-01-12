#ifndef AALTO_ELEC_CPP_MATRIX
#define AALTO_ELEC_CPP_MATRIX

#include <vector>

typedef std::vector<std::vector<int>> Matrix;

// Function reads input from user to n x n matrix
Matrix readMatrix(int n);

// Function rotates n x n matrix 90 degrees clockwise
Matrix rotate90deg(Matrix & );

// Function prints n x n matrix to standard output:
// e.g. when n = 3:
// 1 2 3 \n
// 1 2 3 \n
// 1 2 3 \n
void print(Matrix & );

#endif
