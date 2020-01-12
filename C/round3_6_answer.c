#include <stdio.h>
#include "source.h"


void sort(int *start, int size)
{
    int i, j, min, temp;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (start[j] < start[min]) min = j;
        }
        if (min != i) {
            temp = start[i];
            start[i] = start[min];
            start[min] = temp;
        }
    }
}
