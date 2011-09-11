#ifndef EVENT_HPP
	#define EVENT_HPP

	#include "void.hpp"

	/**
		\brief A simple conditional variable, used for thread synchronization.
	 */
	class Event
	{
		private:

			class _Impl;
			_Impl* _impl;

		public:

			Event();
			Event(Event const&) = delete;
			Event& operator=(Event const&) = delete;
			~Event();

			/**
				\brief Wait on condvar.
				Suspends calling thread until another thread notifies it
			 */
			Void wait();

			/**
				\brief Wait on condvar with timeout.
				Suspends calling thread until another thread notifies it, or until time period specified by timeout elapses,
				whichever comed first.
				\return Returns true if condvar was notified by another thread and false if it timeout seconds elapsed.
			 */
			Bool const wait(long double const timeout);

			/**
				\brief Notify one waiting thread.
				Causes one of the waiting threads to resume its activity.
			 */
			Void signal();
	};

#endif //EVENT_HPP
