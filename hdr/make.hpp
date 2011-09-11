#ifndef MAKE_HPP
	#define MAKE_HPP

	#include "cast.hpp"

	template <typename Type, typename...Args>
	Type make(Args&&... args)
	{
		return Type(cast_static<Args&&>(args)...);
	}

#endif //MAKE_HPP
