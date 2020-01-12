#include <stdio.h>
void sort(int *start, int size)
{
	int i,j,k;
	for(i=0;i<size-1;i++)
	for(j=i+1;j<size;j++)
	if(start[i]>start[j])
	{
	k=start[i];
	start[i]=start[j];
	start[j]=k;
	}
}
int main(void)
{
	int s[]={5,4,3,2,1};
	int i;
	sort(s,5);
	for(i=0;i<5;i++)
	{
	printf("%d",s[i]);
	}
	return 0;
}
