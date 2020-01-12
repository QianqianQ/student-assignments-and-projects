#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *join_arrays(unsigned int num1, int *arr1, unsigned int num2, int *arr2, unsigned int num3, int *arr3){
    int *mem = malloc(sizeof(int)*(num1 + num2 + num3));
    if(!mem){
        printf("Memory allocation failed");
        exit(-1);
    }
    memcpy(mem, arr1, num1*sizeof(int));
    memcpy(mem+num1, arr2, num2*sizeof(int));
    memcpy(mem+num1+num2, arr3, num3*sizeof(int));
    return mem;
}
