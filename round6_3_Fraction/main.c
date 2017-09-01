#include <stdio.h>
#include "fraction.h"
#include<stdlib.h>
#include<assert.h>
Fraction* setFraction(unsigned int numerator, unsigned int denominator)
{
    Fraction *f=malloc(sizeof(struct fraction_st));
    f->num=numerator;
    f->den=denominator;
    return f;
}
void freeFraction(Fraction* f)
{
    assert(f);
    free(f);
}
unsigned int getNum(const Fraction *f)
{
    assert(f);
    return f->num;
}
unsigned int getDenom(const Fraction *f)
{
    assert(f);
    return f->den;
}
//b
int compFraction(const Fraction *a, const Fraction *b)
{
    assert(a);
    assert(b);
    float c= (float)a->num/(float)a->den;
    float d= (float)b->num/(float)b->den;
    if(c<d)
    {
        return -1;
    }
    else if(c==d)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//c
Fraction* addFraction(const Fraction *a, const Fraction *b)
{
    Fraction *c=malloc(sizeof(struct fraction_st));
    c->num = (a->num)*(b->den)+(b->num)*(a->den);
    c->den= (a->den)*(b->den);
    return c;
}
void reduceFraction(Fraction *val)
{   int i=1;
    int gcd=0;
    if(val->den==val->num)
    {
         val->den=1;
         val->num=1;
    }
    else if(val->num==0)
    {
        val->den=0;
        val->num=0;
    }
    else
    {
         for(i=1;i<=(val->num) && i<=(val->den);++i)
         {
             if((val->num)%i==0 && (val->den)%i==0)
             {
                 gcd=i;
             }
         }
         val->num=val->num/gcd;
         val->den=val->den/gcd;
    }

}
void printFraction(const Fraction *val)
{
    printf("%d/%d",val->num,val->den);
}
int main()
{
    /* Hint: if you have implemented only part of the functions,
       add comments around those that you didn't yet implement.
       Feel free to modify this function as you wish. It is not checked
       by the tester.*/

    /* The below code uses function printFraction. Implementing it will not
     * gain you points, but will be useful for testing */

    Fraction *a = setFraction(2,3);
    Fraction *b = setFraction(3,4);

    Fraction *sum = addFraction(a, b);
    printFraction(sum);
    printf("\n");

    printf("Result of comparison: %d\n", compFraction(a,b));

    Fraction *mul = setFraction(6,12);
    reduceFraction(mul);
    printFraction(mul);

    freeFraction(a);
    freeFraction(b);
    freeFraction(sum);
    freeFraction(mul);
    return 0;
}
