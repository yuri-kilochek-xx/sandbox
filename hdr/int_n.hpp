#ifndef INT_N_HPP
	#define INT_N_HPP

	#include "int.hpp"
	#include "size.hpp"
	#include "if.hpp"

	namespace _impl
	{
		namespace _Int
		{
			template <Size index>
			struct Holder
			{
				static Size const size = 0;
			};


			template <>
			struct Holder<0>
			{
				typedef IntTiny Type;
				typedef UIntTiny UType;
				static Size const size = sizeof(Type);
			};

			template <>
			struct Holder<1>
			{
				typedef IntShort Type;
				typedef UIntShort UType;
				static Size const size = sizeof(Type);
			};

			template <>
			struct Holder<2>
			{
				typedef Int Type;
				typedef UInt UType;
				static Size const size = sizeof(Type);
			};

			template <>
			struct Holder<3>
			{
				typedef IntLong Type;
				typedef UIntLong UType;
				static Size const size = sizeof(Type);
			};

			template <>
			struct Holder<4>
			{
				typedef IntHuge Type;
				typedef UIntHuge UType;
				static Size const size = sizeof(Type);
			};


			template <Size size, Size index = 0>
			struct ByByteSize : public If<(size == Holder<index>::size), Holder<index>, ByByteSize<size, index+1>>::Type
			{

			};
		}
	}

	template <Size bits>
	struct IntExact
	{
		static_assert((8 <= bits), "Amount if bits is less than eight");
		static_assert(!(bits & (bits-1)), "Amount if bits is not a power of two");

		typedef typename _impl::_Int::ByByteSize<bits/8>::Type Type;
	};

	template <Size bits>
	struct UIntExact
	{
		static_assert((8 <= bits), "Amount if bits is less than eight");
		static_assert(!(bits & (bits-1)), "Amount if bits is not a power of two");

		typedef typename _impl::_Int::ByByteSize<bits/8>::UType Type;
	};

	typedef IntExact<8>::Type Int8;
	typedef UIntExact<8>::Type UInt8;

	typedef IntExact<16>::Type Int16;
	typedef UIntExact<16>::Type UInt16;

	typedef IntExact<32>::Type Int32;
	typedef UIntExact<32>::Type UInt32;

	typedef IntExact<64>::Type Int64;
	typedef UIntExact<64>::Type UInt64;

	typedef IntExact<sizeof(void*)*8>::Type IntPtr;
	typedef UIntExact<sizeof(void*)*8>::Type UIntPtr;

#endif //INT_N_HPP
