### 2.59:
```c
(x & 0x000000FF) + (y & 0xFFFFFF00)
```

### 2.60
```c
unsigned replace_byte (unsigned x, int i, unsigned char b)
{
	unsigned result = 0;
	unsigned ival = (unsigned)b;

	int y = 0xff << (i * 8);
	ival = ival << (i * 8);

	result = (x ^ ival) ^ (x & y);

	return result;
}            
```
