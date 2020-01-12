#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[40];
    char *strings[] = { "Paasikivi", "Kekkonen", "Koivisto",
                        "Ahtisaari", "Halonen" };
    int left,i,j;
    for(i=0;i<5;i++)
    {
    if(*strings[i]=='K')
        {
    strcpy(buffer, strings[i]);
    left = sizeof(buffer) - strlen(strings[i]);
    break;
        }
    else continue;
    }
    j = i+1;
    while (left > 0 && j < 5) {
        if(*strings[j]=='K')
        {
        strncat(buffer, strings[j], left - 1);
        left = left - strlen(strings[j]);
        j++;
        }
        else j++;
    }
    printf("buffer: %s, length: %lu\n", buffer, strlen(buffer));
}