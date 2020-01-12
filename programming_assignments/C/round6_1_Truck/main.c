#include <string.h>
#include <stdio.h>
#include "source.h"
#include<stdlib.h>
struct cargo;
struct truck;
struct truck create_truck(const char *name, double length, double weight,struct cargo crg){
        struct truck t;
        if(strlen(name)<30)
        {
            strcpy(t.name,name);
            t.name[strlen(name)]='\0';
        }
        else
        {
            strncpy(t.name,name,30);
            t.name[30]='\0';
        }

        t.length=length;
        t.weight=weight;
        t.crg=crg;
        return t;
};
void print_truck(const struct truck *car){
    printf("%s\n",car->name);
    printf("%.1f\n",car->length);
    printf("%.1f\n",car->weight);
    printf("%s\n",car->crg.title);
    printf("%d\n",car->crg.quantity);
    printf("%.1f\n",car->crg.weight);
}

int main()
{
    /* testing exercise. Feel free to modify */
    struct cargo c = { "Bananas", 10000, 1500 };

    struct truck t = create_truck( "Mercedes-Benz Actros", 12.0, 12.5, c );

    printf("Length of the name: %lu\n", strlen(t.name));

    // shortening the name, if it is very long
    t.name[19] = 0;

    if (t.length < 1)
	printf("Length is too short!\n");

    if (t.weight > 100)
	printf("Too heavy\n");

    printf("cargo: %s\n", t.crg.title);

    print_truck(&t);

    return 0;
}
