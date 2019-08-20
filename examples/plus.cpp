
template <typename T>
struct plus
{
	T operator()() const;
	T _1;
	T _2;
};

template <typename T>
T plus<T>::operator()() const
{
	return _1 + _2;
}

int main()
{
	plus<unsigned int> p;
	p._1 = (unsigned int)1;
	p._2 = (unsigned int)2;
	return p();
}

// numbering primitive-type according bit-width
// a 1-bit
// b 8-bit
// c 16-bit
// d 32-bit
// e 64-bit
// f 128-bit
// examples
struct d
{
	unsigned int d_;
};

struct f
{
	union
	{
		long double _1;
		unsigned long long _2;
	}
};

struct dd : public d
{
	d 2_;
};

struct ee : public e
{
	e 2_;
};

struct fee : public ee // sort descendantly
{
	f 3_;
};

struct plus : public dd
{
	d operator()()
	{
		d& lhs = this->dd::2_.d::1_;
		d& rhs = this->dd::2_;
		return rhs + lhs;
	}
};

