#include <stdio.h>
#include <stddef.h>
#include<string.h>
void es_print(const char *s)
{
	int k=0;
	for(k=0;*(s+k)!='#';k++)
	{
		printf("%c",*(s+k));
	}
}
unsigned int es_length(const char *s)
{
	int count=0;
	int k=0;
	for(k=0;*(s+k)!='#';k++)
	{
		count++;
	}
	return count;
}

int es_copy(char *dst, const char *src)
{
	int k=0;
	int count=0;
	for(k=0;*(src+k)!='#';k++)
	{

		dst[k]= *(src+k);
		count++;
	}
	dst[k]='#';
	return count;
}
char *es_token(char *s, char c)
{   char rep='#';
    int i=0;
    int j;
    for(i=0;s[i]!=c&&s[i]!='\0';i++)
    {
        continue;
    }
    if(s[i]=='\0')
    {
        s[i-1]=rep;
        return NULL;
    }
    else{
        s[i]=rep;
        j=i+1;
        if(s[j+1]=='\0')
        {
            s[j]=rep;
            return NULL;
        }
        else
        {
        while(s[j+1]!='\0')
        {
            j++;
            continue;
        }
        s[j]=rep;
        return s+i+1;
        }
    }

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
