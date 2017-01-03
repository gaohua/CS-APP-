### 2.59:
```c
(x & 0xFF) + (y & ~(0xFF))
```

### 2.60
```c
unsigned replace_byte (unsigned x, int i, unsigned char b)
{
	unsigned result = 0;
	unsigned uval = (unsigned)b;

	int y = 0xff << (i * 8);
	uval = uval << (i * 8);

	result = (x ^ uval) ^ (x & y);

	return result;
}            
```
上面这个代码可读性比较差啊，下面重新整理一下
```c
unsigned replace_byte (unsigned x, int i, unsigned char b)
{
	unsigned uval = (unsigned)b;
	int shift = i << 3;
	unsigned mask  = 0xff << shift;
	uval = uval << shift;

	return ((x^uval) ^ (x&mask));
}
```
### 2.61
```c
A.!(~x)
B.!x
C.!((x&0xFF)^0xFF)
D.!((x>>((sizeof(int)-1)<<3))&0xFF)
```
### 2.62
```c
int int_shifts_are_arithmetic()
{
	int ival = ~0;
	return !(~(ival >> 1));
}
```
### 2.63
```c
unsigned srl(unsigned x, int k){
	/*Perform shift arithmetically*/
	unsigned xsra = (int) x >> k;

	/*yield shift logically*/
	return xsra & ~((~0) << ((8 * sizeof(int)) - k));
}

int sra(int x, int k){
	/*Perform shift logically*/
	int xsrl = (unsigned) x >> k;
	/*yield shift arithmetically*/
	return xsrl | ((~0) << ((8 * sizeof(int)) - k));
}
```
### 2.64
题目说我们可以假设int类型是32位的，这样的话降低了这道题的难度，用下面这种方法就可以解决，但可移植性不强。
```c
	int any_odd_one(unsigned x){
		return !(x^0xaaaaaaaa);
	}
```
可移植性强的版本
```c
	int any_odd_one(unsigned x){
			unsigned mask = x >> 1;
			return !(~(x ^ mask));
	}
```
### 2.68
```c
/*
 * 注意： ～0 >> n 和 （unsigned)~0 >> n
*/
int lower_one_mask(int n){
	unsigned mask = ~0;
	return mask >> ((sizeof(int)<<3)-n);
}
```
### 2.92
```c
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
```
### 2.93
```c
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

```
