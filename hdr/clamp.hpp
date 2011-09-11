#ifndef CLAMP_HPP
	#define CLAMP_HPP

	template <typename Type>
	inline Type const clamp(Type const& a, Type const& x, Type const& b)
	{
		if (x < a)
			return a;
		else if (b < x)
			return b;
		else
			return x;
	}

	template <typename Type, typename Cmp>
	inline Type const clamp(Type const& a, Type const& x, Type const& b, Cmp cmp)
	{
		if (cmp(x, a))
			return a;
		else if (cmp(b, x))
			return b;
		else
			return x;
	}

#endif //CLAMP_HPP
