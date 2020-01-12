#include <stdio.h>
int array_sum(int *array, int count)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < count; i++)
	{
		sum = sum + *(array + i);
	}
	printf("%d\n", sum);
	return sum;
}
int array_reader(int *vals, int n)
{
	int j =0;
	for(j=0;j<n;j++)
	{
	    if(scanf("%d", &vals[j])<=0)
		break;
		
	}
	return j;
}
int main(void)
{
	int valarray[] = { 10, 100, 1000 };
	array_sum(valarray, 3);
	int array[10];
	int n = array_reader(array, 10);
	printf("%d numbers read\n", n);
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}