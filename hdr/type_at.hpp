#ifndef TYPE_AT_HPP
	#define TYPE_AT_HPP

	#include "size.hpp"

	template <Size index, typename... Types>
	struct TypeAt;

	template <Size index, typename Head, typename... Rest>
	struct TypeAt<index, Head, Rest...>
	{
		typedef typename TypeAt<index-1, Rest...>::Type Type;
	};

	template <typename Head, typename... Rest>
	struct TypeAt<0, Head, Rest...>
	{
		typedef Head Type;
	};

#endif //TYPE_AT_HPP
