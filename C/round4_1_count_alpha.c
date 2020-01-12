#include<stdio.h>
#include<ctype.h>
int count_alpha(const char *str)
{
	int i=0;
	int count=0;
	while(str[i]!='\0')
	{
		if(isalpha(str[i]))
		{
		count=count+1;
		i++;
		}
		else
		i++;
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
	
		
		
