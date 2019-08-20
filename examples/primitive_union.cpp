
#include <stdio.h>

struct _4
{
	union {
		uint8_t uc_[4];
		uint16_t us_[2];
		uint32_t ui_[1];
	};
};

struct _8
{
	union {
		uint8_t uc_[8];
		uint16_t us_[4];
		uint32_t ui_[2];
		uint64_t ul_[1];
		double d_[1];
	};
};

struct _16
{
	union {
		uint8_t uc_[16];
		uint16_t us_[8];
		uint32_t ui_[4];
		uint64_t ul_[2];
		double d_[2];
		long double ld_[1];
	};
};

struct _32
{
	union {
		uint8_t uc_[32];
		uint16_t us_[16];
		uint32_t ui_[8];
		uint64_t ul_[4];
		double d_[4];
		long double ld_[2];
	};
};

int main()
{
	printf("%d\n", sizeof(_4));
	printf("%d\n", sizeof(_8));
	printf("%d\n", sizeof(_16));
	printf("%d\n", sizeof(_32));
	_8 c;
	c.uc_[0] = '0';
	return c.uc_[0]-0x30; // 0
}

