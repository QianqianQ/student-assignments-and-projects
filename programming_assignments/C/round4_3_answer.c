#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_substr(const char *str, const char *sub)
{
    int count = 0;
    char *ptr;
    while (1) {
        ptr = strstr(str, sub);
        if (ptr) {
            count++;
            str = ptr + 1;
        } else {
            return count;
        }
    }
}
