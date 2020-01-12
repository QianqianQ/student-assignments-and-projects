title: Matrix rotation
task_id: M2-MATRIX
points: 1


**Objective:** Use nested vectors for a two-dimensional matrix.

This exercise operates on two-dimensional integer matrix that is
composed of vector containers. Conceptually the idea is not much
different from two-dimensional arrays in C, but now we use C++ vector
along with its functions and iterators. Like C arrays, vectors can be
accessed using the *subscript operator*, and when two nested vectors
are used for two-dimensional matrix, you need to provide two indexes,
for both dimensions respectively.

Implement the following functions:

**readMatrix(int n)** that will read a square matrix from user (i.e.,
  standard input). Argument **n** gives the width and height of the
  matrix, i.e., you must read at least n^2 integers, and then return
  the resulting Matrix. Pay attention to how the Matrix type is
  defined in **matrix.hpp**.

**rotate90deg(m)** that will rotate Matrix **m** clockwise, and return
the resulting matrix. The function should not modify the old matrix,
but create a new one.

**print(m)** that will output Matrix **m** to the screen. Each integer
is followed by one space.
