#include "../hdr/mutex.hpp"

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	// windows

	#include <windows.h>

	class Mutex::_Impl
	{
		public:
			HANDLE mutex;
	};

	Mutex::Mutex()
		: _impl(new _Impl)
	{
		_impl->mutex = CreateMutex(NULL, FALSE, NULL);
	}

	Mutex::~Mutex()
	{
		CloseHandle(_impl->mutex);
		delete _impl;
	}

	Bool const Mutex::acquire(Flt64 timeout)
	{
		if (timeout < 0)
			return false;

		switch (WaitForSingleObject(_impl->mutex, ((timeout == inf) ? (INFINITE) : ((DWORD)(timeout*1000)))))
		{
			case WAIT_OBJECT_0:
				return true;
			case WAIT_TIMEOUT:
			default:
				return false;
		}
	}

	Void Mutex::release()
	{
		ReleaseMutex(_impl->mutex);
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

	#include <pthread.h>
	#include <time.h>

	class Mutex::_Impl
	{
		public:
			pthread_mutex_t mutex;
	};

	Mutex::Mutex()
		: _impl(new _Impl)
	{
		pthread_mutex_init(&_impl->mutex, 0);
	}

	Mutex::~Mutex()
	{
		pthread_mutex_destroy(&_impl->mutex);
		delete _impl;
	}

	Bool const Mutex::acquire(Flt64 timeout)
	{
		if (timeout < 0)
		{
			return false;
		}
		else if (timeout == 0)
		{
			return pthread_mutex_trylock(&_impl->mutex) == 0;
		}
		else if (timeout == inf)
		{
			return pthread_mutex_lock(&_impl->mutex) == 0;
		}
		else
		{
			timespec ts;
			clock_gettime(CLOCK_REALTIME, &ts);
			Flt64 target = ts.tv_sec + ts.tv_nsec/1000000000.0 + timeout;
			ts.tv_sec = target;
			ts.tv_nsec = (target-ts.tv_sec)*1000000000.0;
			return ::pthread_mutex_timedlock(&_impl->mutex, &ts) == 0;
		}
	}

	Void Mutex::release()
	{
		::pthread_mutex_unlock(&_impl->mutex);
	}

#else

	#error "mutex is not implemented on this system"

#endif
