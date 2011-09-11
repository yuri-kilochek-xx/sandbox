#ifndef SPACE_HPP
	#define SPACE_HPP

	#include "size.hpp"
	#include "if.hpp"

	template <typename T, Size const ts>
	class Vector;

	template <typename T>
	class Vector<T, 0>;

	template <typename T>
	class Vector<T, 1>;

	namespace _impl
	{
		namespace Vector
		{
			template <Size const ts, Size const index, typename T>
			struct VariadicConstructor
			{
				template <typename... Rest>
				static void exec(T* data, T&& head, Rest&&... rest)
				{
					new (data + index) T(static_cast<T&&>(head));
					VariadicConstructor<ts, index+1, T>::exec(data, static_cast<Rest&&>(rest)...);
				}
				template <typename... Rest>
				static void exec(T* data, T const& head, Rest&&... rest)
				{
					new (data + index) T(head);
					VariadicConstructor<ts, index+1, T>::exec(data, static_cast<Rest&&>(rest)...);
				}
			};
			template <Size const ts, typename T>
			struct VariadicConstructor<ts, ts, T>
			{
				template <typename... Rest>
				static void exec(T* data)
				{

				}
			};
		}
	}



	template <typename T, Size const ts>
	class Vector
	{
		template <typename U, Size const us>
		friend class Vector;

		private:

			unsigned char _data[ts*sizeof(T)];

		public:

			Vector()
			{
				for (Size i = 0; i < ts; ++i)
					new (((T*)_data)+i) T();
			}

			Vector(Vector const& that)
			{
				for (Size i = 0; i < ts; ++i)
					new (((T*)this->_data)+i) T(((T const*)that._data)[i]);
			}
			Vector(Vector&& that)
			{
				for (Size i = 0; i < ts; ++i)
					new (((T*)this->_data)+i) T(static_cast<T&&>(((T*)that._data)[i]));
			}

			~Vector()
			{
				for (Size i = 0; i < ts; ++i)
					(((T*)_data)+i)->~T();
			}

			Vector& operator=(Vector const& that)
			{
				for (Size i = 0; i < ts; ++i)
					((T*)this->_data)[i] = ((T const*)that._data)[i];
				return *this;
			}
			Vector& operator=(Vector&& that)
			{
				for (Size i = 0; i < ts; ++i)
					((T*)this->_data)[i] = static_cast<T&&>(((T*)that._data)[i]);
				return *this;
			}


			template <typename... Args>
			explicit Vector(T&& head, Args&&... args)
			{
				_impl::Vector::VariadicConstructor<ts, 0, T>::exec((T*)_data, static_cast<T&&>(head), static_cast<Args&&>(args)...);
			}

			template <typename U, Size const us>
			explicit Vector(Vector<U, us> const that, typename If<(ts < us), void>::Type* = 0)
			{
				for (Size i = 0; i < ts; ++i)
					new (((T*)_data)+i) T(((U const*)that._data)[i]);
			}

			template <typename U, Size const us>
			Vector(Vector<U, us> const that, typename If<(ts == us), void>::Type* = 0)
			{
				for (Size i = 0; i < ts; ++i)
					new (((T*)_data)+i) T(((U const*)that._data)[i]);
			}

			template <typename U, Size const us>
			Vector(Vector<U, us> const that, typename If<(ts > us), void>::Type* = 0)
			{
				for (Size i = 0; i < us; ++i)
					new (((T*)_data)+i) T(((U const*)that._data)[i]);
				for (Size i = us; i < ts; ++i)
					new (((T*)_data)+i) T();
			}

			template <typename U, Size const us, typename... Args>
			explicit Vector(Vector<U, us> const that, Args&&... args)
			{
				for (Size i = 0; i < us; ++i)
					new (((T*)_data)+i) T(((U const*)that._data)[i]);
				_impl::Vector::VariadicConstructor<ts, us, T>::exec((T*)_data, static_cast<Args&&>(args)...);
			}


			T& operator[](Size const i)
			{
				return ((T*)_data)[i];
			}
			T const& operator[](Size const i) const
			{
				return ((T const*)_data)[i];
			}
	};

		//-
	template <typename R, Size const rs>
	inline Vector<decltype(-R()), rs> const
	operator-(Vector<R, rs> const& r)
	{
		Vector<decltype(-R()), rs> t;
		for (Size i = 0; i < rs; ++i)
			t[i] = -r[i];
		return t;
	}

		//+
	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls < rs), Vector<decltype(L()+R()), rs> const>::Type
	operator+(Vector<L, ls> const& l, Vector<R, rs> const& r)
	{
		Vector<decltype(L()+R()), rs> t;
		for (Size i = 0; i < ls; ++i)
			t[i] = l[i]+r[i];
		for (Size i = ls; i < rs; ++i)
			t[i] = r[i];
		return t;
	}

	template <typename L, typename R, Size const s>
	inline Vector<decltype(L()+R()), s> const
	operator+(Vector<L, s> const& l, Vector<R, s> const& r)
	{
		Vector<decltype(L()+R()), s> t;
		for (Size i = 0; i < s; ++i)
			t[i] = l[i]+r[i];
		return t;
	}

	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls > rs), Vector<decltype(L()+R()), ls> const>::Type
	operator+(Vector<L, ls> const& l, Vector<R, rs> const& r)
	{
		Vector<decltype(L()+R()), ls> t;
		for (Size i = 0; i < rs; ++i)
			t[i] = l[i]+r[i];
		for (Size i = rs; i < ls; ++i)
			t[i] = l[i];
		return t;
	}

		//+=
	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls >= rs), Vector<L, ls>&>::Type
	operator+=(Vector<L, ls>& l, Vector<R, rs> const& r)
	{
		for (Size i = 0; i < rs; ++i)
			l[i] += r[i];
		return l;
	}


		//-
	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls < rs), Vector<decltype(L()-R()), rs> const>::Type
	operator-(Vector<L, ls> const& l, Vector<R, rs> const& r)
	{
		Vector<decltype(L()-R()), rs> t;
		for (Size i = 0; i < ls; ++i)
			t[i] = l[i]-r[i];
		for (Size i = ls; i < rs; ++i)
			t[i] = r[i];
		return t;
	}

	template <typename L, typename R, Size const s>
	inline Vector<decltype(L()-R()), s> const
	operator-(Vector<L, s> const& l, Vector<R, s> const& r)
	{
		Vector<decltype(L()-R()), s> t;
		for (Size i = 0; i < s; ++i)
			t[i] = l[i]-r[i];
		return t;
	}

	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls > rs), Vector<decltype(L()-R()), ls> const>::Type
	operator-(Vector<L, ls> const& l, Vector<R, rs> const& r)
	{
		Vector<decltype(L()-R()), ls> t;
		for (Size i = 0; i < rs; ++i)
			t[i] = l[i]-r[i];
		for (Size i = rs; i < ls; ++i)
			t[i] = l[i];
		return t;
	}

		//-=
	template <typename L, Size const ls, typename R, Size const rs>
	inline typename If<(ls >= rs), Vector<L, ls>&>::Type
	operator-=(Vector<L, ls>& l, Vector<R, rs> const& r)
	{
		for (Size i = 0; i < rs; ++i)
			l[i] -= r[i];
		return l;
	}


		//inner
	template <typename L, Size const ls, typename R, Size const rs>
	inline decltype(L()*R()) const
	inner(Vector<L, ls>& l, Vector<R, rs> const& r)
	{
		decltype(L()*R()) t = l[0]*r[0];
		for (Size i = 1; i < (ls < rs ? ls : rs); ++i)
			t += l[i]*r[i];
		return t;
	}





	template <typename T, Size const h, Size const w = h>
	class Matrix;

	template <typename T>
	class Matrix<T, 0, 0>;

	template <typename T>
	class Matrix<T, 0, 1>;

	template <typename T>
	class Matrix<T, 1, 0>;

	template <typename T>
	class Matrix<T, 1, 1>;

	template <typename T>
	class Matrix<T, 1, 2>;

	template <typename T>
	class Matrix<T, 2, 1>;


	template <typename T, Size const h, Size const w>
	class Matrix
	{
		private:

			unsigned char _data[h*w*sizeof(T)];

		public:

			Matrix()
			{
				for (Size i = 0; i < w*h; ++i)
					new (((T*)_data) + i) T();
			}

			Matrix(Matrix const& that)
			{
				for (Size i = 0; i < w*h; ++i)
					new (((T*)this->_data) + i) T(((T const*)that._data)[i]);
			}

			Matrix(Matrix&& that)
			{
				for (Size i = 0; i < w*h; ++i)
					new (((T*)this->_data) + i) T(static_cast<T&&>(((T*)that._data)[i]));
			}

			~Matrix()
			{
				for (Size i = 0; i < w*h; ++i)
					(((T*)_data) + i)->~T();
			}

			Matrix& operator=(Matrix const& that)
			{
				for (Size i = 0; i < w*h; ++i)
					((T*)this->_data)[i] = ((T const*)that._data)[i];
				return *this;
			}
			Matrix& operator=(Matrix&& that)
			{
				for (Size i = 0; i < w*h; ++i)
					((T*)this->_data)[i] = static_cast<T&&>(((T*)that._data)[i]);
				return *this;
			}


			T* const operator[](Size const i)
			{
				return ((T*)_data) + i*w;
			}
			T const* const operator[](Size const i) const
			{
				return ((T const*)_data) + i*w;
			}
	};


	template <typename L, Size const lh, typename R, Size const rw, Size const s>
	inline Matrix<decltype(L()*R()+L()*R()), lh, rw> const
	operator*(Matrix<L, lh, s> const& l, Matrix<R, s, rw> const& r)
	{
		Matrix<decltype(L()*R()+L()*R()), lh, rw> t;
		for (Size i = 0; i < lh; ++i)
			for (Size j = 0; j < rw; ++j)
			{
				t[i][j] = l[i][0] * r[0][j];
				for (Size k = 1; k < s; ++k)
					t[i][j] += l[i][k] * r[k][j];
			}
		return t;
	}


	template <typename L, typename R, Size const s>
	inline Matrix<L, s, s>&
	operator*=(Matrix<L, s, s>& l, Matrix<R, s, s> const& r)
	{
		return l = l*r;
	}

	template <typename L, Size const lh, typename R, Size const rw, Size const s>
	inline Vector<decltype(L()*R()+L()*R()), lh, rw> const
	operator*(Vector<L, s> const& l, Matrix<R, s, rw> const& r)
	{
		Vector<decltype(L()*R()+L()*R()), lh, rw> t;
		for (Size j = 0; j < rw; ++j)
		{
			t[j] = l[0] * r[0][j];
			for (Size k = 1; k < s; ++k)
				t[j] += l[k] * r[k][j];
		}
		return t;
	}




#endif //SPACE_HPP
