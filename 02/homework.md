### 2.59:
```c
(x & 0x000000FF) + (y & 0xFFFFFF00)
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
