#include "../hdr/timer.hpp"

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	// windows

	#include <windows.h>

	Flt64 const timer()
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		return Flt64(time.QuadPart)/Flt64(freq.QuadPart);
	}

#elif defined(linux) || defined(__linux)\
   || defined(__minix)\
   || defined(__FreeBSD__)\
   || defined(__NetBSD__)\
   || defined(__OpenBSD__)\
   || defined(_AIX) || defined(__TOS_AIX__)\
   || defined(sun) || defined(__sun)\
   || defined(hpux) || defined(_hpux) || defined(__hpux)\
   || defined(__APPLE__) || defined(__MACH__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
	// unix

	#include <sys/time.h>

	Flt64 const timer()
	{
		timeval tv;
		gettimeofday(&tv, 0);
		return tv.tv_sec + Flt64(tv.tv_usec)/1000000;
	}

#else

	#error "timer is not supported on this system"

#endif
