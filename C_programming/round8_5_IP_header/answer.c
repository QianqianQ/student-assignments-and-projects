#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "ipheader.h"


void parseIp(struct ipHeader *ip, const void *buffer)
{
    unsigned char *cbuf = (unsigned char *)buffer;
    ip->version = cbuf[0] >> 4;
    
    ip->ihl = (cbuf[0] & 0x0f) * 4;
    ip->dscp = cbuf[1] >> 2;
    ip->ecn = cbuf[1] & 0x03;
    ip->length = (cbuf[2] << 8) + cbuf[3];
    ip->identification = (cbuf[4] << 8) + cbuf[5];
    ip->flags = cbuf[6] >> 5;
    ip->fragment_offset = ((cbuf[6] & 0x1f) << 8) + cbuf[7];
    ip->time_to_live = cbuf[8];
    ip->protocol = cbuf[9];
    ip->header_checksum = (cbuf[10] << 8) + cbuf[11];
    
    memcpy(ip->source_ip, cbuf + 12, 4);
    memcpy(ip->destination_ip, cbuf + 16, 4);
}