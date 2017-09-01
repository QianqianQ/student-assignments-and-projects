#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "filebasics.h"

int print_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return -1;
    
    int c, n=0;
    while((c=fgetc(f))!=EOF)
    {
        n++;
        printf("%c", c);
    }

    return n;
}

char *difference(const char *file1, const char *file2)
{
    FILE *f1 = fopen(file1, "r");
    if (!f1)
        return NULL;

    FILE *f2 = fopen(file2, "r");
    if (!f2)
        return NULL;

    char l1[1000];
    char l2[1000];

    fgets(l1, 1000, f1);
    fgets(l2, 1000, f2);

    while (1)
    {
        if(feof(f1) || feof(f2))
            return NULL;
        if(strcmp(l1, l2)){
            char* r = calloc(strlen(l1)+strlen(l2)+strlen("----\n")+1, 1);
            strcat(r, l1);
            strcat(r, "----\n");
            strcat(r, l2);
            return r;
        }
        fgets(l1, 1000, f1);
        fgets(l2, 1000, f2);
    }

    return NULL;
}
int main(void)
{
    printf("--- Printing file:\n");
    int t = print_file("testifile.c");
    if(t<0)
        printf("Opening failed!\n");

    printf("--- Printed %d characters\n", t);

    char* diff = difference("testifile.c", "testifile2.c");
    printf("\n--- Difference:\n");
    printf("%s", diff);

    free(diff);

    return 0;
}
