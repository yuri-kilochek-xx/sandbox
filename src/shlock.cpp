//#include "../hdr/mutex.hpp"
//
//#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
//	// windows
//
//	#include <windows.h>
//
//	class Mutex::_Impl
//	{
//		public:
//			::CRITICAL_SECTION critical_section;
//	};
//
//	Mutex::Mutex()
//		: _impl(new _Impl)
//	{
//		::InitializeCriticalSection(&_impl->critical_section);
//	}
//
//	Mutex::~Mutex()
//	{
//		::DeleteCriticalSection(&_impl->critical_section);
//		delete _impl;
//	}
//
//	Void Mutex::lock()
//	{
//		::EnterCriticalSection(&_impl->critical_section);
//	}
//
//	Bool const Mutex::try_lock()
//	{
//		return ::TryEnterCriticalSection(&_impl->critical_section);
//	}
//
//	Void Mutex::unlock()
//	{
//		::LeaveCriticalSection(&_impl->critical_section);
//	}
//
//#elif defined(linux) || defined(__linux)\
//   || defined(__minix)\
//   || defined(__FreeBSD__)\
//   || defined(__NetBSD__)\
//   || defined(__OpenBSD__)\
//   || defined(_AIX) || defined(__TOS_AIX__)\
//   || defined(sun) || defined(__sun)\
//   || defined(hpux) || defined(_hpux) || defined(__hpux)\
//   || defined(__APPLE__) || defined(__MACH__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
//	// unix
//
//	#include <pthread.h>
//
//	class Mutex::_Impl
//	{
//		public:
//			::pthread_mutex_t mutex;
//	};
//
//	Mutex::Mutex()
//		: _impl(new _Impl)
//	{
//		::pthread_mutex_init(&_impl->mutex, 0);
//	}
//
//	Mutex::~Mutex()
//	{
//		::pthread_mutex_destroy(&_impl->mutex);
//		delete _impl;
//	}
//
//	Void Mutex::lock()
//	{
//		::pthread_mutex_lock(&_impl->mutex);
//	}
//
//	Bool const Mutex::try_lock()
//	{
//		return ::pthread_mutex_trylock(&_impl->mutex);
//	}
//
//	Void Mutex::unlock()
//	{
//		::pthread_mutex_unlock(&_impl->mutex);
//	}
//
//#else
//
//	#error "mutex is not supported on this system"
//
//#endif
