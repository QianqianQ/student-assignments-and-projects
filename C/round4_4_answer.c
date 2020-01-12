#include <stdio.h>


void es_print(const char *s)
{
    int i = 0;
    char c;
    while ((c = s[i++]) != '#')
        putchar(c); //putchar kirjoittaa ascii-merkin standardi-IO-virtaan
}

unsigned int es_length(const char *s)
{
    unsigned int i = 0;
    while (s[i] != '#') i++;
    return i;
}

int es_copy(char *dst, const char *src)
{
    int i = 0;
    while ((dst[i] = src[i]) != '#')
        i++;
    return i;
}

char *es_token(char *s, char c)
{
    int i = 0;
    while (s[i] != '#' && s[i] != c)
        i++;

    if (s[i] == '#')
        return NULL;

    s[i] = '#';
    return s + i + 1;
}
int main(void)
{

    char *str = "Auto ajoi#kilparataa";
    //char *str2 = "aaa,bbb,ccc#ddd,eee";
    char *str3="Foobarbaz#asd:w";
    es_print(str);
        printf("\n");
    char dst[20];
    int b=es_copy(dst,str);
    printf("%d\n",b);
    printf("%s\n",dst);
    //char *c=es_token(str3,':');
    //printf("%s\n",c);
    printf("%s",str3);
    return 0;
}