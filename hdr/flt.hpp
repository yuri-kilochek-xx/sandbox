#ifndef FLT_HPP
	#define FLT_HPP

	#include "bool.hpp"

	typedef float Flt;

	Flt const inf = 1.0f/0.0f;
	Flt const nan = 0.0f/0.0f;

	inline Bool const is_inf(Flt x)
	{
		return (x == inf) | (x == -inf);
	}

	inline Bool const is_nan(Flt x)
	{
		return x != x;
	}

	inline Flt const abs(Flt x)
	{
		return (x < 0.0f) ? (-x) : (x);
	}

	inline Flt const sgn(Flt x)
	{
		if (x < 0.0f)
			return -1.0f;
		else if (x > 0.0f)
			return 1.0f;
		else
			return 0.0f;
	}

//	inline Flt const mod(Flt x, Flt s)
//	{
//		Flt t = x/s;
//		if (abs(t) >= 8338608.0f) //2^23
//			return x - t*s;
//		else if (abs(t) < 1.0f)
//			return x;
//		else
//			return x - ((long)t)*s;
//	}
//
//	inline Flt const rndc(Flt x); //ceil
//	inline Flt const rndf(Flt x); //floor
//	inline Flt const rndz(Flt x); //round to zero
//	inline Flt const rndi(Flt x); //round to inf (from zero)
//	inline Flt const rnd(Flt x); //round to nearest integer


	typedef double FltLong;

	inline Bool const is_inf(FltLong x)
	{
		return (x == FltLong(inf)) | (x == -FltLong(inf));
	}

	inline Bool const is_nan(FltLong x)
	{
		return x != x;
	}

	inline FltLong const abs(FltLong x)
	{
		return (x < 0.0) ? (-x) : (x);
	}

	inline FltLong const sgn(FltLong x)
	{
		if (x < 0.0)
			return -1.0;
		else if (x > 0.0)
			return 1.0;
		else
			return 0.0;
	}


	typedef long double FltHuge;

	inline Bool const is_inf(FltHuge x)
	{
		return (x == FltHuge(inf)) | (x == -FltHuge(inf));
	}

	inline Bool const is_nan(FltHuge x)
	{
		return x != x;
	}

	inline FltHuge const abs(FltHuge x)
	{
		return (x < 0.0l) ? (-x) : (x);
	}

	inline FltHuge const sgn(FltHuge x)
	{
		if (x < 0.0l)
			return -1.0l;
		else if (x > 0.0l)
			return 1.0l;
		else
			return 0.0l;
	}



#endif //FLT_HPP
