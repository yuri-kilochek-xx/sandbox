#ifndef META_MOD_HPP
	#define META_MOD_HPP

	namespace meta
	{
		template <typename Head, typename Rest>
		struct Mod<Head, Rest>
		{
			static decltype(Head::value % Rest::value) const value = (Head::value % Rest::value);
		};
	}

#endif //META_MOD_HPP
