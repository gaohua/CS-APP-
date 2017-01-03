#include <stdio.h>

typedef unsigned int float_bits;

/* compute |f|. if f is NaN, then return f. */
float_bits float_absval(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFF;
	
	unsigned tmp = sign ^ sign;	
	if((exp == 0xFF) && frac > 0)
	{
		tmp = sign;	
	}

	sign = tmp;

	return (sign<<31) | (exp<<23) | frac;
}

int main()
{
		
	return 0;
}
