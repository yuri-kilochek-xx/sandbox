#ifndef MUTEX_HPP
	#define MUTEX_HPP

	#include "void.hpp"
	#include "bool.hpp"
	#include "flt_n.hpp"


	/**
		\brief A simple mutual exclusion, used for thread synchronization.
	 */
	class Mutex
	{
		private:

			class _Impl;
			_Impl* _impl;

		public:

			Mutex();
			Mutex(Mutex const&) = delete;
			Mutex& operator=(Mutex const&) = delete;
			~Mutex();

			/**
				\brief Acquires lock on mutex.
				\param timeout Time period specified in seconds, for which the calling thread can wait to acquire this mutex.
					If this value is negative this false will be returned immediately, without trying to obtain the lock, otherwise,
					if this value zero lock will we obtained only if it is not already owned by another thread, otherwise,
					if this value if finite it will wait at when the specified time expires or the mutex becomes free, whichever comes first, otherwise,
					if this value is infinite, it will wait for the mutex to become free.
				\return Returns true if the mutex was successfully locked, otherwise returns false.
			 */
			Bool const acquire(Flt64 timeout = inf);

			/**
				\brief Releases lock on mutex.
				Resumes one of the threads that is waiting to lock the mutex, and allows it to lock it.
			 */
			Void release();
	};

#endif //MUTEX_HPP
