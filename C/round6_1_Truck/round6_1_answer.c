#include <string.h>
#include <stdio.h>
#include "source.h"

struct truck create_truck(const char *name, double length, double weight,
                          struct cargo crg) {
    struct truck new_truck;
    strncpy(new_truck.name, name, 30);
    new_truck.name[30] = '\0';
    new_truck.length = length;
    new_truck.weight = weight;
    new_truck.crg = crg;

    return new_truck;
}

void print_truck(const struct truck *car) {
    printf("%s\n%.1f\n%.1f\n", car->name, car->length, car->weight);
    printf("%s\n%d\n%.1f\n", car->crg.title, car->crg.quantity, car->crg.weight);
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
