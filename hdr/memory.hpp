#ifndef MEMORY_HPP
	#define MEMORY_HPP

	#include "size.hpp"
	#include "byte.hpp"
	#include "void.hpp"
	#include "cast.hpp"
	#include "self.hpp"

	template <typename T, typename... Args>
	inline T* const create(Void* ptr, Args&&... args)
	{
		return new (ptr) T(cast_static<Args&&>(args)...);
	}

	template <typename T>
	inline Void remove(typename Self<T*>::Type ptr)
	{
		ptr->~T();
	}

	template <Size delta, typename T>
	inline T* align(T* ptr)
	{
		static_assert((!(delta & (delta-1)) && (delta != 0)), "Align delta is not a power of two");
		return (T*)((Size(ptr) + (delta-1)) & ~(delta-1));
	}

	template <typename... OptionalTag>
	class Memory;

	template <>
	class Memory<>
	{
		public:

			static Byte* const grab(Size size);
			static Void free(Byte* ptr);
	};

	template <typename Tag>
	class Memory<Tag>
	{
		public:

			static Byte* const grab(Size size)
			{
				return Memory<>::grab(size);
			}
			static Void free(Byte* ptr)
			{
				Memory<>::free(ptr);
			}
	};

#endif //MEMORY_HPP
