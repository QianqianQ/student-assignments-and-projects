#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
    return strcmp(((const Product*)a)->name, ((const Product*)b)->name);
}

int compareNum(const void* a, const void* b)
{
    const Product* pa = a;
    const Product* pb = b;
    
    int res = pb->in_stock - pa->in_stock;
    if(res != 0)
        return res;
    else
        return strcmp(pa->name, pb->name);
}

Product* findProduct(Product* p_array, const char* searchkey, int (*cmp)(const void*, const void*))
{
    Product search;
    strcpy(search.name, searchkey);
    size_t n = 0;
    while(p_array[n].name[0] != 0) n++;
    return bsearch(&search, p_array, n, sizeof(Product), cmp);
}