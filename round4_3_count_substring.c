#include <stdio.h>
#include <string.h>
int count_substr(const char *str, const char *sub)
{
	int count = 0;
	while (strstr(str, sub))
	{
		str = strstr(str,sub);
		count++;
		str++;
	}
	return count;
}
int main(void)
{
	char a[] = "one two one twotwo three";
	char b[] = "two";
	printf("%d",count_substr(a, b));
	return 0;
}