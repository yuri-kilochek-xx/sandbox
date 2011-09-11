#ifndef GRAPHIC_HPP
	#define GRAPHIC_HPP

	#include "void.hpp"
	#include "byte.hpp"
	#include "size.hpp"

	class Canvas
	{
		protected:

			virtual Byte* const lock();
			virtual Void unlock();

		public:

			class Format
			{
				Size rp;
				Size rs;
				Size gp;
				Size gs;
				Size bp;
				Size bs;
			};




	};

#endif //GRAPHIC_HPP
