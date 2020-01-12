#include <stdio.h>
#include <math.h>
//To use pow function
double vectorlength(double c1, double c2, double c3)
{
	double len = sqrt(pow(c1,2) + pow(c2,2) + pow(c3,2));
	return len;
}
int main(void)
{
	double len1 = vectorlength(1, 1, 1);
	double len2 = vectorlength(1, 2, 3);
	printf("len1: %f len2: %f\n", len1, len2);
	return 0;
}