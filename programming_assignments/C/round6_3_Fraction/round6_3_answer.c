#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

Fraction* setFraction(unsigned int numerator, unsigned int denominator)
{
    Fraction *f = malloc(sizeof(struct fraction_st));
    f->numerator = numerator;
    f->denominator = denominator;
    return f;
}

unsigned int getNum(const Fraction *f)
{
    return f->numerator;
}

unsigned int getDenom(const Fraction *f)
{
    return f->denominator;

}

void freeFraction(Fraction *f)
{
    free(f);
}

void make_similar(Fraction *a, Fraction *b)
{
    unsigned int d = a->denominator;
    if (a->denominator != b->denominator) {
        a->numerator *= b->denominator;
        a->denominator *= b->denominator;
        b->numerator *= d;
        b->denominator *= d;
    }
}

int compFraction(const Fraction *a, const Fraction *b)
{
    Fraction fa = *a, fb = *b;
    make_similar(&fa, &fb);  // ensure that the denominators are same
    if (fa.numerator < fb.numerator)
        return -1;
    else if (fa.numerator == fb.numerator)
        return 0;
    else
        return 1;
}

Fraction* addFraction(const Fraction *a, const Fraction *b)
{
    Fraction fa = *a, fb = *b;
    make_similar(&fa, &fb);  // ensure that denominators are same
    Fraction *res = malloc(sizeof(struct fraction_st));
    res->numerator = fa.numerator + fb.numerator;
    res->denominator = fa.denominator;
    return res;
}


void reduceFraction(Fraction* val)
{
    unsigned int div = gcd(val->numerator, val->denominator);
    val->numerator = val->numerator / div;
    val->denominator = val->denominator / div;
}
