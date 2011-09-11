#ifndef SMALL_SPACE_HPP
	#define SMALL_SPACE_HPP

	#include "size.hpp"

	template <typename, Size const>
	class Vector;

	template<typename T>
	class Vector<T, 2>
	{
		public:

			T x;
			T y;

			Vector()
			{

			}

			Vector(Vector const& that)
				:	x(that.x)
				,	y(that.y)
			{

			}

			Vector& operator=(Vector const& that)
			{
				x = that.x;
				y = that.y;
				return *this;
			}




			Vector(T const& x_, T const& y_)
				:	x(x_)
				,	y(y_)
			{

			}

			template <typename U>
			Vector(Vector<U, 2> const& that)
				:	x(that.x)
				,	y(that.y)
			{

			}

			template <typename U>
			Vector& operator=(Vector<U, 2> const& that)
			{
				x = that.x;
				y = that.y;
				return *this;
			}

			template <typename U>
			explicit Vector(Vector<U, 3> const& that)
				:	x(that.x)
				,	y(that.y)
			{

			}

	};

	template<typename T>
	class Vector<T, 3>
	{
		public:

			T x;
			T y;
			T z;

			Vector()
			{

			}

			Vector(Vector const& that)
				:	x(that.x)
				,	y(that.y)
				,	z(that.z)
			{

			}

			Vector& operator=(Vector const& that)
			{
				x = that.x;
				y = that.y;
				z = that.z;
				return *this;
			}


			Vector(T const& x_, T const& y_, T const& z_)
				:	x(x_)
				,	y(y_)
				,	z(z_)
			{

			}

			template <typename U>
			Vector(Vector<U, 2> const& that)
				:	x(that.x)
				,	y(that.y)
				,	z()
			{

			}

			template <typename U>
			Vector& operator=(Vector<U, 2> const& that)
			{
				x = that.x;
				y = that.y;
				z = T();
				return *this;
			}

			template <typename U>
			Vector(Vector<U, 2> const& that, T const& z_)
				:	x(that.x)
				,	y(that.y)
				,	z(z_)
			{

			}

			template <typename U>
			Vector(Vector<U, 3> const& that)
				:	x(that.x)
				,	y(that.y)
				,	z(that.z)
			{

			}

			template <typename U>
			Vector& operator=(Vector<U, 3> const& that)
			{
				x = that.x;
				y = that.y;
				z = that.z;
				return *this;
			}
	};


		//negate
	template <typename T>
	inline Vector<T, 2> const operator-(Vector<T, 2> const& t)
	{
		return Vector<T, 2>(-t.x, -t.y);
	}

	template <typename T>
	inline Vector<T, 3> const operator-(Vector<T, 3> const& t)
	{
		return Vector<T, 2>(-t.x, -t.y, -t.z);
	}

		//add
	template <typename L, typename R>
	inline Vector<decltype(L()+R()), 2> const operator+(Vector<L, 2> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()+R()), 2>
		(
			l.x + r.x,
			l.y + r.y
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()+R()), 3> const operator+(Vector<L, 3> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()+R()), 3>
		(
			l.x + r.x,
			l.y + r.y,
			l.z
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()+R()), 3> const operator+(Vector<L, 2> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()+R()), 3>
		(
			l.x + r.x,
			l.y + r.y,
			      r.z
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()+R()), 3> const operator+(Vector<L, 3> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()+R()), 3>
		(
			l.x + r.x,
			l.y + r.y,
			l.z + r.z
		);
	}

		//add and assign
	template <typename L, typename R>
	inline Vector<L, 2>& operator+=(Vector<L, 2>& l, Vector<R, 2> const& r)
	{
		l.x += r.x;
		l.y += r.y;
		return l;
	}
	template <typename L, typename R>
	inline Vector<L, 3>& operator+=(Vector<L, 3>& l, Vector<R, 2> const& r)
	{
		l.x += r.x;
		l.y += r.y;
		return l;
	}
	template <typename L, typename R>
	inline Vector<L, 3>& operator+=(Vector<L, 3>& l, Vector<R, 3> const& r)
	{
		l.x += r.x;
		l.y += r.y;
		l.z += r.z;
		return l;
	}


			//substract
	template <typename L, typename R>
	inline Vector<decltype(L()-R()), 2> const operator-(Vector<L, 2> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()-R()), 2>
		(
			l.x - r.x,
			l.y - r.y
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()-R()), 3> const operator-(Vector<L, 3> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()-R()), 3>
		(
			l.x - r.x,
			l.y - r.y,
			l.z
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()-R()), 3> const operator-(Vector<L, 2> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()-R()), 3>
		(
			l.x - r.x,
			l.y - r.y,
			    - r.z
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()-R()), 3> const operator-(Vector<L, 3> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()-R()), 3>
		(
			l.x - r.x,
			l.y - r.y,
			l.z - r.z
		);
	}

		//substract and assign
	template <typename L, typename R>
	inline Vector<L, 2>& operator-=(Vector<L, 2>& l, Vector<R, 2> const& r)
	{
		l.x -= r.x;
		l.y -= r.y;
		return l;
	}
	template <typename L, typename R>
	inline Vector<L, 3>& operator-=(Vector<L, 3>& l, Vector<R, 2> const& r)
	{
		l.x -= r.x;
		l.y -= r.y;
		return l;
	}
	template <typename L, typename R>
	inline Vector<L, 3>& operator-=(Vector<L, 3>& l, Vector<R, 3> const& r)
	{
		l.x -= r.x;
		l.y -= r.y;
		l.z -= r.z;
		return l;
	}


		//multiply
	template <typename L, typename R>
	inline Vector<decltype(L()*R()), 2> const operator*(Vector<L, 2> const& l, R const& r)
	{
		return Vector<decltype(L()*R()), 2>
		(
			l.x * r,
			l.y * r
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()*R()), 2> const operator*(L const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()*R()), 2>
		(
			l * r.x,
			l * r.y
		);
	}

	template <typename L, typename R>
	inline Vector<decltype(L()*R()), 3> const operator*(Vector<L, 3> const& l, R const& r)
	{
		return Vector<decltype(L()*R()), 2>
		(
			l.x * r,
			l.y * r,
			l.z * r
		);
	}
	template <typename L, typename R>
	inline Vector<decltype(L()*R()), 3> const operator*(L const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()*R()), 2>
		(
			l * r.x,
			l * r.y,
			l * r.z
		);
	}

		//multiply and assign
	template <typename L, typename R>
	inline Vector<L, 2>& operator*=(Vector<L, 2>& l, R const& r)
	{
		l.x *= r;
		l.y *= r;
		return l;
	}

	template <typename L, typename R>
	inline Vector<L, 3>& operator*=(Vector<L, 3>& l, R const& r)
	{
		l.x *= r;
		l.y *= r;
		l.z *= r;
		return l;
	}

		//divide
	template <typename L, typename R>
	inline Vector<decltype(L()/R()), 2> const operator/(Vector<L, 2> const& l, R const& r)
	{
		return Vector<decltype(L()/R()), 2>
		(
			l.x / r,
			l.y / r
		);
	}

	template <typename L, typename R>
	inline Vector<decltype(L()/R()), 3> const operator/(Vector<L, 3> const& l, R const& r)
	{
		return Vector<decltype(L()/R()), 2>
		(
			l.x / r,
			l.y / r,
			l.z / r
		);
	}

		//divide and assign
	template <typename L, typename R>
	inline Vector<L, 2>& operator/=(Vector<L, 2>& l, R const& r)
	{
		l.x /= r;
		l.y /= r;
		return l;
	}

	template <typename L, typename R>
	inline Vector<L, 3>& operator/=(Vector<L, 3>& l, R const& r)
	{
		l.x /= r;
		l.y /= r;
		l.z /= r;
		return l;
	}

		//dot product
	template <typename L, typename R>
	inline decltype(L()*R()+L()*R()) const operator*(Vector<L, 2> const& l, Vector<R, 2> const& r)
	{
		return l.x*r.x + l.y*r.y;
	}

	template <typename L, typename R>
	inline decltype(L()*R()+L()*R()) const operator*(Vector<L, 2> const& l, Vector<R, 3> const& r)
	{
		return l.x*r.x + l.y*r.y;
	}

	template <typename L, typename R>
	inline decltype(L()*R()+L()*R()) const operator*(Vector<L, 3> const& l, Vector<R, 2> const& r)
	{
		return l.x*r.x + l.y*r.y;
	}

	template <typename L, typename R>
	inline decltype(L()*R()+L()*R()) const operator*(Vector<L, 3> const& l, Vector<R, 3> const& r)
	{
		return l.x*r.x + l.y*r.y + l.z*r.z;
	}

		//cross product
	template <typename L, typename R>
	inline Vector<decltype(L()*R()-L()*R()), 3> const operator%(Vector<L, 2> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()*R()-L()*R()), 3>
		(
			decltype(L()*R()-L()*R())(),
			decltype(L()*R()-L()*R())(),
			l.x*r.y - l.y*r.x
		);
	}

	template <typename L, typename R>
	inline Vector<decltype(L()*R()-L()*R()), 3> const operator%(Vector<L, 2> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()*R()-L()*R()), 3>
		(
			l.y*r.z			 ,
					- l.x*r.z,
			l.x*r.y - l.y*r.x
		);
	}

	template <typename L, typename R>
	inline Vector<decltype(L()*R()-L()*R()), 3> const operator%(Vector<L, 3> const& l, Vector<R, 2> const& r)
	{
		return Vector<decltype(L()*R()-L()*R()), 3>
		(
			        - l.z*r.y,
			l.z*r.x          ,
			l.x*r.y - l.y*r.x
		);
	}

	template <typename L, typename R>
	inline Vector<decltype(L()*R()-L()*R()), 3> const operator%(Vector<L, 3> const& l, Vector<R, 3> const& r)
	{
		return Vector<decltype(L()*R()-L()*R()), 3>
		(
			l.y*r.z - l.z*r.y,
			l.z*r.x - l.x*r.z,
			l.x*r.y - l.y*r.x
		);
	}

		//squared length
	template <typename T>
	inline decltype(T()*T()+T()*T()) const len2(Vector<T, 2> const& t)
	{
		return t.x*t.x + t.y*t.y;
	}

	template <typename T>
	inline decltype(T()*T()+T()*T()+T()*T()) const len2(Vector<T, 3> const& t)
	{
		return t.x*t.x + t.y*t.y + t.z*t.z;
	}








	template <typename, Size const>
	class Matrix;

	template <typename T>
	class Matrix<T, 3>
	{
		public:

			T
				s00, s01, s02,
				s10, s11, s12,
				s20, s21, s22;

			Matrix()
			{

			}

			Matrix
			(
				T const& s00_, T const& s01_, T const& s02_,
				T const& s10_, T const& s11_, T const& s12_,
				T const& s20_, T const& s21_, T const& s22_
			)
				:	s00(s00_), s01(s01_), s02(s02_),
					s10(s10_), s11(s11_), s12(s12_),
					s20(s20_), s21(s21_), s22(s22_)
			{

			}

	};

	template <typename T>
	class Matrix<T, 4>
	{
		public:

			T
				s00, s01, s02, s03,
				s10, s11, s12, s13,
				s20, s21, s22, s23,
				s30, s31, s32, s33;


			Matrix()
			{

			}

			Matrix
			(
				T const& s00_, T const& s01_, T const& s02_, T const& s03_,
				T const& s10_, T const& s11_, T const& s12_, T const& s13_,
				T const& s20_, T const& s21_, T const& s22_, T const& s23_,
				T const& s30_, T const& s31_, T const& s32_, T const& s33_
			)
				:	s00(s00_), s01(s01_), s02(s02_), s03(s03_),
					s10(s10_), s11(s11_), s12(s12_), s13(s13_),
					s20(s20_), s21(s21_), s22(s22_), s23(s23_),
					s30(s30_), s31(s31_), s32(s32_), s33(s33_)
			{

			}
	};


		//multiply
	template <typename L, typename R>
	inline Matrix<decltype(L()*R() + L()*R() + L()*R()), 3> const operator*(Matrix<L, 3> const& l, Matrix<R, 3> const& r)
	{
		return Matrix<decltype(L()*R() + L()*R() + L()*R()), 3>
		(
			l.s00*r.s00 + l.s01*r.s10 + l.s02*r.s20,
			l.s00*r.s01 + l.s01*r.s11 + l.s02*r.s21,
			l.s00*r.s02 + l.s01*r.s12 + l.s02*r.s22,

			l.s10*r.s00 + l.s11*r.s10 + l.s12*r.s20,
			l.s10*r.s01 + l.s11*r.s11 + l.s12*r.s21,
			l.s10*r.s02 + l.s11*r.s12 + l.s12*r.s22,

			l.s20*r.s00 + l.s21*r.s10 + l.s22*r.s20,
			l.s20*r.s01 + l.s21*r.s11 + l.s22*r.s21,
			l.s20*r.s02 + l.s21*r.s12 + l.s22*r.s22
		);
	}

	template <typename L, typename R>
	inline Matrix<decltype(L()*R() + L()*R() + L()*R() + L()*R()), 4> const operator*(Matrix<L, 4> const& l, Matrix<R, 4> const& r)
	{
		return Matrix<decltype(L()*R() + L()*R() + L()*R() + L()*R()), 4>
		(
			l.s00*r.s00 + l.s01*r.s10 + l.s02*r.s20 + l.s03*r.s30,
			l.s00*r.s01 + l.s01*r.s11 + l.s02*r.s21 + l.s03*r.s31,
			l.s00*r.s02 + l.s01*r.s12 + l.s02*r.s22 + l.s03*r.s32,
			l.s00*r.s03 + l.s01*r.s13 + l.s02*r.s23 + l.s03*r.s33,

			l.s10*r.s00 + l.s11*r.s10 + l.s12*r.s20 + l.s13*r.s30,
			l.s10*r.s01 + l.s11*r.s11 + l.s12*r.s21 + l.s13*r.s31,
			l.s10*r.s02 + l.s11*r.s12 + l.s12*r.s22 + l.s13*r.s32,
			l.s10*r.s03 + l.s11*r.s13 + l.s12*r.s23 + l.s13*r.s33,

			l.s20*r.s00 + l.s21*r.s10 + l.s22*r.s20 + l.s23*r.s30,
			l.s20*r.s01 + l.s21*r.s11 + l.s22*r.s21 + l.s23*r.s31,
			l.s20*r.s02 + l.s21*r.s12 + l.s22*r.s22 + l.s23*r.s32,
			l.s20*r.s03 + l.s21*r.s13 + l.s22*r.s23 + l.s23*r.s33,

			l.s30*r.s00 + l.s31*r.s10 + l.s32*r.s20 + l.s33*r.s30,
			l.s30*r.s01 + l.s31*r.s11 + l.s32*r.s21 + l.s33*r.s31,
			l.s30*r.s02 + l.s31*r.s12 + l.s32*r.s22 + l.s33*r.s32,
			l.s30*r.s03 + l.s31*r.s13 + l.s32*r.s23 + l.s33*r.s33
		);
	}

		//multily and assign
	template <typename L, typename R>
	inline Matrix<L, 3>& operator*=(Matrix<L, 3>& l, Matrix<R, 3> const& r)
	{
		return l = l*r;
	}

	template <typename L, typename R>
	inline Matrix<L, 4>& operator*=(Matrix<L, 4>& l, Matrix<R, 4> const& r)
	{
		return l = l*r;
	}

		//invert
	template <typename T>
	inline Matrix<T, 3> const operator~(Matrix<T, 3> const& t)
	{
		auto const t0 = t.s11*t.s22 - t.s12*t.s21;
		auto const t1 = t.s12*t.s20 - t.s10*t.s22;
		auto const t2 = t.s10*t.s21 - t.s11*t.s20;

		auto const d = t.s00*t0 + t.s01*t1 + t.s02*t2;

		return Matrix<T, 3>
		(
			t0                          / d,
			(t.s02*t.s21 - t.s01*t.s22) / d,
			(t.s01*t.s12 - t.s02*t.s11) / d,

			t1                          / d,
			(t.s00*t.s22 - t.s02*t.s20) / d,
			(t.s02*t.s10 - t.s00*t.s12) / d,

			t2                          / d,
			(t.s01*t.s20 - t.s00*t.s21) / d,
			(t.s00*t.s11 - t.s01*t.s10) / d
		);
	}

	template <typename T>
	inline Matrix<T, 4> const operator~(Matrix<T, 4> const& t)
	{
		auto const a0 = t.s00*t.s11 - t.s01*t.s10;
		auto const a1 = t.s00*t.s12 - t.s02*t.s10;
		auto const a2 = t.s00*t.s13 - t.s03*t.s10;
		auto const a3 = t.s01*t.s12 - t.s02*t.s11;
		auto const a4 = t.s01*t.s13 - t.s03*t.s11;
		auto const a5 = t.s02*t.s13 - t.s03*t.s12;

		auto const b0 = t.s20*t.s31 - t.s21*t.s30;
		auto const b1 = t.s20*t.s32 - t.s22*t.s30;
		auto const b2 = t.s20*t.s33 - t.s23*t.s30;
		auto const b3 = t.s21*t.s32 - t.s22*t.s31;
		auto const b4 = t.s21*t.s33 - t.s23*t.s31;
		auto const b5 = t.s22*t.s33 - t.s23*t.s32;

		auto const d = a0*b5 - a1*b4 + a2*b3 + a3*b2 - a4*b1 + a5*b0;

		return Matrix<T, 4>
		(
			(t.s11*b5 - t.s12*b4 + t.s13*b3) / d,
			(t.s02*b4 - t.s03*b3 - t.s01*b5) / d,
			(t.s31*a5 - t.s32*a4 + t.s33*a3) / d,
			(t.s22*a4 - t.s23*a3 - t.s21*a5) / d,

			(t.s12*b2 - t.s13*b1 - t.s10*b5) / d,
			(t.s00*b5 - t.s02*b2 + t.s03*b1) / d,
			(t.s32*a2 - t.s33*a1 - t.s30*a5) / d,
			(t.s20*a5 - t.s22*a2 + t.s23*a1) / d,

			(t.s10*b4 - t.s11*b2 + t.s13*b0) / d,
			(t.s01*b2 - t.s03*b0 - t.s00*b4) / d,
			(t.s30*a4 - t.s31*a2 + t.s33*a0) / d,
			(t.s21*a2 - t.s23*a0 - t.s20*a4) / d,

			(t.s11*b1 - t.s12*b0 - t.s10*b3) / d,
			(t.s00*b3 - t.s01*b1 + t.s02*b0) / d,
			(t.s31*a1 - t.s32*a0 - t.s30*a3) / d,
			(t.s20*a3 - t.s21*a1 + t.s22*a0) / d
		);
	}

		//matrix vector multiply
	template <typename L, typename R>
	inline Vector<decltype((L()*R() + L()*R() + R()) / (L()*R() + L()*R() + R())), 2> const operator*(Vector<L, 2> const& l, Matrix<R, 3> const& r)
	{
		auto const p = l.x*r.s02 + l.y*r.s12 + r.s22;

		return Vector<decltype((L()*R() + L()*R() + R()) / (L()*R() + L()*R() + R())), 2>
		(
			(l.x*r.s00 + l.y*r.s10 + r.s20) / p,
			(l.x*r.s01 + l.y*r.s11 + r.s21) / p
		);
	}

	template <typename L, typename R>
	inline Vector<decltype((L()*R() + L()*R() + L()*R() + R()) / (L()*R() + L()*R() + L()*R() + R())), 3> const operator*(Vector<L, 3> const& l, Matrix<R, 4> const& r)
	{
		auto const p = l.x*r.s03 + l.y*r.s13 + l.z*r.s23 + r.s33;

		return Vector<decltype((L()*R() + L()*R() + L()*R() + R()) / (L()*R() + L()*R() + L()*R() + R())), 3>
		(
			(l.x*r.s00 + l.y*r.s10 + l.z*r.s20 + r.s30) / p,
			(l.x*r.s01 + l.y*r.s11 + l.z*r.s21 + r.s31) / p,
			(l.x*r.s02 + l.y*r.s12 + l.z*r.s22 + r.s32) / p
		);
	}

		//matrix vector multiply and assign
	template <typename L, typename R>
	inline Vector<L, 2>& operator*=(Vector<L, 2>& l, Matrix<R, 3> const& r)
	{
		return l = l*r;
	}

	template <typename L, typename R>
	inline Vector<L, 3>& operator*=(Vector<L, 3>& l, Matrix<R, 4> const& r)
	{
		return l = l*r;
	}

#endif //SMALL_SPACE_HPP
