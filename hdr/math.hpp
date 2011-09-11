#ifndef MATH_HPP
	#define MATH_HPP

	#include "abs.hpp"
	#include "size.hpp"

	template <typename R>
	R const eps() = delete;

	template <typename R>
	R const inf() = delete;

	template <typename R>
	R const nan() = delete;

	template <typename R>
	R const e() = delete;

	template <typename R>
	R const pi() = delete;

	template <typename R>
	R const fct(Size n)
	{
		R y = 1;
		for (Size i = 2; i <= n; ++i)
			y *= i;
		return y;
	}


		//float
	template <>
	float const eps<float>()
	{
		return 0.00000011920928955078125f;
	}

	template <>
	float const inf<float>()
	{
		return 1.0f/0.0f;
	}

	template <>
	float const nan<float>()
	{
		return 0.0f/0.0f;
	}

	template <>
	float const e<float>()
	{
		return 2.71828182845904523536028747135266249775724709369995f;
	}

	template<>
	float const pi<float>()
	{
		return 3.14159265358979323846264338327950288419716939937510f;
	}



	inline float const mod(float const x, float const s)
	{
		float const t = x/s;
		if (abs(t) >= 8338608.0f)
			return x - t*s;
		else if (abs(t) < 1.0f)
			return x;
		else
			return x - ((long)t)*s;
	}


	float const exp(float const x, float const b)
	{

	}

	inline float const exp2(float const x)
	{
		return exp(x, 2.0f);
	}
	inline float const expe(float const x)
	{
		return exp(x, e<float>());
	}
	inline float const exp10(float const x)
	{
		return exp(x, 10.0f);
	}

	float const log(float const x, float const b)
	{

	}

	float const log2(float const x)
	{
		return log(x, 2.0f);
	}
	float const loge(float const x)
	{
		return log(x, e<float>());
	}
	float const log10(float const x)
	{
		return log(x, 10.0f);
	}




	float const pw(float const x, float const p)
	{
		return expe(loge(x)*p);
	}

	inline float const pw2(float const x)
	{
		return x*x;
	}

	inline float const pw3(float const x)
	{
		return x*x*x;
	}



	float const rt(float const x, float const p)
	{
		return expe(loge(x)/p);
	}

	inline float const rt2(float const x)
	{
		return rt(x, 2.0f);
	}

	inline float const rt3(float const x)
	{
		return rt(x, 3.0f);
	}




	inline float const sin(float const x)
	{
        /* move x to [-pi, pi) */
        float t = mod(x, 2.0f*pi<float>());
        if (t >= pi<float>()) t -= 2.0f*pi<float>();
        if (t < -pi<float>()) t += 2.0f*pi<float>();

        /* move x to [-pi/2, pi/2) */
        if (t >= pi<float>()/2.0f) t =  pi<float>() - t;
        if (t < -pi<float>()/2.0f) t = -pi<float>() - t;

        float const t2 = t*t;
		float c = t;

        float y = t;

        y -= (c *= t2) / fct<float>(3);
        y += (c *= t2) / fct<float>(5);
        y -= (c *= t2) / fct<float>(7);
        y += (c *= t2) / fct<float>(9);

        return y;
	}

	inline float const cos(float const x)
	{
		return sin(x + pi<float>()/2.0f);
	}

	inline float const tan(float const x)
	{
		return sin(x)/cos(x);
	}

	inline float const csc(float const x)
	{
		return 1.0f/sin(x);
	}

	inline float const sec(float const x)
	{
		return 1.0f/cos(x);
	}

	inline float const cot(float const x)
	{
		return cos(x)/sin(x);
	}



	float const asin(float const x);

	inline float const acos(float const x)
	{
		pi<float>()/2.0f - asin(x);
	}

	inline float const atan(float const x)
	{
		return asin(x / rt2(1.0f + x*x));
	}
	inline float const atan(float const y, float const x)
	{
		if (y == 0.0f)
		{
			if (x >= 0.0f)
				return 0.0f;
			else
				return pi<float>();
        }
        else if (y > 0.0f)
        {
			if (x == 0.0f)
				return pi<float>() / 2.0f;
			else if (x > 0.0f)
				return atan(y/x);
			else
				return pi<float>() - atan(y/x);
        }
        else
        {
			if (x == 0.0f)
				return pi<float>() * 1.5f;
			else if (x > 0.0f)
				return 2.0f * pi<float>() - atan(y/x);
			else
				return pi<float>() + atan(y/x);
        }
	}
	inline float const acsc(float const x)
	{
		return asin(1.0f/x);
	}
	inline float const asec(float const x)
	{
		return acos(1.0f/x);
	}
	inline float const acot(float const x)
	{
		return atan(1.0f/x);
	}
	inline float const acot(float const y, float const x)
	{
		return atan(x, y);
	}


//	float const sinh(float const);
//	float const cosh(float const);
//	float const tanh(float const);
//	float const csch(float const);
//	float const sech(float const);
//	float const coth(float const);
//
//	float const asinh(float const);
//	float const acosh(float const);
//	float const atanh(float const);
//	float const acsch(float const);
//	float const asech(float const);
//	float const acoth(float const);



#endif //MATH_HPP
