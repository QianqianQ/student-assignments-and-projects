#include <stdio.h>
unsigned char sixBits(unsigned char v)
{
    if(v&(1<<6))
    {
        v=v-64;
    }
    if(v&(1<<7))
    {
        v=v-128;
    }
    return v;

}
int main(void)
{
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
}
