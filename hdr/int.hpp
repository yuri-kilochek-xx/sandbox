#ifndef INT_HPP
	#define INT_HPP



	typedef signed char IntTiny;

	inline IntTiny const abs(IntTiny x)
	{
		return (x < 0) ? (-x) : (x);
	}


	typedef unsigned char UIntTiny;

	inline UIntTiny const abs(UIntTiny x)
	{
		return x;
	}



	typedef signed short IntShort;

	inline IntShort const abs(IntShort x)
	{
		return (x < 0) ? (-x) : (x);
	}


	typedef unsigned short UIntShort;

	inline UIntShort const abs(UIntShort x)
	{
		return x;
	}



	typedef signed int Int;

	inline Int const abs(Int x)
	{
		return (x < 0) ? (-x) : (x);
	}


	typedef unsigned int UInt;

	inline UInt const abs(UInt x)
	{
		return x;
	}



	typedef signed long IntLong;

	inline IntLong const abs(IntLong x)
	{
		return (x < 0L) ? (-x) : (x);
	}


	typedef unsigned long UIntLong;

	inline UIntLong const abs(UIntLong x)
	{
		return x;
	}



	typedef signed long long IntHuge;

	inline IntHuge const abs(IntHuge x)
	{
		return (x < 0LL) ? (-x) : (x);
	}


	typedef unsigned long long UIntHuge;

	inline UIntHuge const abs(UIntHuge x)
	{
		return x;
	}



#endif //INT_HPP
