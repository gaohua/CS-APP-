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
C.!(~(x&0xFF)^0xFF)
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
