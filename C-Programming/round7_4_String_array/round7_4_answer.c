#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stringarray.h"

char **init_string_array(void)
{
    char **ret = malloc(sizeof(char *));
    *ret = NULL;
    return ret;
}

void release_string_array(char **arr)
{
    char **orig = arr;
    while(*arr)
    {
        free(*arr);
        arr++;
    }
    free(orig);
}

char **insert_string(char **arr, const char *str)
{
    int n = 0;
    if (arr)
    {
        char **p = arr;
        while (*p)
            p++;
        n = p - arr;
    } else
    {
        return NULL;
    }

    char **newarr = realloc(arr, (n + 2) * sizeof(char *));
    newarr[n] = malloc(strlen(str) + 1);
    strcpy(newarr[n], str);
    newarr[n + 1] = NULL;

    return newarr;
}


void sort_string_array(char **arr)
{
    for (unsigned int i = 0; arr[i] != NULL; i++)
    {
        unsigned int min = i;
        for (unsigned int j = i + 1; arr[j] != NULL; j++)
        {
            if (strcmp(arr[j], arr[min]) < 0)
                min = j;
        }
        if (min != i)
        {
            char *temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

/* You can use this function to check what your array looks like.
 */
void print_string_array(char **arr)
{
    if (!arr)
        return;
    while (*arr){
        printf("%s  ", *arr);
        arr++;
    }
    printf("\n");
}
