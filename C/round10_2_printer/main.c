#include <stdarg.h>
#include <string.h>
#include <stdio.h>
int myprint(const char *str, ...);

int myprint(const char *str,...)
{
    va_list args;
    va_start(args,str);
    char *p;
    int i=0;
    while(str!=NULL)
    {
        p=strchr(str,'&');
        if(p==NULL)
        {
            printf("%s",str);
            str=p;
            str=NULL;
        }
        else
        {
            i+=1;
            while(str!=p)
            {
            fputc(*str,stdout);
            str++;
            }
            str++;
            printf("%d",va_arg(args,int));
            continue;
        }


    }
    return i;
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
