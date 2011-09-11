#ifndef META_BIT_OR_HPP
	#define META_BIT_OR_HPP

	namespace meta
	{
		template <typename... Args>
		struct BitOr;
		template <typename Head, typename... Rest>
		struct BitOr<Head, Rest...>
		{
			static decltype(Head::value | BitOr<Rest...>::value) const value = (Head::value | BitOr<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct BitOr<Head, Rest>
		{
			static decltype(Head::value | Rest::value) const value = (Head::value | Rest::value);
		};
	}

#endif //META_BIT_OR_HPP
