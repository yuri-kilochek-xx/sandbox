#ifndef VARIANT_HPP
	#define VARIANT_HPP

	#include "void.hpp"
	#include "none.hpp"
	#include "cast.hpp"
	#include "alignment_of.hpp"

	template <typename...>
	class Variant;

	/////////////////////////////////////////////


	namespace _impl
	{
		namespace _Variant
		{
			template <typename>
			inline Void const* id_of()
			{
				static char const dummy = 0;
				return &dummy;
			}


			template <typename...>
			class Holder;

			template <>
			class Holder<>
			{
				public:

					virtual Void const* id() = 0;


					virtual Void* ptr() = 0;

			};

			template <typename T>
			class Holder
			{

			};
		}
	}

	template <typename... Types>
	class Variant
	{


	};


#endif //VARIANT_HPP
