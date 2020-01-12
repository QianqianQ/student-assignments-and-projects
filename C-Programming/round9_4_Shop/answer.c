#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "aaltoshop.h"



int output_binary(const char* filename, Product* shop)
{
	FILE* file= fopen(filename, "wb");
	if (file != NULL)
	{
		int i = 0;
		do
		{
			fwrite(&shop[i], sizeof(Product), 1, file);
			i++;
		} while(shop[i].name[0] != 0);
		fclose(file);
		return 0;
	}
	return 1;
}

Product* read_binary(const char* filename)
{
	FILE* file = fopen(filename, "rb");
	Product* list = NULL;
	if (file)
	{
		int i = 0;
		int retval = 1;
		do
		{
			if(retval == 1)
			{
				i++;
				list = realloc(list, i * sizeof(Product));
				retval = fread(&list[i-1], sizeof(Product), 1, file);
			}
		} while (retval == 1);
		list[i-1].name[0] = 0;

		if(i == 1)
		{
			free(list);
			return NULL;
		}
		fclose(file);
		return list;
	}
	return NULL;
}

int output_plaintext(const char* filename, Product* shop)
{
	FILE* file = fopen(filename, "w");
	if (file != NULL)
	{
		int i = 0;
		while(shop[i].name[0] != 0)
		{
			fprintf(file, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
			i++;
		}
		fclose(file);
		return 0;
	}
	return 1;
}

Product* read_plaintext(const char* filename)
{
	char buf[60];
	Product* list = NULL;
	FILE* file = fopen(filename, "r");
	if(file != NULL)
	{
		int i = 0;
		char* ret = NULL;
		do 
		{
			char namebuf[31] = {0};
			float price;
			int in_stock;
			ret = fgets(buf, 60, file);
			if(ret)
			{
				sscanf (buf, "%s %f %d", namebuf, &price, &in_stock);
				list = realloc(list, (i+1) * sizeof(Product));
				strncpy(list[i].name, namebuf, 30);
				list[i].price = price;
				list[i].in_stock = in_stock;
				i++;
			}
		} while(ret);
		list = realloc(list, (i+1) * sizeof(Product));
		list[i].name[0] = 0;
		fclose(file);
		return list;
	}
	return NULL;
}