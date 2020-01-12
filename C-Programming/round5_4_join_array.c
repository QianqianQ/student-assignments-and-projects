#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *join_arrays(unsigned int n1,int *arr1,unsigned int n2,int*arr2,unsigned int n3,int*arr3)
{
    int *arr=malloc((n1+n2+n3)*sizeof(int));
    if (!arr){
        return NULL;
    }
    int i=0;
    int j,k;

    for(i=0;i<n1;i++)
    {
        arr[i]=arr1[i];
    }
    for(j=i;j<i+n2;j++)
    {
        arr[j]=arr2[j-i];
    }
    for(k=j;k<j+n3;k++)
    {
        arr[k]=arr3[k-j];
    }
    return arr;
}
int main(void)
{
    /* testing exercise. Feel free to modify */
    int a1[] = { 1, 2, 3, 4, 5 };
    int a2[] = { 10, 11, 12, 13, 14, 15, 16, 17 };
    int a3[] = { 20, 21, 22 };

    int *joined = join_arrays(5, a1, 8, a2, 3, a3);

    for (int i = 0; i < 5 + 8 + 3; i++) {
        printf("%d  ", joined[i]);
    }
    printf("\n");
    free(joined);
    return 0;
}
