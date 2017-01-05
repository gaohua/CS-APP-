#include <stdio.h>

typedef unsigned float_bits;

/* compute 2*f. if f is NaN, return f. */
float_bits float_twice(float_bits f)
{
    float_bits result;
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if((exp == 0xFF) && frac != 0)
    {
        result = f;
    }
    else
        result = (sign << 31) | ((exp + 1) << 23) | frac;

    return result;
}
