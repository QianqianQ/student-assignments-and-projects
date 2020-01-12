#include <stdio.h>
#include <string.h>
#include "hexread.h"
#include<stdlib.h>
int dump_hex(const char *filename)
{
    FILE *f=fopen(filename,"r");
    if(!f)
    {
        fprintf(stderr,"Could not open file\n");
        return EXIT_FAILURE;
    }
    int count_char=0;
    while(fgetc(f)!=EOF)
    {

        count_char++;
    }
    char* buffer=malloc(count_char);
    int n=fread(buffer,sizeof(char),count_char,f);
    int c;
    while((c=fgetc(f))!=0)
    {
        printf("%x",c);
    }
    fclose(f);
    return n;
}

int main(void)
{
    if (dump_hex("main.c") == -1) {
         fprintf(stderr, "Could not open main.c\n");
    }
}
