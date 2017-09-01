#include <stdio.h>
void draw_triangle(unsigned int size)
{
	int i, j, k;
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size-i; ++j)
		{
			printf(".");
		}
		for (k = j; k <= size; ++k)
		{
			printf("#");
		}
		printf("\n");
	}
}
int main(void)
	{
	unsigned int a;
	scanf("%u", &a);
	draw_triangle(a);
	return 0;
	}