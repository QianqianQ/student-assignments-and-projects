#include <stdio.h>
#include <stdlib.h>
int read_int(int *number)
{
    int ret;
    if (number == NULL) { 
        return -1; 
    }
    ret=scanf("%d", number);
    if (ret != 1) { 
        return -1;
    }
    return *number;
}

int main(void)
{
    int a;
    int *ptr_a=malloc(10);
	int ret=read_int(&a);
    int ret2 = read_int(ptr_a);
	
    if (ret!=-1)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");
	
	if (ret2!=-1)
       printf("r: %d\n", ret2);  
}