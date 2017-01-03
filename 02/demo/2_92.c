#include <stdio.h>

typedef unsigned int float_bits;

/* compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f){
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;

	sign = ~sign;
	if((exp == 0xFF) && (frac > 0))
		sign = ~sign;
	
	return (sign << 31) | (exp << 23) | frac;
}

void show_bytes(unsigned char *p, size_t len)
{
	for(int i = len -1 ; i >= 0; i--)
	{
		printf("%.2x",p[i]);
	}
	printf("\n");
}

int main()
{
	float_bits val = 1;
	float_bits negateVal = float_negate(val);
	show_bytes((unsigned char *) &negateVal, sizeof(unsigned int));

	float fval =(float) (1>>31);//*-126;
	show_bytes((unsigned char *) &fval, sizeof(float));
//	printf("%u\n",float_negate(val));
	return 0;
}

