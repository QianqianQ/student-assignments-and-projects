#include <stdio.h>
#include "bits.h"
#include<math.h>
#include<string.h>
/* Feel free to modify this function to test different things */
void bit_set(unsigned char* data, int idx)
{
    int i=idx/8;
    int pos=idx%8;
    unsigned char flag=1;
    flag=flag<<(7-pos);
    data[i]=data[i]|flag;
}

void bit_unset(unsigned char* data, int idx)
{
    int i=idx/8;
    int pos=idx%8;
    unsigned char flag=1;
    flag=~(flag<<(7-pos));
    data[i]=data[i]&flag;
}
int bit_get(const unsigned char* data, int idx)
{
    int i=idx/8;
    int pos=idx%8;
    unsigned char flag=1;
    flag=flag<<(7-pos);
    if(data[i]&flag)
        return 1;
    else
        return 0;

}
void print_byte(unsigned char b)
{

    int i;
    for(i=0;i<8;i++)
    {
        unsigned char flag=1;
        flag=flag<<(7-i);
        if(b&flag)
            printf("%d",1);
        else
            printf("%d",0);
    }
}
unsigned char bit_get_sequence(const unsigned char* data, int idx, int how_many)
{
    unsigned char seq=0;
    int i=idx/8;
    int pos=idx%8;
    if((pos+how_many)<=8)
    {
        for(int j=0;j<how_many;j++)
        {
            unsigned char flag=1;
            flag=flag<<((7-pos)-j);
            if(data[i]&flag)
            {
                unsigned char flag2=1;
                flag2=flag2<<(how_many-1-j);
                seq=seq|flag2;
            }
        }

    }
    else
    {
        int k=0;
        for(int j=pos;j<8;j++)
        {
            unsigned char flag=1;

            flag=flag<<(7-j);
            if(data[i]&flag)
            {
                unsigned char flag2=1;
                flag2=flag2<<(how_many-1-k);
                seq=seq|flag2;

            }

            k++;
        }
        for(int l=0;l<(how_many-k);l++)
        {
            unsigned char flag=1;
            flag=flag<<(7-l);
            if(data[i+1]&flag)
            {
                unsigned char flag2=1;
                flag2=flag2<<(how_many-1-k-l);
                seq=seq|flag2;
            }

        }


    }
    return seq;

}
int main(void) {

    const unsigned char data[]={0x9b, 0x87, 0x90, 0x0d};
    bit_get_sequence(data,1,3);
    printf("Getting sequence... Should be 0x68, was 0x%02X\n", bit_get_sequence(data, 1, 3));
    return 0;
}
