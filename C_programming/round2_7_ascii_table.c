#include <stdio.h>
#include <ctype.h>
void ascii_chart(char min, char max)
{
	char i = min;
	int j = 1;
	for (i = min; i < max; i++)
	{
		if (isprint(i))
		{
			if (j % 4 != 0)
			{
				printf("%3d 0x%02x %c	", i, i, i);
				j++;
			}
			else if (j % 4 == 0)
			{
				printf("%3d 0x%02x %c\n", i, i, i);
				j++;
			}
		}
		else
		{
			if (j % 4 != 0)
			{
				printf("%3d 0x%02x ?	", i, i);
				j++;
			}
			else if (j % 4 == 0)
			{
				printf("%3d 0x%02x ?\n", i, i);
				j++;
			}
		}
	}
	
	//printf("%d %d", i, j);
	while (i == max)
	{
		if (isprint(i))
		{
			if (j % 4 != 0)
			{
				printf("%3d 0x%02x %c", i, i, i);
				printf("\t");
				i++;
			}
			if (j % 4 == 0)
			{
				printf("%3d 0x%02x %c", i, i, i);
				printf("\n");
				i++;
			}
		}
		else
		{
			if (j % 4 != 0)
			{
				printf("%3d 0x%02x ?", i, i);
				printf("\t");
				i++;
			}
			if (j % 4 == 0)
			{
				printf("%3d 0x%02x ?", i, i);
				printf("\n");
				i++;
			}
		}

	}
}
int main(void)
	{
		char a, b;
		scanf("%c %c", &a, &b);
		ascii_chart(a,b);
		return 0;
	}























































