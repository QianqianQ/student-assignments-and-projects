#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

void bit_set(unsigned char* data, int idx)
{
    data[idx/8] |= (128 >> (idx % 8));
}

void bit_unset(unsigned char* data, int idx)
{
    data[idx/8] &= ~(0x80 >> idx % 8);
}

int bit_get(const unsigned char* data, int idx)
{
    return !!(data[idx / 8] & (128 >> (idx % 8)));
}

void print_byte(unsigned char b)
{
    for (int i = 0; i < 8; i++)
        if (bit_get(&b, i))
            fputc('1', stdout);
        else
            fputc('0', stdout);
}

unsigned char bit_get_sequence(const unsigned char* data, int idx, int how_many)
{
    unsigned char retval = 0;
    for (int i = 0; i < how_many; i++)
    {
        retval <<= 1;
        retval |= bit_get(data, idx+i);
    }
    return retval;
}
int main(void) {

    const unsigned char data[]={0x9b, 0x87, 0x90, 0x0d};
    bit_get_sequence(data,1,3);
    printf("Getting sequence... Should be 0x68, was 0x%02X\n", bit_get_sequence(data, 1, 3));
    return 0;
}