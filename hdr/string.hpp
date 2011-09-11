#ifndef STRING_HPP
	#define STRING_HPP

	#include "byte.hpp"
	#include "size.hpp"
	#include "void.hpp"
	#include "int.hpp"



	template <Size = 0>
	class Utf;

	template <>
	class Utf<>
	{
		public:

			class InvalidCodePoint
			{
				private:

					UInt32 _value;

				public:

					InvalidCodePoint(UInt32 value)
						: _value(value)
					{

					}

					UInt32 value() const
					{
						return _value;
					}
			};

			class OutputOverflow
			{
				private:

					Size _value;

				public:

					OutputOverflow(Size value)
						: _value(value)
					{

					}

					Size excess() const
					{
						return _value;
					}
			};

			class UnexpectedEndOfInput
			{

			};

			class InvalidInput
			{

			};
	};


	template <>
	class Utf<8>
	{
		public:

			Utf() = delete;
			Utf(Utf const&) = delete;
			Utf& operator=(Utf const&) = delete;
			~Utf() = delete;

			template <typename ForwardIterator>
			static ForwardIterator encode(UInt32 code, ForwardIterator beg, ForwardIterator end)
			{
				if ((0xD7FF < code) && (code < 0xE000) || (0x10FFFF < code)) //code is invalid
					throw Utf<>::InvalidCodePoint(code);

				if (code < 0x80) //one byte
				{
					if (beg != end)
						*beg++ = code;
					else
						throw Utf<>::OutputOverflow(1);
				}
				else if (code < 0x800) //two bytes
				{
					if (beg != end)
						*beg++ = 0xC0 | (0x1F & (code >> 6));
					else
						throw Utf<>::OutputOverflow(2);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 0));
					else
						throw Utf<>::OutputOverflow(1);
				}
				else if (code < 0x10000) //three bytes
				{
					if (beg != end)
						*beg++ = 0xE0 | (0x0F & (code >> 12));
					else
						throw Utf<>::OutputOverflow(3);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 6));
					else
						throw Utf<>::OutputOverflow(2);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 0));
					else
						throw Utf<>::OutputOverflow(1);
				}
				else //four bytes
				{
					if (beg != end)
						*beg++ = 0xF0 | (0x07 & (code >> 18));
					else
						throw Utf<>::OutputOverflow(4);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 12));
					else
						throw Utf<>::OutputOverflow(3);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 6));
					else
						throw Utf<>::OutputOverflow(2);

					if (beg != end)
						*beg++ = 0x80 | (0x3F & (code >> 0));
					else
						throw Utf<>::OutputOverflow(1);
				}
				return beg;
			}

			template <typename ForwardIterator>
			static ForwardIterator decode(UInt32* code, ForwardIterator beg, ForwardIterator end)
			{
				if (beg != end)
				{
					if ((*beg & 0x80) == 0x00) // 0xxxxxxx //one byte
					{
						*code = *beg++;
					}
					else if ((*beg & 0xE0) == 0xC0) // 110xxxxx //two bytes
					{
						*code = (*beg & 0x1F) << 6;

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= *beg & 0x3F;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();
					}
					else if ((*beg & 0xF0) == 0xE0)  // 1110xxxx //three bytes
					{
						*code = (*beg & 0x0F) << 12;

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= (*beg & 0x3F) << 6;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= *beg & 0x3F;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();
					}
					else if ((*beg & 0xF8) == 0xF0)  // 11110xxx //four bytes
					{
						*code = (*beg & 0x07) << 18;

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= (*beg & 0x3F) << 12;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= (*beg & 0x3F) << 6;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();

						if (++beg != end)
							if ((*beg & 0xC0) == 0x80) // 10xxxxxx
								*code |= *beg & 0x3F;
							else
								throw Utf<>::InvalidInput();
						else
							throw Utf<>::UnexpectedEndOfInput();
					}

					if (((0xD7FF < *code) && (*code < 0xE000)) || (0x10FFFF < *code)) //code is invalid
						throw Utf<>::InvalidCodePoint(*code);
				}
				else
					throw Utf<>::UnexpectedEndOfInput();

				return beg;
			}
	};




	template <>
	class Utf<32>
	{
		public:

			Utf() = delete;
			Utf(Utf const&) = delete;
			Utf& operator=(Utf const&) = delete;
			~Utf() = delete;

			template <typename ForwardIterator>
			static ForwardIterator encode(UInt32 code, ForwardIterator beg, ForwardIterator end)
			{
				if (((0xD7FF < code) && (code < 0xE000)) || (0x10FFFF < code)) //code is invalid
					throw Utf<>::InvalidCodePoint(code);

				if (beg != end)
					*beg++ = code;
				else
					throw Utf<>::OutputOverflow(1);

				return beg;
			}

			template <typename ForwardIterator>
			static ForwardIterator decode(UInt32* code, ForwardIterator beg, ForwardIterator end)
			{
				if (beg != end)
				{
					*code = *beg++;
					if ((0xD7FF < *code) && (*code < 0xE000) || (0x10FFFF < *code)) //code is invalid
						throw Utf<>::InvalidCodePoint(*code);
				}
				else
					throw Utf<>::UnexpectedEndOfInput();

				return beg;
			}
	};




