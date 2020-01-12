#include <stdio.h>
#include <ctype.h>
#include "hexread.h"


int dump_hex(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return -1;
    int c;
    int i = 0;
    while ((c = fgetc(f)) != EOF) 
    {
        printf("%02x ", c);
        i++;
        if (!(i % 16))
            fputc('\n', stdout);
    }
    fclose(f);
    return i;
}