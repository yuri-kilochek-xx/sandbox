#ifndef SAME_HPP
	#define SAME_HPP

	#include "bool.hpp"

	template <typename A, typename B>
	struct Same
	{
		static Bool const value = false;
	};

	template <typename T>
	struct Same<T, T>
	{
		static Bool const value = true;
	};

#endif //SAME_HPP
