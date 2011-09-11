#ifndef FLT_N_HPP
	#define FLT_N_HPP

	#include "flt.hpp"
	#include "if.hpp"

	typedef If<(sizeof(float) == 4), float>::Type Flt32;

	typedef If<(sizeof(double) == 8), double>::Type Flt64;

#endif //FLT_N_HPP
