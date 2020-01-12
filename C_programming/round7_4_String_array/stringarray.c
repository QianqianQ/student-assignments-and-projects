#include <stdio.h>
#include "stringarray.h"
#include<stdlib.h>
#include<string.h>
/* Exercise a: Initializes the string array to contain the initial
 * NULL pointer, but nothing else.
 * Returns: pointer to the array of strings that has one element
 *      (that contains NULL)
 */
char **init_string_array(void)
{
    char **create=malloc(sizeof(char*));
    *create=NULL;
    return create;
}

/* Releases the memory used by the strings.
 */
void release_string_array(char **arr)
{
    int i=0;
    while(*(arr+i)!=NULL)
    {
        i++;
        continue;
    }
    for(int j=0;j<(i+1);j++)
    {
        free(arr[j]);
    }

    free(arr);
}

/* Exercise b: Add <string> to the end of array <array>.
 * Returns: pointer to the array after the string has been added.
 */
char **insert_string(char **arr, const char *str)
{
    int i=0;
    while(arr[i]!=NULL)
    {
        i++;
        continue;
    }
    arr=realloc(arr,(i+2)*sizeof(char*));
    int len=strlen(str)+1;
    arr[i]=malloc(len*sizeof(char));
    strcpy(arr[i],str);
    arr[i+1]=NULL;
    return arr;

}


/* Exercise c: reorder strings in <array> to lexicographical order */
void sort_string_array(char **arr)
{
    int i=0;
    while(*(arr+i)!=NULL)
    {
        i++;
        continue;
    }
    int len=i;
    int j=0;
    int k;
    for(j=0;j<len-1;j++)
        for(k=j;k<len;k++)
            if(strcmp(arr[j],arr[k])>0)
        {
            char *t=arr[j];
            arr[j]=arr[k];
            arr[k]=t;
        }


}

/* You can use this function to check what your array looks like.
 */
void print_string_array(char **arr)
{
    if (!arr)
        return;
    while (*arr) {
        printf("%s  ", *arr);
        arr++;
    }
    printf("\n");
}
