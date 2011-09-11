#ifndef FUNCTION_HPP
	#define FUNCTION_HPP

	#include "type_at.hpp"
	#include "size.hpp"

	template <typename R, typename... A>
	class Function;

	namespace _impl
	{
		namespace _Function
		{
			class _Dispatcher
			{
				public:
					virtual R call(A...) = 0;
					virtual _Dispatcher* const clone() = 0;
					virtual ~_Dispatcher() {}
			};

			template <typename Ret, typename... Arg>
			class _DispatcherFuncPtr : public _Dispatcher
			{
				private:

					Ret (*_f)(Arg...);

				public:

					_DispatcherFuncPtr(Ret (*f)(Arg...))
						:	_f(f)
					{

					}

					virtual R call(A... a)
					{
						return (*_f)(a...);
					}
					virtual _Dispatcher* const clone()
					{
						return new _DispatcherFuncPtr(_f);
					}
					virtual ~_DispatcherFuncPtr() {}
			};

			template <typename Obj, typename Ret, typename... Arg>
			class _DispatcherMetPtr : public _Dispatcher
			{
				private:

					Obj* _o;
					Ret (Obj::*_f)(Arg...);

				public:

					_DispatcherMetPtr(Obj* o, Ret (Obj::*f)(Arg...))
						:	_o(o)
						,	_f(f)
					{

					}

					virtual R call(A... a)
					{
						return (_o->*_f)(a...);
					}
					virtual _Dispatcher* const clone()
					{
						return new _DispatcherMetPtr(_o, _f);
					}
					virtual ~_DispatcherMetPtr() {}
			};

			template <typename Obj>
			class _DispatcherObject : public _Dispatcher
			{
				private:

					Obj _o;

				public:

					_DispatcherObject(Obj o)
						:	_o(o)
					{

					}

					virtual R call(A... a)
					{
						return _o(a...);
					}
					virtual _Dispatcher* const clone()
					{
						return new _DispatcherObject(_o);
					}
					virtual ~_DispatcherObject() {}
			};

		}
	}





	template <typename R, typename... A>
	class Function<R (A...)>
	{
		public:

				//argument count
			static Size const arity = sizeof...(A);

				//return type
			struct Return
			{
				typedef R Type;
			};

				//argument n type
			template <Size const n>
			struct Argument
			{
				typedef typename TypeAt<n, A...>::Type Type;
			};

		private:




			_Dispatcher* _dispatcher;



		public:

			Function()
				:	_dispatcher(0)
			{

			}

			Function(Function const& that)
				:	_dispatcher(that._dispatcher ? that._dispatcher->clone() : 0)
			{

			}

			Function& operator=(Function const& that)
			{
				if (this != &that)
				{
					delete this->_dispatcher;
					this->_dispatcher = that._dispatcher ? that._dispatcher->clone() : 0;
				}
				return *this;
			}

			template <typename Ret, typename... Arg>
			Function(Ret (*f)(Arg...))
				:	_dispatcher(new _DispatcherFuncPtr<Ret, Arg...>(f))
			{

			}

			template <typename Obj, typename Ret, typename... Arg>
			Function(Obj* o, Ret (Obj::*f)(Arg...))
				:	_dispatcher(new _DispatcherMetPtr<Obj, Ret, Arg...>(o, f))
			{

			}

			template <typename Obj>
			Function(Obj o)
				:	_dispatcher(new _DispatcherObject<Obj>(o))
			{

			}

			~Function()
			{
				delete _dispatcher;
			}


			R operator()(A... a)
			{
				return _dispatcher->call(a...);
			}

			operator bool const() const
			{
				return _dispatcher;
			}
	};


#endif //FUNCTION_HPP
