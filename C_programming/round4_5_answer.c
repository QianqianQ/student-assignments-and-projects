#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "source.h"

void korsoraattori(char *dest, const char *src)
{
    unsigned int count = 0;
    while (*src) {
        if (*src == 'k' && *(src+1) == 's') {
            *dest++ = 'x';
            src++;
        } else if (*src == 't' && *(src+1) == 's') {
            *dest++ = 'z';
            src++;
        } else {
            *dest++ = *src;
        }
        if (*src == ' ') {
            count++;
            if (!(count % 3)) {
                strcpy(dest, "niinku");
                dest += strlen("niinku");
                if (*(src+1) != 0)
                    *dest++ = ' ';
            }
            if (!(count % 4)) {
                strcpy(dest, "totanoin");
                dest += strlen("totanoin");
                if (*(src+1) != 0)
                    *dest++ = ' ';
            }
        }
        src++;
    }
    *dest = 0;
}
