#include <stdio.h>

void show_table(long *a, size_t n)
{
	int i;
	*a = 3;
	for (i = 0; i < n; i++) {
		if (i == 0)
			printf("%ld ", *a);
		else
			// print the table using pointer arithmetics:
		{
			*(a + i) = (*(a+i-1))*2;
			printf("%ld ", *(a + i));
		}

		// Also this would produce same result:
		//printf("%d ", a[i]);

		// We could also do this for same effect, but pointer 'a' is modified.
		// Therefore, this cannot be used together with indexing, as above.
		// Modification of pointer 'a' is not visible outside the function.
		//printf("%d ", *a++);
	}
	printf("\n");
}

int main(void)
{
	long table[30] = { 1, 4, 6, 8 };
	printf("size: %lu\n", sizeof(table)); /* print array size for fun */

										  /* below is one way to get the number of elements */
										  // sizeof(table) is 4 * sizeof(short) == 8;
	show_table(table, sizeof(table) / sizeof(long));

	// in this case the above would be equivalent to:
	show_table(table, 4);
}