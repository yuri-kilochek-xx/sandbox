#ifndef META_SELF_HPP
	#define META_SELF_HPP

	namespace meta
	{
		template <typename T>
		struct Self
		{
			typedef T Type;
		};
	}

#endif //META_SELF_HPP
