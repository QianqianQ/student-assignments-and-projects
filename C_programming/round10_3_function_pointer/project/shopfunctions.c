#include <string.h>
#include "shopfunctions.h"
int compareAlpha(const void* a, const void* b)
{
    const Product *Product_a=a;
    const Product *Product_b=b;
    char temp[31];
    float t_price;
    int t_instock;
    if(strcmp(Product_a->name[0],Product_b->name[0])>0)
    {
        strcpy(temp,Product_a->name);
        strcpy(Product_a->name,Product_b->name);
        strcpy(Product_b->name,Product_a->name);
        t_price=Product_a->price;
        Product_a->price=Product_b->price;
        Product_b->price=t_price;
        t_instock=Product_a->in_stock;
        Product_a->in_stock=Product_b->in_stock;
        Product_b->in_stock=t_instock;
        return 1;
    }
    else if (strcmp(Product_a->name[0],Product_b->name[0])==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

int compareNum(const void* a, const void* b)
{
    const struct Product *Product_a=a;
    const struct Product *Product_b=b;
    char temp[31];
    float t_price;
    int t_instock;
    if((Product_a->in_stock)<(Product_b->in_stock))
    {
        strcpy(temp,Product_a->name);
        strcpy(Product_a->name,Product_b->name);
        strcpy(Product_b->name,Product_a->name);
        t_price=Product_a->price;
        Product_a->price=Product_b->price;
        Product_b->price=t_price;
        t_instock=Product_a->in_stock;
        Product_a->in_stock=Product_b->in_stock;
        Product_b->in_stock=t_instock;
        return 1;
    }
    else if (Product_a->in_stock)>(Product_b->in_stock))
    {
        return 1;
    }
    else
    {
        compareAlpha(Product_a,Product_b);
    }
}

int (*cmp)(const void*, const void*)
{
    return 0;
}
