#ifndef CRC_HPP
	#define CRC_HPP

	#include "int.hpp"
	#include "byte.hpp"
	#include "size.hpp"

	namespace _impl
	{
		namespace _crc
		{
			template <typename T, const T mirror_polynom>
			struct Table
			{
				private:

					T _data[256];

					Table()
					{
						for (Size i = 0; i < 256; ++i)
						{
							_data[i] = i;
							for (Size j = 0; j < 8; ++j)
								_data[i] = (_data[i] >> 1) ^ (_data[i] & 1 ? mirror_polynom : 0);
						}
					}

					static Table const _instance;

				public:

					static T const at(Size index)
					{
						return _instance._data[index];
					}
			};

			template <typename T, const T mirror_polynom>
			Table<T, mirror_polynom> const Table<T, mirror_polynom>::_instance;
		}
	}

	template <Size bits, typename UIntExact<bits>::Type mirror_polynom, typename UIntExact<bits>::Type initial_value, typename UIntExact<bits>::Type final_value>
	inline typename UIntExact<bits>::Type const crc(Byte const* data, Size size, typename UIntExact<bits>::Type hash = initial_value ^ final_value)
	{
		hash ^= final_value;
		while (size--)
			hash = (hash >> 8) ^ _impl::_crc::Table<typename UIntExact<bits>::Type, mirror_polynom>::at((*(data++) ^ hash) & 0xFF);
		return hash ^ final_value;
	}



	/*******************************************************************************
	   Some common parameters:

	   Standard CRC-8 generator polynomial:
		   Name               : CRC-8 Standard
		   Standards          : -
		   References         : -
		   Initializing value : FF
		   Finalizing value   : FF
		   Polynomial value   : 31 (Mirror value = 8C)
		   Polynom            : x^8 + x^5 + x^4 + 1

	   Standard CRC-16 generator polynomial:
		   Name               : CRC-16 Standard
		   Standards          : ITU X.25/T.30
		   References         : LHA
		   Initializing value : 0000
		   Finalizing value   : 0000
		   Polynomial value   : 8005 (Mirror value = A001)
		   Polynom            : x^16 + x^15 + x^2 + 1

	   Standard CRC-32 generator polynomial:
		   Name               : CRC-32 Standard
		   Standards          : ISO 3309, ITU-T V.42, ANSI X3.66, FIPS PUB 71
		   References         : ZIP, RAR, Ethernet, AUTODIN II, FDDI
		   Initializing value : FFFFFFFF
		   Finalizing value   : FFFFFFFF
		   Polynomial value   : 04C11DB7 (Mirror value = EDB88320)
		   Polynom            : x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 +
								x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1

	   Standard CRC-64 generator polynomial:
		   Name               : CRC-64 Standard
		   Standards          : ISO 3309
		   References         : -
		   Initializing value : FFFFFFFFFFFFFFFF
		   Finalizing value   : FFFFFFFFFFFFFFFF
		   Polynomial value   : 000000000000001B (Mirror value = D800000000000000)
		   Polynom            : x^64 + x^4 + x^3 + x + 1

	******************************************************************************/

	inline UInt8 const crc8(Byte const* data, Size size)
	{
		return crc<8, 0x8C, 0xFF, 0xFF>(data, size);
	}
	inline UInt8 const crc8(Byte const* data, Size size, UInt8 hash)
	{
		return crc<8, 0x8C, 0xFF, 0xFF>(data, size, hash);
	}

	inline UInt16 const crc16(Byte const* data, Size size)
	{
		return crc<16, 0xA001, 0x0000, 0x0000>(data, size);
	}
	inline UInt16 const crc16(Byte const* data, Size size, UInt16 hash)
	{
		return crc<16, 0xA001, 0x0000, 0x0000>(data, size, hash);
	}

	inline UInt32 const crc32(Byte const* data, Size size)
	{
		return crc<32, 0xEDB88320, 0xFFFFFFFF, 0xFFFFFFFF>(data, size);
	}
	inline UInt32 const crc32(Byte const* data, Size size, UInt32 hash)
	{
		return crc<32, 0xEDB88320, 0xFFFFFFFF, 0xFFFFFFFF>(data, size, hash);
	}

	inline UInt64 const crc64(Byte const* data, Size size)
	{
		return crc<64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF>(data, size);
	}
	inline UInt64 const crc64(Byte const* data, Size size, UInt64 hash)
	{
		return crc<64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF>(data, size, hash);
	}

#endif //CRC_HPP
