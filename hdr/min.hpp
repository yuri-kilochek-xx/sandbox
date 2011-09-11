#ifndef MIN_HPP
	#define MIN_HPP

	template <typename T>
	inline T const min(T const& a, T const& b)
	{
		return a < b ? a : b;
	}

	template <typename T, typename Cmp>
	inline T const min(T const& a, T const& b, Cmp cmp)
	{
		return cmp(a, b) ? a : b;
	}

#endif //MIN_HPP
