#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filebasics.h"
int print_file(const char *filename)
{
    int count=0;
    char c;
    FILE *file=NULL;
    file=fopen(filename,"r");
    if(file==NULL)
    {
        return -1;
    }
    else
    {
        while((c=fgetc(file))!=EOF)
        {
            printf("%c",c);
            count++;
        }
        fclose(file);
        return count;
    }


}

char *difference(const char* file1, const char* file2)
{
    FILE* f1=fopen(file1,"r");
    FILE* f2=fopen(file2,"r");
    char *s1=malloc(100*sizeof(char));
    char *s2=malloc(100*sizeof(char));
    while((fgets(s1,100,f1)!=NULL)&&(fgets(s2,100,f2)!=NULL))
    {
        if(strcmp(s1,s2)!=0)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    if(s1==NULL||s2==NULL)
        return NULL;
    else
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        char *t="----\n";
        int lent=strlen(t);
        char *total=malloc(len1+len2+lent+1);
        for(int i=0;i<len1;i++)
        {
            total[i]=s1[i];
        }
        for(int j=0;j<lent;j++)
        {
            total[len1+j]=t[j];
        }
        for(int k=0;k<len2;k++)
        {
            total[len1+lent+k]=s2[k];
        }
        total[len1+len2+lent]='\0';
        free(s1);
        free(s2);
        return total;
    }
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
