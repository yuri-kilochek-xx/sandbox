#ifndef META_BIT_NOT_HPP
	#define META_BIT_NOT_HPP

	namespace meta
	{
		template <typename Arg>
		struct BitNot
		{
			static decltype(~Arg::value) const = (~Arg::value);
		};
	}

#endif //META_BIT_NOT_HPP
