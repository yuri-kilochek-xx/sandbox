#ifndef META_NEG_HPP
	#define META_NEG_HPP

	namespace meta
	{
		template <typename Arg>
		struct Neg
		{
			static decltype(-Arg::value) const = (-Arg::value);
		};
	}

#endif //META_NEG_HPP
