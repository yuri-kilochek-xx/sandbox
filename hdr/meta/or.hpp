#ifndef META_OR_HPP
	#define META_OR_HPP

	namespace meta
	{
		template <typename... Args>
		struct Or;
		template <typename Head, typename... Rest>
		struct Or<Head, Rest...>
		{
			static decltype(Head::value || Or<Rest...>::value) const value = (Head::value || Or<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct Or<Head, Rest>
		{
			static decltype(Head::value || Rest::value) const value = (Head::value || Rest::value);
		};
	}

#endif //META_OR_HPP
