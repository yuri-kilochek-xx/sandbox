#ifndef META_BIT_AND_HPP
	#define META_BIT_AND_HPP

	namespace meta
	{
		template <typename... Args>
		struct BitAnd;
		template <typename Head, typename... Rest>
		struct BitAnd<Head, Rest...>
		{
			static decltype(Head::value & BitAnd<Rest...>::value) const value = (Head::value & BitAnd<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct BitAnd<Head, Rest>
		{
			static decltype(Head::value & Rest::value) const value = (Head::value & Rest::value);
		};
	}

#endif //META_BIT_AND_HPP
