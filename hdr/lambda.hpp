#ifndef LAMBDA_HPP
	#define LAMBDA_HPP

	#include "value_at.hpp"
	#include "type_at.hpp"
	#include "size.hpp"


	namespace lambda
	{
		template <typename Tag>
		class Expr;





		template <Size index>
		class TagArg {};

		template <Size index>
		class Expr<TagArg<index>>
		{
			public:
				template <typename... Args>
				typename TypeAt<index, Args...>::Type operator()(Args... args) const
				{
					return value_at<index>(args...);
				}
		};

		template <Size index>
		inline Expr<TagArg<index>> arg()
		{
			return Expr<TagArg<index>>();
		}

		Expr<TagArg<0x0>> const _0 = {};
		Expr<TagArg<0x1>> const _1 = {};
		Expr<TagArg<0x2>> const _2 = {};
		Expr<TagArg<0x3>> const _3 = {};
		Expr<TagArg<0x4>> const _4 = {};
		Expr<TagArg<0x5>> const _5 = {};
		Expr<TagArg<0x6>> const _6 = {};
		Expr<TagArg<0x7>> const _7 = {};
		Expr<TagArg<0x8>> const _8 = {};
		Expr<TagArg<0x9>> const _9 = {};
		Expr<TagArg<0xA>> const _A = {};
		Expr<TagArg<0xB>> const _B = {};
		Expr<TagArg<0xC>> const _C = {};
		Expr<TagArg<0xD>> const _D = {};
		Expr<TagArg<0xE>> const _E = {};
		Expr<TagArg<0xF>> const _F = {};





		template <typename T>
		class TagVal;

		template <typename T>
		class Expr<TagVal<T>>
		{
			private:

				T _t;

			public:

				Expr(T const& t)
					: _t(t)
				{

				}

				template <typename... Args>
				T operator()(Args... args) const
				{
					return _t;
				}
		};

		template <typename T>
		Expr<TagVal<T>> val(T const& t)
		{
			return Expr<TagVal<T>>(t);
		}






		template <typename T>
		class TagRef;

		template <typename T>
		class Expr<TagRef<T>>
		{
			private:

				T& _t;

			public:

				Expr(T& t)
					: _t(t)
				{

				}

				template <typename... Args>
				T& operator()(Args... args) const
				{
					return _t;
				}
		};

		template <typename T>
		Expr<TagRef<T>> ref(T& t)
		{
			return Expr<TagRef<T>>(t);
		}




		template <typename F>
		class TagFun;

		template <typename F>
		class Expr<TagFun<F>>
		{
			private:
			public:

				F _f;



				Expr(F f)
					: _f(f)
				{

				}

				template <typename... Args>
				decltype(_f(Args()...)) operator()(Args... args) const
				{
					return _f(args...);
				}
		};

		template <typename F>
		Expr<TagFun<F>> fun(F f)
		{
			return Expr<TagFun<F>>(f);
		}











		template <typename TagL, typename TagR>
		class TagBinaryPlus;

		template <typename TagL, typename TagR>
		class Expr<TagBinaryPlus<TagL, TagR>>
		{
			private:
			public:

				Expr<TagL> _l;
				Expr<TagR> _r;



				Expr(Expr<TagL> l, Expr<TagR> r)
					: _l(l)
					, _r(r)
				{

				}

				template <typename... Args>
				decltype(_l(Args()...)+_r(Args()...)) operator()(Args... args) const
				{
					return _l(args...)+_r(args...);
				}
		};

		template <typename TagL, typename TagR>
		Expr<TagBinaryPlus<TagL, TagR>> operator+(Expr<TagL> l, Expr<TagR> r)
		{
			return Expr<TagBinaryPlus<TagL, TagR>>(l, r);
		}
	}

#endif //LAMBDA_HPP