//
//	class Char
//	{
//		private:
//
//			UInt32 _code;
//
//		public:
//
//
//	};
//
//	Bool const is_lower(Char);
//	Char const to_lower(Char);
//
//	Bool const is_upper(Char);
//	Char const to_upper(Char);
//
//
//	#include "size.hpp"
//	#include "void.hpp"
//	#include "bool.hpp"
//	#include "int.hpp"
//	#include "flt.hpp"
//
//
//	class String
//	{
//		public:
//
//			String();
//			String(String const& that);
//			String(String&& that);
//			String& operator=(String const& that);
//			String& operator=(String&& that);
//			~String();
//
//			String(char const* ptr);
//			String(Char c);
//
//			explicit String(IntShort);
//			explicit String(UIntShort);
//			explicit String(Int);
//			explicit String(UInt);
//			explicit String(IntLong);
//			explicit String(UIntLong);
//			explicit String(IntHuge);
//			explicit String(UIntHuge);
//			explicit String(Flt);
//			explicit String(FltLong);
//			explicit String(FltHuge);
//
//			explicit operator IntShort() const;
//			explicit operator UIntShort() const;
//			explicit operator Int() const;
//			explicit operator UInt() const;
//			explicit operator IntLong() const;
//			explicit operator UIntLong() const;
//			explicit operator IntHuge() const;
//			explicit operator UIntHuge() const;
//			explicit operator Flt() const;
//			explicit operator FltLong() const;
//			explicit operator FltHuge() const;
//
//			String& operator+=(String const& that);
//			String& operator+=(char const* that);
//
//	};
//
//	Void swap(String* a, String* b);
//
//	String& operator+(String const& l, char const* r);
//	String& operator+(char const* l, String const& r);
//
//	Size length(String const& str);
//	Size length(char const* str);
//
//	Size search(String const& str, String const& sub, Size pos = 0);
//	Size search(String const& str, char const* sub, Size pos = 0);
//	Size search(char const* str, String const& sub, Size pos = 0);
//	Size search(char const* str, char const* sub, Size pos = 0);
//
//	String remove(String const& str, Size pos = 0, Size size = ~Size(0));
//	String remove(char const* str, Size pos = 0, Size size = ~Size(0));
//
//	String insert(String const& str, String const& sub, Size pos);
//	String insert(String const& str, char const* sub, Size pos);
//	String insert(char const* str, String const& sub, Size pos);
//	String insert(char const* str, char const* sub, Size pos);
//
//	String subseq(String const& str, Size pos = 0, Size size = ~Size(0));
//	String subseq(char const* str, Size pos = 0, Size size = ~Size(0));
//
//
//	Char at(String const& str, Size pos);
//	Char at(char const* str, Size pos);
//
//	String at(String const& str, Size pos, Char c);
//	String at(char const* str, Size pos, Char c);
//
//	Bool is_lower(String const&);
//	Bool is_lower(char const*);
//	String to_lower(String const&);
//	String to_lower(char const*);
//
//	Bool is_upper(String const&);
//	Bool is_upper(char const*);
//	String to_upper(String const&);
//	String to_upper(char const*);
//
//	Bool is_title(String const&);
//	Bool is_title(char const*);
//	String to_title(String const&);
//	String to_title(char const*);

#endif //STRING_HPP;
