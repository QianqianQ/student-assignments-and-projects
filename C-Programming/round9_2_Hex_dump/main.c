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
    int c;
    int count_16=0;
    while((c=fgetc(f))!=EOF)
    {

        printf("%02x ",c);
        count_char++;
        count_16++;
        if(count_16==16)
        {
            printf("\n");
            count_16=0;
        }
    }
    fclose(f);
    return count_char;
}

int main(void)
{
    if (dump_hex("main.c") == -1) {
         fprintf(stderr, "Could not open main.c\n");
    }
}
