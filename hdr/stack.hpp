#ifndef STACK_HPP
	#define STACK_HPP

	#include "size.hpp"
	#include "swap.hpp"
	#include "void.hpp"

	template <typename, Size const = ~Size(0)>
	class Stack;

	template <typename T>
	class Stack<T, ~Size(0)>
	{
		private:

			struct _Item
			{
				_Item* next;
				T value;
			};

			_Item* _top;
			Size _size;

		public:

			Stack()
				: _top(0)
				, _size(0)
			{

			}

			Stack(Stack const& that)
				: _top(0)
				, _size(0)
			{

			}

	};

#endif //STACK_HPP
