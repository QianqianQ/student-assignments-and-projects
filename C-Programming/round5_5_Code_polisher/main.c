#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char *delete_comments(char *input)
{
    char* output=NULL;
    char* temp=NULL;
    int i=0;
    int j=0;
    int s=0;
    int m=0;
    while(input[i]!='\0')
    {
        if(s==1&&input[i]=='\n')
        {
            s=0;
            i++;
            continue;
        }
        else if(m==1&&input[i]=='*'&&input[i+1]=='/')
        {
            m=0;
            i=i+2;
            continue;
        }
        else if(s==1||m==1)
        {
            i++;
            continue;
        }
        else if(input[i]=='/'&&input[i+1]=='/')
        {
            s=1;
            i=i+2;
            continue;
        }
        else if(input[i]=='/'&&input[i+1]=='*')
        {
            m=1;
            i=i+2;
            continue;
        }
        else
        {
            temp=realloc(output,(j+2)*sizeof(char));
            if(temp==NULL)
            {
                free(output);
                return NULL;
            }
            else
            {
                output=temp;
                output[j]=input[i];
                j++;
                i++;
                continue;
            }

        }
    }
    output[j]='\0';
    free(input);
    return output;
}
/* Read given file <filename> to dynamically allocated memory.
 * Return pointer to the allocated memory with file content, or
 * NULL on errors.
 */
char *read_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;

    char *buf = NULL;
    unsigned int count = 0;
    const unsigned int ReadBlock = 100;
    unsigned int n;
    do {
        buf = realloc(buf, count + ReadBlock + 1);
        n = fread(buf + count, 1, ReadBlock, f);
        count += n;
    } while (n == ReadBlock);

    buf[count] = 0;

    return buf;
}


int main(void)
{
    char *code = read_file("testifile.c");
    if (!code) {
        printf("No code read");
        return -1;
    }
    printf("-- Original:\n");
    fputs(code, stdout);
    code = delete_comments(code);
    printf("-- Comments removed:\n");
    fputs(code, stdout);
    free(code);
    return 0;
}
