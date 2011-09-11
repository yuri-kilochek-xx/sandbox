#ifndef SWAP_HPP
	#define SWAP_HPP

	#include "void.hpp"
	#include "cast.hpp"

	template <typename T>
	inline Void swap(T* a, T* b)
	{
		T t(cast_static<T&&>(*a));
		*a = cast_static<T&&>(*b);
		*b = cast_static<T&&>(t);
	}

#endif //SWAP_HPP
