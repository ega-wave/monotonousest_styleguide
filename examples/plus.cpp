
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

