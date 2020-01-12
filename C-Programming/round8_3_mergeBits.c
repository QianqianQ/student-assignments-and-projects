#include <stdio.h>
unsigned char mergeBits(unsigned char a, unsigned char b)
{
    unsigned char c,d;
    c=a<<4;
    d=c+b;
    return d;

}
int main()
{
    printf("%02x\n", mergeBits(0x5, 0xE));
    printf("%02x\n", mergeBits(0xA, 0xC));
    printf("%02x\n", mergeBits(0xD, 0x2));
}
