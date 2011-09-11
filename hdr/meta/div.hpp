#ifndef META_DIV_HPP
	#define META_DIV_HPP

	namespace meta
	{
		template <typename Head, typename Rest>
		struct Div<Head, Rest>
		{
			static decltype(Head::value / Rest::value) const value = (Head::value / Rest::value);
		};
	}

#endif //META_DIV_HPP
