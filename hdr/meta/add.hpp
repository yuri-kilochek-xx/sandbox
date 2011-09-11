#ifndef META_ADD_HPP
	#define META_ADD_HPP

	namespace meta
	{
		template <typename... Args>
		struct Add;
		template <typename Head, typename... Rest>
		struct Add<Head, Rest...>
		{
			static decltype(Head::value + Add<Rest...>::value) const value = (Head::value + Add<Rest...>::value);
		};
		template <typename Head, typename Rest>
		struct Add<Head, Rest>
		{
			static decltype(Head::value + Rest::value) const value = (Head::value + Rest::value);
		};
	}

#endif //META_ADD_HPP
