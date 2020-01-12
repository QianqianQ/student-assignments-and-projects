#include <stdio.h>
#include "filestats.h"
#include<stdlib.h>
#include<ctype.h>
int line_count(const char *filename)
{
    FILE* f=fopen(filename,"r");
    if(!f)
    {
        fprintf(stderr,"Opening file failed\n");
        return -1;
    }
    int count=0;
    char *s=malloc(300*sizeof(char));
        while(fgets(s,300,f)!=NULL)
        {
             if(ferror(f))
            {
            fprintf(stderr,"Error occurred\n");
            return -1;
            }

            count++;
        }
        free(s);
        return count;
}

int word_count(const char *filename)
{
    FILE* test_f=fopen(filename,"r");
    if(!test_f)
    {
        fprintf(stderr,"Opening file failed\n");
        return -1;
    }
    else
    {
        fseek(test_f,0,SEEK_END);
        long size=ftell(test_f);
        if(size==0)
        {
            fclose(test_f);
            return 0;
        }
        else
        {
            fclose(test_f);
        }

    }
    FILE* f=fopen(filename,"r");
    int count=0;
    int update=0;
    int newline=0;
    char c;
    for(;;)
    {
        c=fgetc(f);
        if(isalpha(c))
        {
            update=1;
            newline=0;
        }
        if(c=='\n')
        {
            newline=1;
        }
        if(c==' '&& update==1)
        {
            count++;
            update=0;
            newline=0;
        }
         if(c=='\n'&&update==1)
        {
            count++;
            update=0;
            newline=1;
        }
        if(c==EOF)
        {
            if(newline!=1)
            {
                count++;
            }
            break;
        }
    }

        return count;

    }


