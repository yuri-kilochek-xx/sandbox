#ifndef META_SUB_HPP
	#define META_SUB_HPP

	namespace meta
	{
		template <typename Head, typename Rest>
		struct Sub<Head, Rest>
		{
			static decltype(Head::value - Rest::value) const value = (Head::value - Rest::value);
		};
	}

#endif //META_SUB_HPP
