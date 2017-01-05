#include <stdio.h>

typedef unsigned int float_bits;

/*
 * Compute (int)f
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
int float_f2i(float_bits f)
{
	int result;
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f && 0x7FFFFF;

	frac = frac | 0x1000000;

	while(exp >> 1)
	{

	}
}
