#include "../hdr/sleep.hpp"

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	// windows

	#include <windows.h>

	Void sleep(Flt64 seconds)
	{
		::Sleep((DWORD)(seconds*1000));
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

	#include <time.h>

	Void sleep(Flt64 seconds)
	{
		timespec ts;
		ts.tv_sec = seconds;
		ts.tv_nsec = (seconds-ts.tv_sec)*1000000000;
		while (::nanosleep(&ts, &ts));
	}

#else

	#error "sleep is not supported on this system"

#endif
