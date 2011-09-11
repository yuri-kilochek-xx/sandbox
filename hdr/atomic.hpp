#ifndef ATOMIC_HPP
	#define ATOMIC_HPP

	#include "int_n.hpp"
	#include "size.hpp"

	template <typename T>
	class Atomic;



	template <>
	class Atomic<Int32>
	{
		private:

			Int32 volatile mutable _data;

		public:

			Atomic()
				: _data(0)
			{

			}
			Atomic(Atomic const&) = delete;
			Atomic& operator=(Atomic const&) = delete;

			Int32 get() const;
			Int32 set(Int32 val);
			Int32 cas(Int32 val, Int32 cmp);

			Int32 get_inc();
			Int32 get_dec();
			Int32 get_add(Int32 val);
			Int32 get_sub(Int32 val);

			Int32 inc_get();
			Int32 dec_get();
			Int32 add_get(Int32 val);
			Int32 sub_get(Int32 val);
	};

	template <>
	class Atomic<UInt32>
	{
		private:

			UInt32 volatile mutable _data;

		public:

			Atomic()
				: _data(0)
			{

			}
			Atomic(Atomic const&) = delete;
			Atomic& operator=(Atomic const&) = delete;


			UInt32 get() const;
			UInt32 set(UInt32 val);
			UInt32 cas(UInt32 val, UInt32 cmp);

			UInt32 get_inc();
			UInt32 get_dec();
			UInt32 get_add(UInt32 val);
			UInt32 get_sub(UInt32 val);

			UInt32 inc_get();
			UInt32 dec_get();
			UInt32 add_get(UInt32 val);
			UInt32 sub_get(UInt32 val);
	};


	template <>
	class Atomic<Int64>
	{
		private:

			Int64 volatile mutable _data;

		public:

			Atomic()
				: _data(0)
			{

			}
			Atomic(Atomic const&) = delete;
			Atomic& operator=(Atomic const&) = delete;

			Int64 get() const;
			Int64 set(Int64 val);
			Int64 cas(Int64 val, Int64 cmp);

			Int64 get_inc();
			Int64 get_dec();
			Int64 get_add(Int64 val);
			Int64 get_sub(Int64 val);

			Int64 inc_get();
			Int64 dec_get();
			Int64 add_get(Int64 val);
			Int64 sub_get(Int64 val);
	};

	template <>
	class Atomic<UInt64>
	{
		private:

			UInt64 volatile mutable _data;

		public:

			Atomic()
				: _data(0)
			{

			}
			Atomic(Atomic const&) = delete;
			Atomic& operator=(Atomic const&) = delete;

			UInt64 get() const;
			UInt64 set(UInt64 val);
			UInt64 cas(UInt64 val, UInt64 cmp);

			UInt64 get_inc();
			UInt64 get_dec();
			UInt64 get_add(UInt64 val);
			UInt64 get_sub(UInt64 val);

			UInt64 inc_get();
			UInt64 dec_get();
			UInt64 add_get(UInt64 val);
			UInt64 sub_get(UInt64 val);
	};


	template <typename T>
	class Atomic<T*>
	{
		private:

			Atomic<UIntPtr> _ptr;

		public:

			Atomic()
			{

			}
			Atomic(Atomic const&) = delete;
			Atomic& operator=(Atomic const&) = delete;


			T* get() const
			{
				return (T*)_ptr.get();
			}
			T* set(T* val)
			{
				return (T*)_ptr.set((UIntPtr)val);
			}
			T* cas(T* val, T const* cmp)
			{
				return (T*)_ptr.cas((UIntPtr)val, (UIntPtr)cmp);
			}

			T* inc_get()
			{
				return (T*)_ptr.add_get(sizeof(T));
			}
			T* dec_get()
			{
				return (T*)_ptr.sub_get(sizeof(T));
			}
			T* add_get(UIntPtr val)
			{
				return (T*)_ptr.add_get(sizeof(T)*val);
			}
			T* sub_get(UIntPtr val)
			{
				return (T*)_ptr.sub_get(sizeof(T)*val);
			}
	};



#endif //ATOMIC_HPP
