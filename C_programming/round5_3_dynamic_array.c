#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *dynamic_reader(int n)
{
    int *a=malloc(n*sizeof(int));
    if(a==NULL)
    {
        return NULL;
    }
    int i=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return a;
}

int *insert_into_array(int *arr, unsigned int num, int newval)
{

    int *new=realloc(arr,(num+2)*sizeof(int));
    if (new==NULL)
    {
        return NULL;
    }
    new[num]=newval;
    return new;
}

int main(void)
{
    int i=0;
    int *a=dynamic_reader(2);
    for(i=0;i<2;i++)
    printf("%d",a[i]);
    int b[]={1,2,3};
    int *new=insert_into_array(b,3,2);
    for(i=0;i<4;i++)
    {
    printf("%d",new[i]);
    }
    free(a);
    free(new);
    return 0;
}
