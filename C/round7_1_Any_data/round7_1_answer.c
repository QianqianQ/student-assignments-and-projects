#include <stdio.h>
#include <string.h>
#include "anydata.h"


AnyData setDouble(double value)
{
    AnyData ad;
    ad.type = DOUBLE;
    ad.value.dval = value;
    return ad;
}

AnyData setInt(int value)
{
    AnyData ad;
    ad.type = INT;
    ad.value.ival = value;
    return ad;
}

AnyData setString(char* value)
{
    AnyData ad;
    ad.type = STRING;
    strcpy(ad.value.sval, value);
    return ad;
}


void printDouble(double val)
{
    printf("D:%lf", val);
}

void printInt(int val)
{
    printf("I:%d", val);
}

void printString(char* val)
{
    printf("S:%s", val);
}

void printValue(AnyData val)
{
    switch(val.type)
    {
        case INT:
            printInt(val.value.ival);
            break;
        case DOUBLE:
            printDouble(val.value.dval);
            break;
        case STRING:
            printString(val.value.sval);
            break;
        case UNDEF:
            break;
    }
}
