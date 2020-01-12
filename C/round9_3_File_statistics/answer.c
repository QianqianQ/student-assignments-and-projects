    /*BEGIN SOLUTION*/
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    /*END SOLUTION*/
#include "filestats.h"


/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return -1;
    }
    char buffer[1024];
    int lines = 0;
    
    while (!feof(f))
    {
        buffer[0] = 0;
        fgets(buffer, sizeof(buffer), f);
        if (strlen(buffer) > 0) 
        {
            lines++;
        }
    }
    fclose(f);
    return lines;
}


int word_count(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) {
        return -1;
    }
    int on_word = 0;
    int count = 0;
    while (!feof(f)) 
    {
        char buffer[1024];
        int n = fread(buffer, 1, sizeof(buffer), f);
        if (ferror(f))
        {
            fclose(f);
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (!on_word && isalpha(buffer[i]))
            {
                on_word = 1;
                count++;
            }
            if (isspace(buffer[i]))
                on_word = 0;
        }        
    }
    fclose(f);
    return count;
}