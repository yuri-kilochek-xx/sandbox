#ifndef DEL_REF_HPP
	#define DEL_REF_HPP

	template <typename T>
	struct DelRef
	{
		typedef T Type;
	};
	template <typename T>
	struct DelRef<T&>
	{
		typedef T Type;
	};
	template <typename T>
	struct DelRef<T&&>
	{
		typedef T Type;
	};

#endif //DEL_REF_HPP
