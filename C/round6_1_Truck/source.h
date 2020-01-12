#include <stdio.h>
#include <string.h>

// Cargo: what the truck is carrying
struct cargo {
    const char *title;
    int quantity;
    double weight;
};
struct truck {
    char name[30];
    double length;
    double weight;
    struct cargo crg;
};
// Define the truck structure here

struct truck create_truck(const char *name, double length, double weight,
			    struct cargo crg);

void print_truck(const struct truck *car);
