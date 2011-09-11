#ifndef NULL_HPP
	#define NULL_HPP

	/**
	 *	\brief Null type.
	 *
	 *  Represents no type;
	 */
	class Null
	{
		public:

			/**
			 *	\brief Convertion to any type.
			 *
			 *  Converts to default-constructed object of any possible type.
			 *
			 *	\param T Type of object.
			 *
			 * 	\return Default-constructed object of type T;
			 */
			template <class T>
			operator T const() const
			{
				return T();
			}
	};

	/**
	 *	\brief null value.
	 *
	 *  Represents no type value;
	 */
	Null const null = Null();

#endif //NULL_HPP
