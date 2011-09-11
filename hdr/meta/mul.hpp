#ifndef META_MUL_HPP
	#define META_MUL_HPP

	namespace meta
	{
		template <typename... Args>
		struct Mul;
		template <typename Head, typename... Rest>
		struct Mul<Head, Rest...>
		{
			static decltype(Head::value * Mul<Rest...>::value) const value = (Head::value * Mul<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct Mul<Head, Rest>
		{
			static decltype(Head::value * Rest::value) const value = (Head::value * Rest::value);
		};
	}

#endif //META_MUL_HPP
