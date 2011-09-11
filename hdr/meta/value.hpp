#ifndef META_VALUE_HPP
	#define META_VALUE_HPP

	namespace meta
	{
		template <typename T, T val>
		struct Value
		{
			static T const value = val;
		};
	}

#endif //META_VALUE_HPP
