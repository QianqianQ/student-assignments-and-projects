#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mystrcat(char *dest, const char *src)
{
    char *new=realloc(dest,20);
    char *origdest = new;
    while(*new) {
        new++;
    }

    while (*src) {
        *new++ = *src++;  // Kopioi merkin ja sitten kasvattaa osoittimia
    }
    *new = 0;

    return origdest;
}
int main(void)
{
    char *str = malloc(7);
    strcpy(str, "Aatami");

    str = mystrcat(str, "Beetami");
    printf("%s\n", str);
    free(str);
}
