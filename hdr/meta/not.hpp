#ifndef META_NOT_HPP
	#define META_NOT_HPP

	namespace meta
	{
		template <typename Arg>
		struct Not
		{
			static decltype(!Arg::value) const = (!Arg::value);
		};
	}

#endif //META_NOT_HPP
