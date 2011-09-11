#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <type_traits>

//class bits
//{
//	public:
//
//		void const* data;
//		unsigned long size;
//
//		bits(void const* _data, unsigned long _size)
//			:	data(_data)
//			,	size(_size)
//		{
//
//		}
//
//		template <class T>
//		explicit bits(T const& x)
//			:	data(&x)
//			,	size(sizeof(x))
//		{
//
//		}
//};
//
//std::ostream& operator<<(std::ostream& os, bits const& b)
//{
//	for (unsigned int i = 0; i < b.size; ++i)
//	{
//		if (i != 0)
//		{
//			std::cout << " ";
//		}
//		for (unsigned int j = 0; j < 8; ++j)
//		{
//			std::cout << ((*((unsigned char*)b.data + b.size - 1 - i) >> (7-j)) & 1);
//		}
//	}
//	return os;
//};



//#include "space.hpp"
//
//template <typename Type, Size const size>
//std::ostream& operator<<(std::ostream& s, Vector<Type, size> const& v)
//{
//	s << "Vector<" << size << ">(" << v[0];
//	for (Size i = 1; i < size; ++i)
//	{
//		s << ", " << v[i];
//	}
//	s << ")";
//	return s;
//}
//
//
//template <typename Type, Size const h, Size const w>
//std::ostream& operator<<(std::ostream& s, Matrix<Type, h, w> const& m)
//{
//	s << "Matrix<" << h << ", " << w << ">\n(\n";
//	for (Size i = 0; i < h-1; ++i)
//	{
//		s << "\t" << m[i][0];
//		for (Size j = 1; j < w; ++j)
//		{
//			s << ",\t" << m[i][j];
//		}
//		s << ",\n";
//	}
//	s << "\t" << m[h-1][0];
//	for (Size j = 1; j < w; ++j)
//	{
//		s << ",\t" << m[h-1][j];
//	}
//	s << "\n)";
//	return s;
//}

//#include "array.hpp"
//#include <type_traits>
//
//
//template <typename T>
//std::ostream& operator<<(std::ostream& s, Array<T> const& a)
//{
//	s << "Array<" << a.size() << ">(" << a[0];
//	for (Size i = 1; i < a.size(); ++i)
//		s << ", " << a[i];
//	s << ")";
//	return s;
//}



//#include "hdr/tuple.hpp"
//
//template <Size index, typename... Types>
//typename If<((index == 0) && (Tuple<Types...>::arity == 0)), void>::Type _impl_tuple_print(std::ostream& s, Tuple<Types...> const& t)
//{
//	s << "[]";
//}
//
//template <Size index, typename... Types>
//typename If<((index == 0) && (Tuple<Types...>::arity != 0)), void>::Type _impl_tuple_print(std::ostream& s, Tuple<Types...> const& t)
//{
//	s << "[" << t.template at<0>();
//	_impl_tuple_print<1>(s, t);
//}
//
//template <Size index, typename... Types>
//typename If<((index != 0) && (index != Tuple<Types...>::arity-1) && (Tuple<Types...>::arity != 0)), void>::Type _impl_tuple_print(std::ostream& s, Tuple<Types...> const& t)
//{
//	s << ", " << t.template at<index>();
//	_impl_tuple_print<index+1>(s, t);
//}
//
//template <Size index, typename... Types>
//typename If<((index == Tuple<Types...>::arity-1) && (Tuple<Types...>::arity != 0)), void>::Type _impl_tuple_print(std::ostream& s, Tuple<Types...> const& t)
//{
//	s << ", " << t.template at<index>() << "]";
//}
//
//
//template <typename... Types>
//std::ostream& operator<<(std::ostream& s, Tuple<Types...> const& t)
//{
//	_impl_tuple_print<0>(s, t);
//	return s;
//}

//template <typename Type, typename Base = Type>
//class Cloneable
//{
//	public:
//
//		virtual Base* const clone() const
//		{
//			return new Type(*this);
//		}
//};



//#include "hdr/memory.hpp"
//
//
//class Heap : public Memory
//{
//	public:
//
//		virtual Void* const grab(Size size)
//		{
//			return new unsigned char[size];
//		}
//		virtual Void* const grab(Size size, Size align)
//		{
//			return new unsigned char[size];
//		}
//		virtual Void free(Void* ptr)
//		{
//			delete [] (unsigned char*)ptr;
//		}
//};
//
//
//struct Test
//{
//	Test()
//	{
//		std::cout << this << " default constructor\n";
//	}
//
//	Test(float, int)
//	{
//		std::cout << this << " (float, int) constructor\n";
//	}
//
//	Test(Test const&)
//	{
//		std::cout << this << " copy constructor\n";
//	}
//
//	Test& operator=(Test const&)
//	{
//		std::cout << this << " copy assignment\n";
//		return *this;
//	}
//
//	Test(Test&&)
//	{
//		std::cout << this << " move constructor\n";
//	}
//
//	Test& operator=(Test&&)
//	{
//		std::cout << this << " move assignment\n";
//		return *this;
//	}
//
//	~Test()
//	{
//		std::cout << this << " destructor\n";
//	}
//};

#include <vector>
#include <map>
#include <string>
#include <functional>





int main()
{



	return 0;
}
