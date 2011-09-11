#ifndef MAX_HPP
	#define MAX_HPP

	template <typename T>
	inline T const max(T const& a, T const& b)
	{
		return a < b ? b : a;
	}

	template <typename T, typename Cmp>
	inline T const max(T const& a, T const& b, Cmp cmp)
	{
		return cmp(a, b) ? b : a;
	}

#endif //MAX_HPP
