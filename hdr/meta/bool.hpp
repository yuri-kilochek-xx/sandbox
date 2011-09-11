#ifndef META_BOOL_HPP
	#define META_BOOL_HPP

	#include "../bool.hpp"
	#include "value.hpp"

	namespace meta
	{
		template <::Bool val>
		struct Bool : public Value<::Bool, val>
		{
		};
	}

#endif //META_BOOL_HPP
