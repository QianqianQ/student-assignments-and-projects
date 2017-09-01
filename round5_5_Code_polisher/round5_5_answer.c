#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *delete_comments(char *input)
{
    char *fin;
    int len = strlen(input);
    fin = malloc(sizeof(char) * len);
    int i;
    int k = 0;
    for (i = 0; i < len; i++)
    {
        if(input[i] == '/' && input[i+1] == '/')
        {
            while(input[i] != '\n')
            {
                i++;
            }
        }
        else if(input[i] == '/' && input[i+1] == '*')
        {
            while(!(input[i] == '*' && input[i+1] == '/'))
            {
                i++;
            }
            i += 1;
        }
        else
        {
            fin[k] = input[i];
            k++;
        }
    }
    free(input);
    char *output = malloc(sizeof(char) * (k + 1));
    for(int j = 0; j < k; j++)
    {
        output[j] = fin[j];
    }
    output[k] = '\0';
    free(fin);
    return output;
}
