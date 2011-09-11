#ifndef ALIGNMENT_OF_HPP
	#define ALIGNMENT_OF_HPP

	#include "size.hpp"

	template <typename T>
	struct AlignmentOf
	{
		private:
			char c;
			T t;
		public:
			static Size const value = (sizeof(AlignOf) - sizeof(T));
	};

#endif //ALIGNMENT_OF_HPP
