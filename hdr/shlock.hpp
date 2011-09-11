#ifndef SHLOCK_HPP
	#define SHLOCK_HPP

	#include "void.hpp"
	#include "bool.hpp"
	#include "flt.hpp"

	/**
		\brief A simple mutual exclusion, used for thread synchronization.
	 */
	class Shlock
	{
		private:

			class _Impl;
			_Impl* _impl;

		public:

			Shlock();
			Shlock(Shlock const&) = delete;
			Shlock& operator=(Shlock const&) = delete;
			~Shlock();


			/**
				\brief Locks mutex if it is not already locked.
				\return Returns true if the mutex was successfully locked, otherwise returns false.
			 */
			Bool const lock_shared(Flt64 seconds = (1.0/0.0));

			/**
				\brief Locks mutex if it is not already locked.
				\return Returns true if the mutex was successfully locked, otherwise returns false.
			 */
			Bool const lock_exclusive(Flt64 seconds = (1.0/0.0));

			/**
				\brief Unlocks mutex.
				Resumes one of the threads that is waiting to lock the mutex, and allows it to lock it.
			 */
			Void unlock();
	};

#endif //SHLOCK_HPP
