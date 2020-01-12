#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int myprint(const char *str, ...)
{
    va_list vl;
    va_start(vl, str);
    const char *s = str;
    int count = 0;
    char *p;
    
    do {
        p = strchr(s, '&');
        while (p && s != p)
        {
            fputc(*s, stdout);
            s++;
        }
        if (p)
        {
            printf("%d", va_arg(vl, int));
            s++;
            count++;
        }
    } while (p);
    va_end(vl);

    while (*s)
    {
    fputc(*s, stdout);
    s++;
    }

    return count;
}
int main(void)
{
    myprint("Hello!\n");
    myprint("Number: &\n", 5);
    myprint("Number one: &, number two: &\n", 120, 1345);
    int ret = myprint("Three numbers: & & &\n", 12, 444, 5555);
    myprint("I just printed & integers\n", ret);

    return 0;
}