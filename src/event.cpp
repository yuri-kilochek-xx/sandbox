//#include "../hdr/event.hpp"
//
//#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
//	// windows
//
//	#include <windows.h>
//
//	class Event::_Impl
//	{
//		public:
//			::CRITICAL_SECTION critical_section;
//			::HANDLE event;
//			unsigned count;
//	};
//
//	Event::Event()
//		: _impl(new _Impl)
//	{
//		::InitializeCriticalSection(&_impl->critical_section);
//		_impl->event = ::CreateEvent(NULL, TRUE, FALSE, NULL);
//		_impl->count = 0;
//	}
//
//	Event::~Event()
//	{
//		::DeleteCriticalSection(&_impl->critical_section);
//		::CloseHandle(_impl->event);
//		delete _impl;
//	}
//
//	Void Event::wait()
//	{
//		::EnterCriticalSection(&_impl->critical_section);
//		++_impl->count;
//		::LeaveCriticalSection(&_impl->critical_section);
//		::WaitForSingleObject(_impl->event, INFINITE);
//		::EnterCriticalSection(&_impl->critical_section);
//		if (--_impl->count == 0)
//			::ResetEvent(_impl->event);
//		::LeaveCriticalSection(&_impl->critical_section);
//	}
//
//	Bool const Event::wait(long double const seconds)
//	{
//			//negative or zero time expires immediately
//		if (seconds <= 0.0l)
//			return false;
//
//		return ::SleepConditionVariableCS(&_impl->condition_variable, *(::CRITICAL_SECTION**)&mutex, seconds*1000);
//	}
//
//
//	Void Event::signal()
//	{
//		::EnterCriticalSection(&_impl->critical_section);
//		::SetEvent(_impl->event);
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
//	#include <time.h>
//
//	class Event::_Impl
//	{
//		public:
//			::pthread_cond_t cond;
//	};
//
//	Event::Event()
//		: _impl(new _Impl)
//	{
//		::pthread_cond_init(&_impl->cond, 0);
//	}
//
//	Event::~Event()
//	{
//		::pthread_cond_destroy(&_impl->cond);
//		delete _impl;
//	}
//
//	Void Event::wait(Mutex& mutex)
//	{
//		::pthread_cond_wait(&_impl->cond, *(::pthread_mutex_t**)&mutex);
//	}
//
//	Bool const Event::wait(Mutex& mutex, long double const seconds)
//	{
//			//negative or zero time expires immediately
//		if (seconds <= 0.0l)
//			return false;
//
//		::timespec ts;
//		::clock_gettime(CLOCK_REALTIME, &ts);
//		long double target = ts.tv_sec + ts.tv_nsec/1000000000.0l + seconds;
//		ts.tv_sec = target;
//		ts.tv_nsec = (target-ts.tv_sec)*1000000000.0l;
//
//		return ::pthread_cond_timedwait(&_impl->cond, *(::pthread_mutex_t**)&mutex, &ts) != ETIMEDOUT;
//	}
//
//	Void Event::signal()
//	{
//		::pthread_cond_broadcast(&_impl->cond);
//	}
//
//
//#else
//
//	#error "event is not supported on this system"
//
//#endif
