#include"aaltoshop.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int output_binary(const char* filename, Product* shop)
{
    FILE* f=fopen(filename,"wb");
    if(!f)
    {
        fprintf(stderr,"Opening file failed\n");
        return 1;
    }
    int i=0;
    while(shop[i].name[0]!=0)
    {
         fwrite(&shop[i],sizeof(Product),1,f);
            if(ferror(f))
            {
            fprintf(stderr,"Error occurred\n");
            return 1;
            }
        i++;
    }
    fwrite(&shop[i].name[0],sizeof(shop[i].name[0]),1,f);
    fclose(f);
    return 0;
}



Product* read_binary(const char* filename)
{
   FILE *f=fopen(filename,"rb");

    if(!f)
    {
        fprintf(stderr,"Opening file failed\n");
        return NULL;
    }
    Product* shop=NULL;
    int i=0;
    while(feof(f)==0)
    {
        shop=realloc(shop,sizeof(Product)*(i+2));
        fread(shop+i,sizeof(Product),1,f);
        if(ferror(f))
            {
            fprintf(stderr,"Error occurred\n");
            return NULL;
            }
        i++;
    }
    shop[i].name[0]=0;
    fclose(f);
    return shop;
}

int output_plaintext(const char* filename, Product* shop)
{
    FILE *f=fopen(filename,"w");
    if(!f)
    {
        fprintf(stderr,"Opening file failed\n");
        return 1;
    }
    int i=0;
    while(shop[i].name[0]!=0)
    {
        fprintf(f,"%s %f %d\n",shop[i].name,shop[i].price,shop[i].in_stock);
         if(ferror(f))
            {
            fprintf(stderr,"Error occurred\n");
            return 1;
            }
        i++;
    }
    fclose(f);
    return 0;
}

Product* read_plaintext(const char* filename)
{
    FILE* f=fopen(filename,"r");
     if(!f)
    {
        fprintf(stderr,"Opening file failed\n");
        return NULL;
    }
    Product *shop=NULL;
    int i=0;
    while(!feof(f))
    {
        shop=realloc(shop,(i+2)*sizeof(Product));
        fscanf(f,"%s %f %d\n",shop[i].name,&shop[i].price,&shop[i].in_stock);
        if(ferror(f))
            {
            fprintf(stderr,"Error occurred\n");
            return NULL;
            }
        i++;
    }
    shop[i].name[0]=0;
    return shop;

}

