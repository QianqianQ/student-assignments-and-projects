#include <stdlib.h>
#include "source.h"
#include <stdio.h>


/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 *
 * Returns: pointer to the dynamically allocated array
 */
int *dynamic_reader(unsigned int n)
{
    int *a;
    a = malloc(n * sizeof(int));
    if(a == NULL)
        return NULL;

    for(unsigned int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return a;  // replace this
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 *
 * Returns: pointer to the allocated array
 */
int *insert_into_array(int *arr, unsigned int num, int newval)
{
    int *newarr = realloc(arr, (num + 1) * sizeof(int));
    if (newarr == NULL) {
        return NULL;
    }
    newarr[num] = newval;

    return newarr;  // replace this
}
