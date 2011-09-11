#ifndef IF_HPP
	#define IF_HPP

	#include "bool.hpp"

	template <Bool condition, typename TrueType, typename... OptionalFalseType>
	struct If;

	template <typename TrueType>
	struct If<true, TrueType>
	{
		typedef TrueType Type;
	};

	template <typename TrueType>
	struct If<false, TrueType>
	{

	};

	template <typename TrueType, typename FalseType>
	struct If<true, TrueType, FalseType>
	{
		typedef TrueType Type;
	};

	template <typename TrueType, typename FalseType>
	struct If<false, TrueType, FalseType>
	{
		typedef FalseType Type;
	};

#endif //IF_HPP
