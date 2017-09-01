#include <stdio.h>
#include <arpa/inet.h>
//#include<Winsock2.h>
#include "ipheader.h"


/* Parses the given buffer into an IP header structure.
 *
 * Parameters:
 * ip: pointer to the IP header structure that will be filled based
 *      on the data in the buffer
 * buffer: buffer of 20 bytes that contain the IP header. */
void parseIp(struct ipHeader *ip, const void *buffer)
{
    unsigned char *data;
    data=(unsigned char*)buffer;
    //version
    ip->version=0;
    for(int v=0;v<4;v++)
    {
        if(data[0]&(1<<(7-v)))
           {
            ip->version=(ip->version)|(1<<(3-v));
           }
        else
            {
            continue;
            }
    }

  // ihl
  ip->ihl=0;
  for(int v=0;v<4;v++)
    {
        if(data[0]&(1<<(3-v)))
           {
            ip->ihl=(ip->ihl)|(1<<(3-v));
           }
        else
            {
            continue;
            }
    }
    ip->ihl=(ip->ihl)*4;
//dcsp
ip->dscp=0;
  for(int v=0;v<6;v++)
    {
        if(data[1]&(1<<(7-v)))
           {
            ip->dscp=(ip->dscp)|(1<<(5-v));
           }
        else
            {
            continue;
            }
    }
//ecn
ip->ecn=0;
  for(int v=0;v<2;v++)
    {
        if(data[1]&(1<<(1-v)))
           {
            ip->ecn=(ip->ecn)|(1<<(1-v));
           }
        else
            {
            continue;
            }
    }
// length
ip->length=0;
  for(int v=0;v<8;v++)
    {
        if(data[2]&(1<<(7-v)))
           {
            ip->length=(ip->length)|(1<<(15-v));
           }
        else
            {
            continue;
            }
    }
  for(int v=0;v<8;v++)
    {
        if(data[3]&(1<<(7-v)))
           {
            ip->length=(ip->length)|(1<<(15-8-v));
           }
        else
            {
            continue;
            }
    }

// identification
ip->identification=0;
  for(int v=0;v<8;v++)
    {
        if(data[4]&(1<<(7-v)))
           {
            ip->identification=(ip->identification)|(1<<(15-v));
           }
        else
            {
            continue;
            }
    }
  for(int v=0;v<8;v++)
    {
        if(data[5]&(1<<(7-v)))
           {
            ip->identification=(ip->identification)|(1<<(15-8-v));
           }
        else
            {
            continue;
            }
    }

//flags
ip->flags=0;
for(int v=0;v<3;v++)
{
    if(data[6]&(1<<(7-v)))
        ip->flags=(ip->flags)|(1<<(2-v));
    else
        continue;
}
//offset
ip->fragment_offset=0;
    for(int v=0;v<5;v++)
    {
        if(data[6]&(1<<(4-v)))
           {
            ip->fragment_offset=(ip->fragment_offset)|(1<<(12-v));
           }
        else
            {
            continue;
            }
    }
    for(int v=0;v<8;v++)
    {
        if(data[7]&(1<<(7-v)))
           {
            ip->fragment_offset=(ip->fragment_offset)|(1<<(7-v));
           }
        else
            {
            continue;
            }
    }

//Time To Live
ip->time_to_live=0;
for(int v=0;v<8;v++)
{
     if(data[8]&(1<<(7-v)))
           {
            ip->time_to_live=(ip->time_to_live)|(1<<(7-v));
           }
        else
            {
            continue;
            }
}

//Protocol
ip->protocol=0;
for(int v=0;v<8;v++)
{
     if(data[9]&(1<<(7-v)))
           {
            ip->protocol=(ip->protocol)|(1<<(7-v));
           }
        else
            {
            continue;
            }
}

//header-checksum
ip->header_checksum=0;
for(int v=0;v<8;v++)
    {
        if(data[10]&(1<<(7-v)))
           {
            ip->header_checksum=(ip->header_checksum)|(1<<(15-v));
           }
        else
            {
            continue;
            }
    }
  for(int v=0;v<8;v++)
    {
        if(data[11]&(1<<(7-v)))
           {
            ip->header_checksum=(ip->header_checksum)|(1<<(15-8-v));
           }
        else
            {
            continue;
            }
    }

//source ip
for(int v=0;v<4;v++)
{
 ip->source_ip[v]=data[12+v];
}

//Destination ip
for(int v=0;v<4;v++)
{
 ip->destination_ip[v]=data[16+v];
}

}





/* Prints the given IP header structure */
void printIp(const struct ipHeader *ip)
{
    /* Note: ntohs below is for converting numbers from network byte order
       to host byte order. Subject of later courses, you can ignore them */
    printf("version: %d   ihl: %d   dscp: %d   ecn: %d\n",
            ip->version, ip->ihl, ip->dscp, ip->ecn);
    printf("length: %d   id: %d   flags: %d   offset: %d\n",
            ntohs(ip->length), ntohs(ip->identification), ip->flags, ip->fragment_offset);
    printf("time to live: %d   protocol: %d   checksum: 0x%04x\n",
            ip->time_to_live, ip->protocol, ntohs(ip->header_checksum));
    printf("source ip: %d.%d.%d.%d\n", ip->source_ip[0], ip->source_ip[1],
            ip->source_ip[2], ip->source_ip[3]);
    printf("destination ip: %d.%d.%d.%d\n", ip->destination_ip[0],
            ip->destination_ip[1],
            ip->destination_ip[2], ip->destination_ip[3]);
}

/* Shows hexdump of given data buffer */
void hexdump(const void *buffer, unsigned int length)
{
    const unsigned char *cbuf = buffer;
    unsigned int i;
    for (i = 0; i < length; ) {
        printf("%02x ", cbuf[i]);
        i++;
        if (!(i % 8))
            printf("\n");
    }
}


