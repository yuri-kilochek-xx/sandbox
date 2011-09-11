#ifndef META_AND_HPP
	#define META_AND_HPP

	namespace meta
	{
		template <typename... Args>
		struct And;
		template <typename Head, typename... Rest>
		struct And<Head, Rest...>
		{
			static decltype(Head::value && And<Rest...>::value) const value = (Head::value && And<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct And<Head, Rest>
		{
			static decltype(Head::value && Rest::value) const value = (Head::value && Rest::value);
		};
	}

#endif //META_AND_HPP
