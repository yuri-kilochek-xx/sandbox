#ifndef STREAM_HPP
	#define STREAM_HPP

	#include "size.hpp"
	#include "bool.hpp"


	/**
		\brief An input stream.
		Represents a simple incoming stream of objects.
		\param T Type of the objects to stream.
	 */
	template <typename T>
	class IStream
	{
		public:

			/**
				\brief Read objects from stream.
				\param ptr Location to read objects to.
				\param size Amount of objects to read.
				\return Amount of objects that were possible to read. If it is greater or equal than size,
					than size objects were actually read to the stream. Otherwise return value
					is the amount of objects actually read.
			 */
			virtual Size const get(T* ptr, Size size) = 0;

			/**
				\brief Read single object from stream.
				\param ptr Location to read object to.
				\return Amount of objects that were possible to read. If it is non-zero,
					than the object was actually read from the stream. Otherwise it wasn't.
			 */
			virtual Size const get(T* ptr) = 0;

			virtual ~IStream()
			{

			}
	};

	/**
		\brief An output stream.
		Represents a simple outgoing stream of objects.
		\param T Type of the objects to stream.
	 */
	template <typename T>
	class OStream
	{
		public:

			/**
				\brief Write objects to stream.
				\param ptr Location to write objects from.
				\param size Amount of objects to write.
				\return Amount of objects that were possible to write. If it is greater or equal than size,
					than size objects were actually written to the stream. Otherwise return value
					is the amount of objects actually written.
			 */
			virtual Size const put(T const* ptr, Size size) = 0;

			/**
				\brief Write single object to stream.
				\param ptr Location to write object from.
				\return Amount of objects that were possible to write. If it is non-zero,
					than the object was actually written to the stream. Otherwise it wasn't.
			 */
			virtual Size const put(T const* ptr) = 0;

			virtual ~OStream()
			{

			}
	};

#endif //STREAM_HPP
