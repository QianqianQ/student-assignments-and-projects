#include <stdio.h>
#include <ctype.h>

int count_alpha(const char *str)
{
    int count = 0;
    while (*str) {
        if (isalpha(*str))
            count++;
        str++;
    }
    return count;
}
int main(void)
{
	char str[]={'a','b','c','\0'};
	count_alpha(str);
	printf("%d",count_alpha(str));
	return 0;
}