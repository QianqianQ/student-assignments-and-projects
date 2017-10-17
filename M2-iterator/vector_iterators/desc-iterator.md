title: Vector iterators
task_id: M2-ITERATOR
points: 1


**Objective:** Learn to use iterators with vectors.

Implement three functions that operate on integer vectors in the
following manner:

**readVector()** that will read numbers from user and stores then as
integer vector that is returned by the function. The function stops
reading when first non-numeric value is given by the user.

**printSum1()** that calculates sums of pair of numbers in the vector
  and prints them on the screen. The function will print the sum of
  two consecutive numbers in vector, seprated by space. For example,
  if the user gives the following input: `1 2 3 4 !`, the output
  should be `3 5 7`, followed by a newline character. As can be seen,
  the output will have one number less than the input.

**printSum2()** that calculates sum of the first and last item in the
  vector, then the sum of second and second-last item in the vector,
  and so on, until all integers in the vector have been
  processed. With input `1 2 3 4 !` the output will be `5 5`, followed
  by newline.

Use iterators for walking through the vectors.
