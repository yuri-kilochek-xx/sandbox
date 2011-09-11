#ifndef CAST_HPP
	#define CAST_HPP

	template <typename T, typename U>
	inline T cast_static(U&& u)
	{
		return static_cast<T>(u);
	}

	template <typename T, typename U>
	inline T cast_dynamic(U&& u)
	{
		return dynamic_cast<T>(u);
	}

	template <typename T, typename U>
	inline T cast_const(U&& u)
	{
		return const_cast<T>(u);
	}

	template <typename T, typename U>
	inline T cast_reinterpret(U&& u)
	{
		return reinterpret_cast<T>(u);
	}

#endif //CAST_HPP
