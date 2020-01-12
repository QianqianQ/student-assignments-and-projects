#include <stdio.h>
#include <stdint.h>
#include "xorcipher.h"



void confidentiality_xor(uint32_t key, void* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        ((uint32_t*)data)[i] ^= key;
    }
}

void confidentiality_xor_shift(uint32_t key, void* data, int len)
{
    for(int i = 0; i < len; i++)
    {
        ((uint32_t*)data)[i] ^= key;
        key = (key << 1) | (key >> 31);
    }
}

void print_uint32_hex(void* data, int len)
{
    for(int i = 0; i < len; i++) printf("0x%08x ", ((uint32_t*)data)[i]);
    printf("\n");
}