
#include <stdio.h>
#include <algorithm>

struct _4
{
	union {
		uint8_t uc_[4];
		uint16_t us_[2];
		uint32_t ui_[1];
	};
	_4() {}
	~_4() {}
	_4(const _4& _) { ui_[0] = _.ui_[0]; }
	_4& operator=(const _4& _) { ui_[0] = _.ui_[0]; return *this; }
	_4(const uint8_t* begin) {
		uc_[0] = begin[0];
		uc_[1] = begin[1];
		uc_[2] = begin[2];
		uc_[3] = begin[3];
	}
	_4(const uint16_t* begin) {
		us_[0] = begin[0];
		us_[1] = begin[1];
	}
	void set(int idx, uint8_t uc) { uc_[idx] = uc; }
	void set(int idx, uint16_t us) { us_[idx] = us; }
	void set(uint32_t ui) { ui_[0] = ui; }
	uint8_t get(int idx, uint8_t) const { return uc_[idx]; }
	uint16_t get(int idx, uint16_t) const { return us_[idx]; }
	uint32_t get() const { return ui_[0]; }
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
	_4 i;
	_4 j(i);
	i = j;
	uint8_t c4[4] = {0x30, 0x31, 0x32, 0x33};
	_4 c4_1(&c4[0]);
	printf("%c\n", c4_1.get(3,uint8_t()));
	return c.uc_[0]-0x30; // 0
}

