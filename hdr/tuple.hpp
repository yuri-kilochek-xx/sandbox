#ifndef TUPLE_HPP
	#define TUPLE_HPP

	#include "if.hpp"
	#include "size.hpp"
	#include "swap.hpp"
	#include "cast.hpp"
	#include "same.hpp"
	#include "type_at.hpp"

	template <typename...>
	class Tuple;

	Void swap(Tuple<>*, Tuple<>*);

	template <>
	class Tuple<>
	{
		friend Void swap(Tuple<>*, Tuple<>*);
		public:

			static Size const arity = 0;

			Tuple()
			{

			}
			Tuple(Tuple const& that)
			{

			}
			Tuple& operator=(Tuple const& that)
			{
				return *this;
			}

	};

	inline Void swap(Tuple<>*, Tuple<>*)
	{

	}




	template <typename Head>
	Void swap(Tuple<Head>*, Tuple<Head>*);

	template <typename Head>
	class Tuple<Head>
	{
		template <typename...>
		friend class Tuple;

		friend Void swap<Head>(Tuple<Head>*, Tuple<Head>*);

		private:

			Head _head;

		public:

			static Size const arity = 1;

			template <Size const index>
			typename If<(index == 0), Head&>::Type at()
			{
				return _head;
			}

			template <Size const index>
			typename If<(index == 0), Head const&>::Type at() const
			{
				return _head;
			}

			Tuple()
				: _head()
			{

			}
			Tuple(Tuple const& that)
				: _head(that._head)
			{

			}
			Tuple(Tuple&& that)
				: _head(cast_static<Head&&>(that._head))
			{

			}
			Tuple& operator=(Tuple const& that)
			{
				_head = that._head;
				return *this;
			}
			Tuple& operator=(Tuple&& that)
			{
				_head = cast_static<Head&&>(that._head);
				return *this;
			}


			template <typename ThatHead>
			Tuple(Tuple<ThatHead> const& that)
				: _head(that._head)
			{

			}
			template <typename ThatHead>
			Tuple& operator=(Tuple<ThatHead> const& that)
			{
				_head = that._head;
				return *this;
			}

			Tuple(Head const& head)
				: _head(head)
			{

			}

//			Tuple(Head&& head)
//				:	_head(cast_static<Head&&>(head))
//			{
//
//			}
	};

	template <typename Head>
	inline Void swap(Tuple<Head>* a, Tuple<Head>* b)
	{
		swap(&a->_head, &b->_head);
	}







	template <typename Head, typename... Rest>
	Void swap(Tuple<Head, Rest...>*, Tuple<Head, Rest...>*);

	template <typename Head, typename... Rest>
	class Tuple<Head, Rest...>
	{
		template <typename...>
		friend class Tuple;

		friend Void swap<Head, Rest...>(Tuple<Head, Rest...>*, Tuple<Head, Rest...>*);

		private:

			Head _head;
			Tuple<Rest...> _rest;

		public:

			static Size const arity = Tuple<Rest...>::arity + 1;

			template <Size const index>
			typename If<(index == 0), Head&>::Type at()
			{
				return _head;
			}
			template <Size const index>
			typename If<(index != 0), typename TypeAt<index, Head, Rest...>::Type&>::Type at()
			{
				return _rest.at<index-1>();
			}


			template <Size const index>
			typename If<(index == 0), Head const&>::Type at() const
			{
				return _head;
			}
			template <Size const index>
			typename If<(index != 0), typename TypeAt<index, Head, Rest...>::Type const&>::Type at() const
			{
				return _rest.at<index-1>();
			}

			Tuple()
				: _head()
				, _rest()
			{

			}
			Tuple(Tuple const& that)
				: _head(that._head)
				, _rest(that._rest)
			{

			}
			Tuple(Tuple&& that)
				: _head(cast_static<Head&&>(that._head))
				, _rest(cast_static<Tuple<Rest...>&&>(that._rest))
			{

			}
			Tuple& operator=(Tuple const& that)
			{
				_head = that._head;
				_rest = that._rest;
				return *this;
			}
			Tuple& operator=(Tuple&& that)
			{
				_head = cast_static<Head&&>(that._head);
				_rest = cast_static<Tuple<Rest...>&&>(that._rest);
				return *this;
			}


			template <typename ThatHead, typename... ThatRest>
			Tuple(Tuple<ThatHead, ThatRest...> const& that)
				: _head(that._head)
				, _rest(that._rest)
			{

			}
			template <typename ThatHead, typename... ThatRest>
			Tuple& operator=(Tuple<ThatHead, ThatRest...> const& that)
			{
				_head = that._head;
				_rest = that._rest;
				return *this;
			}

			Tuple(Head const& head, Rest&&... rest)
				: _head(head)
				, _rest(cast_static<Rest&&>(rest)...)
			{

			}

//			Tuple(Head&& head, Rest&&... rest)
//				:	_head(cast_static<Head&&>(head))
//				,	_rest(cast_static<Rest&&>(rest)...)
//			{
//
//			}

	};

	template <typename Head, typename... Rest>
	inline Void swap(Tuple<Head, Rest...>* a, Tuple<Head, Rest...>* b)
	{
		swap(&a->_head, &b->_head);
		swap(&a->_rest, &b->_rest);
	}



	template <template <typename...> class Type, typename... Args>
	inline typename If<Same<Tuple<Args...>, Type<Args...>>::value, Tuple<Args...>>::Type make(Args&&... args)
	{
		return Tuple<Args...>(cast_static<Args&&>(args)...);
	}

	template <typename... Args>
	inline Tuple<Args&...> tie(Args&... args)
	{
		return Tuple<Args&...>(args...);
	}


#endif //TUPLE_HPP
