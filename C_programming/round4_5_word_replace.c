#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void korsoraattori(char *dest, const char *src)
{
	int i = 0;
	int j = 0;
	int space3 =0;
	int space4=0;
	while (src[i] != '\0')
		{
			if (src[i] == 'k'&&src[i + 1] == 's')
			{
				strcpy(dest+j, "x");
				j++;
				i += 2;
				continue;
			}
			else if (src[i] == 't'&&src[i + 1] == 's')
			{
				strcpy(dest+j, "z");
				j++;
				i += 2;
				continue;
			}
			else if (src[i] == ' ')
			{
				strcpy(dest+j, " ");
				j++;
				i++;
				space3++;
				space4++;

				if (space3 == 3)
				{
					strcpy(dest+j, "niinku ");
					j=j+7;
					space3 = 0;
					continue;
				}
				if (space4 == 4)
				{
					strcat(dest+j, "totanoin ");
					j=j+9;
					space4 = 0;
					continue;
				}
				else {
					continue;
				}
			}
			else
			{
				strcpy(dest+j, src+i);
				i++;
				j++;
				continue;
			}
		}
	
}

int main(void)
{
	char *dest=malloc(100);
	char *src = "yksi auto valui itsekseen ilman kuljettajaa m?ke? alas";
	korsoraattori(dest, src);
	printf("%s",dest);
	return 0;
}
				
				







