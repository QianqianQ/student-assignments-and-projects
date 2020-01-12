#ifndef AALTO_ELEC_CPP_VECTOR
#define AALTO_ELEC_CPP_VECTOR

#include <vector>

/* These functions return the minimum, maximum and the average value
of an array. The arrays must always have at least one element -
if an empty array is passed to these functions, the behaviour is undefined.
*/

int getMin(std::vector<int> v);
int getMax(std::vector<int> v);
double getAvg(std::vector<int> v);

#endif

