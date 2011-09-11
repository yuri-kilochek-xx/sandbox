#ifndef VALUE_AT_HPP
	#define VALUE_AT_HPP

	#include "size.hpp"
	#include "type_at.hpp"

	template <Size index, typename T, T... values>
	struct ValueAt;

	template <Size index, typename T, T head, T... rest>
	struct ValueAt<index, T, head, rest...>
	{
		static T const value = ValueAt<index-1, T, rest...>::value;
	};

	template <typename T, T head, T... rest>
	struct ValueAt<0, T, head, rest...>
	{
		static T const value = head;
	};

	namespace _impl
	{
		namespace _value_at
		{
			template <Size index, typename... Args>
			struct Dispatcher;

			template <Size index, typename Head, typename... Rest>
			struct Dispatcher<index, Head, Rest...>
			{
				static typename TypeAt<index-1, Rest...>::Type exec(Head head, Rest... rest)
				{
					return Dispatcher<index-1, Rest...>::exec(rest...);
				}
			};

			template <typename Head, typename... Rest>
			struct Dispatcher<0, Head, Rest...>
			{
				static Head exec(Head head, Rest... rest)
				{
					return head;
				}
			};
		}
	}

	template <Size index, typename... Args>
	inline typename TypeAt<index, Args...>::Type value_at(Args... args)
	{
		return _impl::_value_at::Dispatcher<index, Args...>::exec(args...);
	}

#endif //VALUE_AT_HPP
