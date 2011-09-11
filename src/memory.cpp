#include "../hdr/memory.hpp"

#include <stdlib.h>

Byte* const Memory<>::grab(Size size)
{
	return (Byte*)::malloc(size);
}

Void Memory<>::free(Byte* ptr)
{
	::free(ptr);
}
