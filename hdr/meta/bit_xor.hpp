#ifndef META_BIT_XOR_HPP
	#define META_BIT_XOR_HPP

	namespace meta
	{
		template <typename... Args>
		struct BitXor;
		template <typename Head, typename... Rest>
		struct BitXor<Head, Rest...>
		{
			static decltype(Head::value ^ BitXor<Rest...>::value) const value = (Head::value ^ BitXor<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct BitXor<Head, Rest>
		{
			static decltype(Head::value ^ Rest::value) const value = (Head::value ^ Rest::value);
		};
	}

#endif //META_BIT_XOR_HPP
