#ifndef BOOST_NUMBER_HPP
	#define BOOST_NUMBER_HPP

	#include <boost/cstdint.hpp>
	#include <boost/detail/endian.hpp>
	#include <boost/none.hpp>
	#include <boost/type_traits.hpp>
	#include <boost/utility/enable_if.hpp>

	namespace boost
	{
		namespace detail
		{
			template <size_t x>
			struct round_to_multiple_of_8

			template <size_t size>
			class bint
			{
				static_assert((!(size & (size - 1)) && size), "Size of integer is not a power of two.");
				static_assert((size != 1) || (size != 2) || (size != 4), "Size of integer is less than eight.");

				template <size_t that_size>
				friend uint8_t* get(bint<that_size>&);
				template <size_t that_size>
				friend uint8_t const* get(bint<that_size> const&);

				private:

					uint8_t data[size/8];

			};


			template <size_t size>
			uint8_t* get(bint<size>& x)
			{
				return x.data;
			}
			template <size_t size>
			uint8_t const* get(bint<size> const& x)
			{
				return x.data;
			}


			template <size_t bytes>
			inline void static_copy(uint8_t* dst, uint8_t const* src)
			{
				for (size_t i = 0; i < bytes; ++i)
				{
					dst[i] = src[i];
				}
			}

			template <size_t bytes, bool value>
			inline void static_fill(uint8_t* dst)
			{
				for (size_t i = 0; i < bytes; ++i)
				{
					dst[i] = ((value) ? ~0 : 0);
				}
			}



//			inline void bit_copy
//			(
//				uint8_t const* src_base,
//				size_t src_bit,
//				uint8_t* dst_base,
//				size_t dst_bit,
//				size_t amount
//			)
//			{
//				src_base += src_bit/8;
//				src_bit %= 8;
//				dst_base += dst_bit/8;
//				dst_bit %= 8;
//
//				while (amount >= 8)
//				{
//					uint8_t buf = ((*src_base) >> src_bit) | ((*(src_base+1)) << (8-src_bit));
//					++src_base;
//					(*dst_base) = ((*dst_base) & ((1 << dst_bit)-1)) | (buf << dst_bit);
//					++dst_base;
//					(*dst_base) = ((*dst_base) & (~((1 << dst_bit)-1))) | (buf >> (8-dst_bit));
//
//					amount -= 8;
//				}
//
//			}


//			template <size_t size>
//			struct native;
//
//			template <>
//			struct native<8>
//			{
//				typedef int8_t s_type;
//				typedef uint8_t u_type;
//			};
//
//			template <>
//			struct native<16>
//			{
//				typedef int16_t s_type;
//				typedef uint16_t u_type;
//			};
//
//			template <>
//			struct native<32>
//			{
//				typedef int32_t s_type;
//				typedef uint32_t u_type;
//			};
//
//			template <>
//			struct native<64>
//			{
//				typedef int64_t s_type;
//				typedef uint64_t u_type;
//			};
//
//			typedef native<64> native_max;



//			template <size_t const _base_bit, size_t const _bit_count>
//			class bit_stream
//			{
//				private:
//
//					uint8_t* _base_byte;
//
//					uint8_t* _base_byte;
//					size_t _bit;
//
//
//			}



			template <size_t const index>
			inline uint8_t const get_byte_impl(void const* const src)
			{
				return (((*((uint8_t const*)src + 1)) << 8) | (*(uint8_t const*)src)) >> index;
			}
			template <>
			inline uint8_t const get_byte_impl<0>(void const* const src)
			{
				return *(uint8_t const*)src;
			}
			template <size_t const index>
			inline uint8_t const get_byte(void const* const src)
			{
				return get_byte_impl<index % 8>((uint8_t const*)src + index/8);
			}


			template <size_t const index>
			inline void put_byte_impl(void* const dst, uint8_t const b)
			{
				*((uint8_t*)dst) = (b << index) | ((*((uint8_t*)dst)) & (~((~0) << index)));
				*((uint8_t*)dst + 1) = ((*((uint8_t*)dst + 1)) & ((~0) << index)) | (b >> (8 - index));
			}
			template <>
			inline void put_byte_impl<0>(void* const dst, uint8_t const b)
			{
				*((uint8_t*)dst) = b;
			}
			template <size_t const index>
			inline void put_byte(void* const dst, uint8_t const b)
			{
				put_byte_impl<index % 8>((uint8_t*)dst + index/8, b);
			}




			template <size_t const index, size_t const count>
			inline int const get_bits_impl(void const* const src)
			{
				static_assert(count < sizeof(int)*8, "trying to extract too many bits");

				//return (((*((uint8_t const*)src + 1)) << 8) | (*(uint8_t const*)src)) >> index;
			}
//			template <>
//			inline uint8_t const get_byte_impl<0>(void const* const src)
//			{
//				return *(uint8_t const*)src;
//			}
//			template <size_t const index>
//			inline uint8_t const get_byte(void const* const src)
//			{
//				return get_byte_impl<index % 8>((uint8_t const*)src + index/8);
//			}




//			template <size_t const src_bit, size_t const dst_bit, size_t const amount>
//			inline void copy
//			(
//				void const* const src_base,
//				void* const dst_base
//			)
//			{
//				uint8_t const* s = src_base + src_bit/8;
//				size_t const sb = src_bit%8;
//				uint8_t* d = dst_base + dst_bit/8;
//				size_t const db = dst_bit%8;
//
//				uint32_t b = 0;
//				size_t bs = 0;
//
//				size_t c = amount;
//
//				//////////
//
//				b = (((*(s+1)) << 8) | (*s)) >> sb;
//				bs += 16-sb;
//
//				while (c)
//				{
//					b |= ((((*(s+1)) << 8) | (*s)) >> sb) << bs;
//					bs += 16-sb;
//
//
//					++src_base;
//					(*dst_base) = ((*dst_base) & ((1 << dst_bit)-1)) | (buf << dst_bit);
//					++dst_base;
//					(*dst_base) = ((*dst_base) & (~((1 << dst_bit)-1))) | (buf >> (8-dst_bit));
//
//					amount -= 8;
//				}
//
//			}


		}


		template <size_t size>
		class sint;

		template <size_t size>
		class uint;



		template <size_t size>
		class sint : public detail::bint<size>
		{
			public:

					//default constructor does no initialization
				sint() = default;

					//assignment is bitwise
				sint& operator=(sint const&) = default;

					//cast sint down to sint
				template <size_t that_size>
				sint(sint<that_size> const& that, typename enable_if_c<(size < that_size), none_t>::type = none)
				{
					using namespace detail;

					static_copy<size/8>(get(*this), get(that));
				}

					//sint to sint
				sint(sint const& that) = default;

					//sint up to sint
				template <size_t that_size>
				sint(sint<that_size> const& that, typename enable_if_c<(size > that_size), none_t>::type = none)
				{
					using namespace detail;

					static_copy<that_size/8>(get(*this), get(that));

					if (get(that)[that_size/8-1] & 0x80)
					{
						static_fill<(size-that_size)/8, 1>(get(*this) + that_size/8);
					}
					else
					{
						static_fill<(size-that_size)/8, 0>(get(*this) + that_size/8);
					}
				}


					//signed native integer to sint
				template <class T>
				sint(T x, typename enable_if_c<is_integral<T>::value && is_signed<T>::value, none_t>::type = none)
				{
					*this = *(sint<sizeof(T)*8>*)&x;
				}
					//unsigned native integer to sint
				template <class T>
				sint(T x, typename enable_if_c<is_integral<T>::value && is_unsigned<T>::value, none_t>::type = none)
				{
					*this = *(uint<sizeof(T)*8>*)&x;
				}


		};








//			/** \brief Integer negation
//			 * Negates integer
//			 */
//		template <unsigned long size>
//		inline memory_holder<size> const operator-(memory_holder<size> const& x)
//		{
//			memory_holder<size> result;
//			unsigned int carry = 0;
//
//			for (unsigned long i = 0; i < size/8; ++i)
//			{
//				carry -= ((std::uint8_t*)&x)[i];
//				((std::uint8_t*)&result)[i] = carry;
//				carry >>= 8;
//			}
//
//			return result;
//		}
//
//
//			/** \brief Integer addition
//			 * Adds two integers returning the result of the same size as the biggest operand size
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<(size_l < size_r ? size_r : size_l)> const operator+(memory_holder<size_l> const& l, memory_holder<size_r> const& r)
//		{
//			memory_holder<(size_l < size_r ? size_r : size_l)> result;
//
//				//if size of the left integer is smaller than the size of the right one...
//			if (size_l < size_r)
//			{
//					//...cast it to the same size
//				memory_holder<size_r> const t(l);
//
//				unsigned int carry = 0;
//
//					//and add them
//				for (unsigned long i = 0; i < size_r/8; ++i)
//				{
//					carry += ((std::uint8_t*)&t)[i] + ((std::uint8_t*)&r)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//			else if (size_l > size_r) //otherwise, if size of the right integer is smaller than the size of the left one...
//			{
//					//...cast it to the same size
//				memory_holder<size_l> const t(r);
//
//				unsigned int carry = 0;
//
//					//and add them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					carry += ((std::uint8_t*)&l)[i] + ((std::uint8_t*)&t)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//			else //otherwise, if size of the right integer is equal to the size of the left one...
//			{
//				unsigned int carry = 0;
//
//					//add them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					carry += ((std::uint8_t*)&l)[i] + ((std::uint8_t*)&r)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//
//			return result;
//		}
//
//			/** \brief Integer addition with assignment
//			 * Adds two integers storing the result in the left operand
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<size_l>& operator+=(memory_holder<size_l>& l, memory_holder<size_r> const& r)
//		{
//			return l = l+r;
//		}
//
//			/** \brief Integer substraction
//			 * Substracts two integers returning the result of the same size as the biggest operand size
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<(size_l < size_r ? size_r : size_l)> const operator-(memory_holder<size_l> const& l, memory_holder<size_r> const& r)
//		{
//			memory_holder<(size_l < size_r ? size_r : size_l)> result;
//
//				//if size of the left integer is smaller than the size of the right one...
//			if (size_l < size_r)
//			{
//					//...cast it to the same size
//				memory_holder<size_r> const t(l);
//
//				unsigned int carry = 0;
//
//					//and substract them
//				for (unsigned long i = 0; i < size_r/8; ++i)
//				{
//					carry += ((std::uint8_t*)&t)[i] - ((std::uint8_t*)&r)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//			else if (size_l > size_r) //otherwise, if size of the right integer is smaller than the size of the left one...
//			{
//					//...cast it to the same size
//				memory_holder<size_l> const t(r);
//
//				unsigned int carry = 0;
//
//					//and substract them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					carry += ((std::uint8_t*)&l)[i] - ((std::uint8_t*)&t)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//			else //otherwise, if size of the right integer is equal to the size of the left one...
//			{
//				unsigned int carry = 0;
//
//					//and substract them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					carry += ((std::uint8_t*)&l)[i] - ((std::uint8_t*)&r)[i];
//					((std::uint8_t*)&result)[i] = carry;
//					carry >>= 8;
//				}
//			}
//
//			return result;
//		}
//
//			/** \brief Integer substraction with assignment
//			 * Substracts two integers storing the result in the left operand
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<size_l>& operator-=(memory_holder<size_l>& l, memory_holder<size_r> const& r)
//		{
//			return l = l-r;
//		}
//
//			/** \brief Integer multiplication
//			 * Multiplies two integers returning the result of the same size as the biggest operand size
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<(size_l < size_r ? size_r : size_l)> const operator*(memory_holder<size_l> const& l, memory_holder<size_r> const& r)
//		{
//			memory_holder<(size_l < size_r ? size_r : size_l)> result;
//
//				//set result to zero
//			for (unsigned long i = 0; i < (size_l < size_r ? size_r : size_l)/8; ++i)
//			{
//				((std::uint8_t*)&result)[i] = 0x00;
//			}
//
//				//if size of the left integer is smaller than the size of the right one...
//			if (size_l < size_r)
//			{
//					//...cast it to the same size
//				memory_holder<size_r> const t(l);
//
//					//and multiply them
//				for (unsigned long i = 0; i < size_r/8; ++i)
//				{
//					memory_holder<size_r> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_r/8; ++j)
//					{
//						carry += ((std::uint8_t*)&t)[j-i] * ((std::uint8_t*)&r)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//			else if (size_l > size_r) //otherwise, if size of the right integer is smaller than the size of the left one...
//			{
//					//...cast it to the same size
//				memory_holder<size_l> const t(r);
//
//					//and multiply them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					memory_holder<size_l> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_l/8; ++j)
//					{
//						carry += ((std::uint8_t*)&t)[j-i] * ((std::uint8_t*)&l)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//			else //otherwise, if size of the right integer is equal to the size of the left one...
//			{
//					//multiply them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					memory_holder<size_l> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_l/8; ++j)
//					{
//						carry += ((std::uint8_t*)&r)[j-i] * ((std::uint8_t*)&l)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//
//			return result;
//		}
//
//			/** \brief Integer multiplication with assignment
//			 * Multiplies two integers storing the result in the left operand
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<size_l>& operator*=(memory_holder<size_l>& l, memory_holder<size_r> const& r)
//		{
//			return l = l*r;
//		}
//
//			/** \brief Integer division
//			 * Divides two integers returning the result of the same size as the biggest operand size
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<(size_l < size_r ? size_r : size_l)> const operator/(memory_holder<size_l> const& l, memory_holder<size_r> const& r)
//		{
//			memory_holder<(size_l < size_r ? size_r : size_l)> result;
//
//				//set result to zero
//			for (unsigned long i = 0; i < (size_l < size_r ? size_r : size_l)/8; ++i)
//			{
//				((std::uint8_t*)&result)[i] = 0x00;
//			}
//
//				//if size of the left integer is smaller than the size of the right one...
//			if (size_l < size_r)
//			{
//					//...cast it to the same size
//				memory_holder<size_r> const t(l);
//
//					//and multiply them
//				for (unsigned long i = 0; i < size_r/8; ++i)
//				{
//					memory_holder<size_r> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_r/8; ++j)
//					{
//						carry += ((std::uint8_t*)&t)[j-i] * ((std::uint8_t*)&r)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//			else if (size_l > size_r) //otherwise, if size of the right integer is smaller than the size of the left one...
//			{
//					//...cast it to the same size
//				memory_holder<size_l> const t(r);
//
//					//and multiply them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					memory_holder<size_l> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_l/8; ++j)
//					{
//						carry += ((std::uint8_t*)&t)[j-i] * ((std::uint8_t*)&l)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//			else //otherwise, if size of the right integer is equal to the size of the left one...
//			{
//					//multiply them
//				for (unsigned long i = 0; i < size_l/8; ++i)
//				{
//					memory_holder<size_l> const temp;
//					unsigned int carry = 0;
//
//					for (unsigned long j = 0; j < i; ++j)
//					{
//						((std::uint8_t*)&temp)[j] = 0x00;
//					}
//					for (unsigned long j = i; j < size_l/8; ++j)
//					{
//						carry += ((std::uint8_t*)&r)[j-i] * ((std::uint8_t*)&l)[i];
//						((std::uint8_t*)&temp)[j] = carry;
//						carry >>= 8;
//					}
//
//					result += temp;
//				}
//			}
//
//			return result;
//		}
//
//			/** \brief Integer division with assignment
//			 * Divides two integers storing the result in the left operand
//			 */
//		template <unsigned long size_l, unsigned long size_r>
//		inline memory_holder<size_l>& operator/=(memory_holder<size_l>& l, memory_holder<size_r> const& r)
//		{
//			return l = l/r;
//		}

	}


#endif //BOOST_NUMBER_HPP





//				//static integral power
//			template <unsigned long base, unsigned long exp>
//			struct pow
//			{
//				static unsigned long const value = base * pow<base, exp-1>::value;
//			};
//			template <unsigned long base>
//			struct pow<base, 0>
//			{
//				static unsigned long const value = 1;
//			};
//
//				//static integral logarithm
//			template <unsigned long base, unsigned long val>
//			struct log
//			{
//				static unsigned long const value = 1+log<base, val/base>::value;
//			};
//			template <unsigned long base>
//			struct log<base, 1>
//			{
//				static unsigned long const value = 0;
//			};
//				//evil cases
//			template <unsigned long base>
//			struct log<base, 0>
//			{
//
//			};
//			template <unsigned long val>
//			struct log<0, val>
//			{
//
//			};
//			template <unsigned long val>
//			struct log<1, val>
//			{
//
//			};
//			template <>
//			struct log<0, 0>
//			{
//
//			};
