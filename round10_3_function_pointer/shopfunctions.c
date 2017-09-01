#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include "shopfunctions.h"
int compareAlpha(const void* a, const void* b)
{
    const Product *pa = (const Product*) a;
	const Product *pb = (const Product*) b;
	int res = strcmp(pa->name, pb->name);
	return res;
}

int compareNum(const void* a, const void* b)
{
    const Product *pa = (const Product*) a;
	const Product *pb = (const Product*) b;

	if (pa->in_stock>pb->in_stock)
    {
        return -1;
    }
    else if (pa->in_stock<pb->in_stock)
    {
        return 1;
    }
    else
    {
        return compareAlpha(pa,pb);

    }


}

Product* findProduct(Product* p_array, const char* searchkey, int (*cmp)(const void*, const void*))
{
    int i=0;
    while(p_array[i].name[0]!=0)
    {
        i++;
    }
    Product* p= bsearch(searchkey,p_array,i,sizeof(Product),cmp);
    return p;
}

