#ifndef ENDIAN_HPP
	#define ENDIAN_HPP

	#include "int_n.hpp"


		//i8
	inline Int8 endian_htol(Int8 x)
	{
		return x;
	}

	inline Int8 endian_htob(Int8 x)
	{
		return x;
	}

	inline Int8 endian_ltoh(Int8 x)
	{
		return x;
	}

	inline Int8 endian_btoh(Int8 x)
	{
		return x;
	}

	inline Int8 endian_swap(Int8 x)
	{
		return x;
	}

		//u8
	inline UInt8 endian_htol(UInt8 x)
	{
		return x;
	}

	inline UInt8 endian_htob(UInt8 x)
	{
		return x;
	}

	inline UInt8 endian_ltoh(UInt8 x)
	{
		return x;
	}

	inline UInt8 endian_btoh(UInt8 x)
	{
		return x;
	}

	inline UInt8 endian_swap(UInt8 x)
	{
		return x;
	}


		//i16
	inline Int16 endian_htol(Int16 x)
	{
		union
		{
			UInt8 b[2];
			Int16 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		return v;
	}

	inline Int16 endian_htob(Int16 x)
	{
		union
		{
			UInt8 b[2];
			Int16 v;
		};
		b[0] = x >> 0x08;
		b[1] = x >> 0x00;
		return v;
	}

	inline Int16 endian_ltoh(Int16 x)
	{
		union
		{
			UInt8 b[2];
			Int16 v;
		};
		v = x;
		return (Int16(b[0]) << 0x00)
		     | (Int16(b[1]) << 0x08);
	}

	inline Int16 endian_btoh(Int16 x)
	{
		union
		{
			UInt8 b[2];
			Int16 v;
		};
		v = x;
		return (Int16(b[0]) << 0x08)
		     | (Int16(b[1]) << 0x00);
	}

	inline Int16 endian_swap(Int16 x)
	{
		return ((x << 0x08) & 0xFF00)
		     | ((x >> 0x08) & 0x00FF);
	}

		//u16
	inline UInt16 endian_htol(UInt16 x)
	{
		union
		{
			UInt8 b[2];
			UInt16 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		return v;
	}

	inline UInt16 endian_htob(UInt16 x)
	{
		union
		{
			UInt8 b[2];
			UInt16 v;
		};
		b[0] = x >> 0x08;
		b[1] = x >> 0x00;
		return v;
	}

	inline UInt16 endian_ltoh(UInt16 x)
	{
		union
		{
			UInt8 b[2];
			UInt16 v;
		};
		v = x;
		return (UInt16(b[0]) << 0x00)
		     | (UInt16(b[1]) << 0x08);
	}

	inline UInt16 endian_btoh(UInt16 x)
	{
		union
		{
			UInt8 b[2];
			UInt16 v;
		};
		v = x;
		return (UInt16(b[0]) << 0x08)
		     | (UInt16(b[1]) << 0x00);
	}

	inline UInt16 endian_swap(UInt16 x)
	{
		return ((x << 0x08) & 0xFF00)
		     | ((x >> 0x08) & 0x00FF);
	}


		//i32
	inline Int32 endian_htol(Int32 x)
	{
		union
		{
			UInt8 b[4];
			Int32 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		b[2] = x >> 0x10;
		b[3] = x >> 0x18;
		return v;
	}

	inline Int32 endian_htob(Int32 x)
	{
		union
		{
			UInt8 b[4];
			Int32 v;
		};
		b[0] = x >> 0x18;
		b[1] = x >> 0x10;
		b[2] = x >> 0x08;
		b[3] = x >> 0x00;
		return v;
	}

	inline Int32 endian_ltoh(Int32 x)
	{
		union
		{
			UInt8 b[4];
			Int32 v;
		};
		v = x;
		return (Int32(b[0]) << 0x00)
		     | (Int32(b[1]) << 0x08)
		     | (Int32(b[2]) << 0x10)
		     | (Int32(b[3]) << 0x18);
	}

	inline Int32 endian_btoh(Int32 x)
	{
		union
		{
			UInt8 b[4];
			Int32 v;
		};
		v = x;
		return (Int32(b[0]) << 0x18)
		     | (Int32(b[1]) << 0x10)
		     | (Int32(b[2]) << 0x08)
		     | (Int32(b[3]) << 0x00);
	}

	inline Int32 endian_swap(Int32 x)
	{
		return ((x << 0x18) & 0xFF000000)
		     | ((x << 0x08) & 0x00FF0000)
		     | ((x >> 0x08) & 0x0000FF00)
		     | ((x >> 0x18) & 0x000000FF);
	}

		//u32
	inline UInt32 endian_htol(UInt32 x)
	{
		union
		{
			UInt8 b[4];
			UInt32 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		b[2] = x >> 0x10;
		b[3] = x >> 0x18;
		return v;
	}

	inline UInt32 endian_htob(UInt32 x)
	{
		union
		{
			UInt8 b[4];
			UInt32 v;
		};
		b[0] = x >> 0x18;
		b[1] = x >> 0x10;
		b[2] = x >> 0x08;
		b[3] = x >> 0x00;
		return v;
	}

	inline UInt32 endian_ltoh(UInt32 x)
	{
		union
		{
			UInt8 b[4];
			UInt32 v;
		};
		v = x;
		return (UInt32(b[0]) << 0x00)
		     | (UInt32(b[1]) << 0x08)
		     | (UInt32(b[2]) << 0x10)
		     | (UInt32(b[3]) << 0x18);
	}

	inline UInt32 endian_btoh(UInt32 x)
	{
		union
		{
			UInt8 b[4];
			UInt32 v;
		};
		v = x;
		return (UInt32(b[0]) << 0x18)
		     | (UInt32(b[1]) << 0x10)
		     | (UInt32(b[2]) << 0x08)
		     | (UInt32(b[3]) << 0x00);
	}

	inline UInt32 endian_swap(UInt32 x)
	{
		return ((x << 0x18) & 0xFF000000)
		     | ((x << 0x08) & 0x00FF0000)
		     | ((x >> 0x08) & 0x0000FF00)
		     | ((x >> 0x18) & 0x000000FF);
	}


		//i64
	inline Int64 endian_htol(Int64 x)
	{
		union
		{
			UInt8 b[8];
			Int64 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		b[2] = x >> 0x10;
		b[3] = x >> 0x18;
		b[4] = x >> 0x20;
		b[5] = x >> 0x28;
		b[6] = x >> 0x30;
		b[7] = x >> 0x38;
		return v;
	}

	inline Int64 endian_htob(Int64 x)
	{
		union
		{
			UInt8 b[8];
			Int64 v;
		};
		b[0] = x >> 0x38;
		b[1] = x >> 0x30;
		b[2] = x >> 0x28;
		b[3] = x >> 0x20;
		b[4] = x >> 0x18;
		b[5] = x >> 0x10;
		b[6] = x >> 0x08;
		b[7] = x >> 0x00;
		return v;
	}

	inline Int64 endian_ltoh(Int64 x)
	{
		union
		{
			UInt8 b[8];
			Int64 v;
		};
		v = x;
		return (Int64(b[0]) << 0x00)
		     | (Int64(b[1]) << 0x08)
		     | (Int64(b[2]) << 0x10)
		     | (Int64(b[3]) << 0x18)
		     | (Int64(b[4]) << 0x20)
		     | (Int64(b[5]) << 0x28)
		     | (Int64(b[6]) << 0x30)
		     | (Int64(b[7]) << 0x38);
	}

	inline Int64 endian_btoh(Int64 x)
	{
		union
		{
			UInt8 b[8];
			Int64 v;
		};
		v = x;
		return (Int64(b[0]) << 0x38)
		     | (Int64(b[1]) << 0x30)
		     | (Int64(b[2]) << 0x28)
		     | (Int64(b[3]) << 0x20)
		     | (Int64(b[4]) << 0x18)
		     | (Int64(b[5]) << 0x10)
		     | (Int64(b[6]) << 0x08)
		     | (Int64(b[7]) << 0x00);
	}

	inline Int64 endian_swap(Int64 x)
	{
		return ((x << 0x38) & 0xFF00000000000000)
		     | ((x << 0x28) & 0x00FF000000000000)
		     | ((x << 0x18) & 0x0000FF0000000000)
		     | ((x << 0x08) & 0x000000FF00000000)
		     | ((x >> 0x08) & 0x00000000FF000000)
		     | ((x >> 0x18) & 0x0000000000FF0000)
		     | ((x >> 0x28) & 0x000000000000FF00)
		     | ((x >> 0x38) & 0x00000000000000FF);
	}

		//u64
	inline UInt64 endian_htol(UInt64 x)
	{
		union
		{
			UInt8 b[8];
			UInt64 v;
		};
		b[0] = x >> 0x00;
		b[1] = x >> 0x08;
		b[2] = x >> 0x10;
		b[3] = x >> 0x18;
		b[4] = x >> 0x20;
		b[5] = x >> 0x28;
		b[6] = x >> 0x30;
		b[7] = x >> 0x38;
		return v;
	}

	inline UInt64 endian_htob(UInt64 x)
	{
		union
		{
			UInt8 b[8];
			UInt64 v;
		};
		b[0] = x >> 0x38;
		b[1] = x >> 0x30;
		b[2] = x >> 0x28;
		b[3] = x >> 0x20;
		b[4] = x >> 0x18;
		b[5] = x >> 0x10;
		b[6] = x >> 0x08;
		b[7] = x >> 0x00;
		return v;
	}

	inline UInt64 endian_ltoh(UInt64 x)
	{
		union
		{
			UInt8 b[8];
			UInt64 v;
		};
		v = x;
		return (UInt64(b[0]) << 0x00)
		     | (UInt64(b[1]) << 0x08)
		     | (UInt64(b[2]) << 0x10)
		     | (UInt64(b[3]) << 0x18)
		     | (UInt64(b[4]) << 0x20)
		     | (UInt64(b[5]) << 0x28)
		     | (UInt64(b[6]) << 0x30)
		     | (UInt64(b[7]) << 0x38);
	}

	inline UInt64 endian_btoh(UInt64 x)
	{
		union
		{
			UInt8 b[8];
			UInt64 v;
		};
		v = x;
		return (UInt64(b[0]) << 0x38)
		     | (UInt64(b[1]) << 0x30)
		     | (UInt64(b[2]) << 0x28)
		     | (UInt64(b[3]) << 0x20)
		     | (UInt64(b[4]) << 0x18)
		     | (UInt64(b[5]) << 0x10)
		     | (UInt64(b[6]) << 0x08)
		     | (UInt64(b[7]) << 0x00);
	}

	inline UInt64 endian_swap(UInt64 x)
	{
		return ((x << 0x38) & 0xFF00000000000000)
		     | ((x << 0x28) & 0x00FF000000000000)
		     | ((x << 0x18) & 0x0000FF0000000000)
		     | ((x << 0x08) & 0x000000FF00000000)
		     | ((x >> 0x08) & 0x00000000FF000000)
		     | ((x >> 0x18) & 0x0000000000FF0000)
		     | ((x >> 0x28) & 0x000000000000FF00)
		     | ((x >> 0x38) & 0x00000000000000FF);
	}



	#include "flt_n.hpp"


		//f32
	inline Flt32 endian_htol(Flt32 x)
	{
		union
		{
			Int32 i;
			Flt32 f;
		};
		union
		{
			UInt8 b[4];
			Flt32 o;
		};
		f = x;
		b[0] = i >> 0x00;
		b[1] = i >> 0x08;
		b[2] = i >> 0x10;
		b[3] = i >> 0x18;
		return o;
	}

	inline Flt32 endian_htob(Flt32 x)
	{
		union
		{
			Int32 i;
			Flt32 f;
		};
		union
		{
			UInt8 b[4];
			Flt32 o;
		};
		f = x;
		b[0] = i >> 0x18;
		b[1] = i >> 0x10;
		b[2] = i >> 0x08;
		b[3] = i >> 0x00;
		return o;
	}

	inline Flt32 endian_ltoh(Flt32 x)
	{
		union
		{
			Flt32 f;
			UInt8 b[4];
			Int32 i;
		};
		f = x;
		i = (Int32(b[0]) << 0x00)
		  | (Int32(b[1]) << 0x08)
		  | (Int32(b[2]) << 0x10)
		  | (Int32(b[3]) << 0x18);
		return f;
	}

	inline Flt32 endian_btoh(Flt32 x)
	{
		union
		{
			Flt32 f;
			UInt8 b[4];
			Int32 i;
		};
		f = x;
		i = (Int32(b[0]) << 0x18)
		  | (Int32(b[1]) << 0x10)
		  | (Int32(b[2]) << 0x08)
		  | (Int32(b[3]) << 0x00);
		return f;
	}

	inline Flt32 endian_swap(Flt32 x)
	{
		union
		{
			Flt32 f;
			Int32 i;
		};
		f = x;
		i = ((i << 0x18) & 0xFF000000)
		  | ((i << 0x08) & 0x00FF0000)
		  | ((i >> 0x08) & 0x0000FF00)
		  | ((i >> 0x18) & 0x000000FF);
		return f;
	}


		//f64
	inline Flt64 endian_htol(Flt64 x)
	{
		union
		{
			Int64 i;
			Flt64 f;
		};
		union
		{
			UInt8 b[8];
			Flt64 o;
		};
		f = x;
		b[0] = i >> 0x00;
		b[1] = i >> 0x08;
		b[2] = i >> 0x10;
		b[3] = i >> 0x18;
		b[4] = i >> 0x20;
		b[5] = i >> 0x28;
		b[6] = i >> 0x30;
		b[7] = i >> 0x38;
		return o;
	}

	inline Flt64 endian_htob(Flt64 x)
	{
		union
		{
			Int64 i;
			Flt64 f;
		};
		union
		{
			UInt8 b[8];
			Flt64 o;
		};
		f = x;
		b[0] = i >> 0x38;
		b[1] = i >> 0x30;
		b[2] = i >> 0x28;
		b[3] = i >> 0x20;
		b[4] = i >> 0x18;
		b[5] = i >> 0x10;
		b[6] = i >> 0x08;
		b[7] = i >> 0x00;
		return o;
	}

	inline Flt64 endian_ltoh(Flt64 x)
	{
		union
		{
			Flt64 f;
			UInt8 b[8];
			Int64 i;
		};
		f = x;
		i = (Int64(b[0]) << 0x00)
		  | (Int64(b[1]) << 0x08)
		  | (Int64(b[2]) << 0x10)
		  | (Int64(b[3]) << 0x18)
		  | (Int64(b[4]) << 0x20)
		  | (Int64(b[5]) << 0x28)
		  | (Int64(b[6]) << 0x30)
		  | (Int64(b[7]) << 0x38);
		return f;
	}

	inline Flt64 endian_btoh(Flt64 x)
	{
		union
		{
			Flt64 f;
			UInt8 b[8];
			Int64 i;
		};
		f = x;
		i = (Int64(b[0]) << 0x38)
		  | (Int64(b[1]) << 0x30)
		  | (Int64(b[2]) << 0x28)
		  | (Int64(b[3]) << 0x20)
		  | (Int64(b[4]) << 0x18)
		  | (Int64(b[5]) << 0x10)
		  | (Int64(b[6]) << 0x08)
		  | (Int64(b[7]) << 0x00);
		return f;
	}

	inline Flt64 endian_swap(Flt64 x)
	{
		union
		{
			Flt64 f;
			Int64 i;
		};
		f = x;
		i = ((i << 0x38) & 0xFF00000000000000)
		  | ((i << 0x28) & 0x00FF000000000000)
		  | ((i << 0x18) & 0x0000FF0000000000)
		  | ((i << 0x08) & 0x000000FF00000000)
		  | ((i >> 0x08) & 0x00000000FF000000)
		  | ((i >> 0x18) & 0x0000000000FF0000)
		  | ((i >> 0x28) & 0x000000000000FF00)
		  | ((i >> 0x38) & 0x00000000000000FF);
		return f;
	}




#endif //ENDIAN_HPP
