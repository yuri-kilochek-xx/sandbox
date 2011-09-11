#ifndef PTR_HPP
	#define PTR_HPP

	#include "size.hpp"
	#include "void.hpp"
	#include "swap.hpp"
	#include "cast.hpp"
	#include "atomic.hpp"
	#include "memory.hpp"


//	SmartPtr
//		StrongPtr
//		FeeblePtr
//		UniquePtr

	namespace _impl
	{
		namespace _SmartPtr
		{
			struct Item
			{
				Void* data;
				Atomic<Size> strong_refc;
				Atomic<Size> feeble_refc;
			};
		}
	}

	template <typename T, typename Allocator = Heap>
	class StrongPtr;
	template <typename T, typename Allocator = Heap>
	class FeeblePtr;



	template <typename T, typename Allocator>
	Void swap(StrongPtr<T, Allocator>*, StrongPtr<T, Allocator>*);
	template <typename T, typename U, typename Allocator>
	StrongPtr<T, Allocator> cast_static(StrongPtr<U, Allocator>&&);
	template <typename T, typename U, typename Allocator>
	StrongPtr<T, Allocator> cast_dynamic(StrongPtr<U, Allocator>&&);
	template <typename T, typename U, typename Allocator>
	StrongPtr<T, Allocator> cast_const(StrongPtr<U, Allocator>&&);


	template <typename T, typename Allocator>
	Void swap(FeeblePtr<T, Allocator>*, FeeblePtr<T, Allocator>*);


	template <typename T, typename Allocator>
	class StrongPtr
	{
		template <typename, typename>
		friend class StrongPtr;
		template <typename, typename>
		friend class FeeblePtr;

		friend Void swap<>(StrongPtr<T, Allocator>*, StrongPtr<T, Allocator>*);
		template <typename U>
		friend StrongPtr<T, Allocator> cast_static(StrongPtr<U, Allocator>&&);
		template <typename U>
		friend StrongPtr<T, Allocator> cast_dynamic(StrongPtr<U, Allocator>&&);
		template <typename U>
		friend StrongPtr<T, Allocator> cast_const(StrongPtr<U, Allocator>&&);

		private:

			_impl::_SmartPtr::Item* _item;

			StrongPtr(_impl::StrongPtr::Item* const item)
				:	_item(item)
			{

			}

		public:

			template <typename... Args>
			static StrongPtr const create(Args&&... args)
			{
				StrongPtr ptr(new _impl::StrongPtr::Item);
				ptr._item->refc = 1;
				ptr._item->data = (Void*)new T(static_cast<Args&&>(args)...);
				return ptr;
			}

			StrongPtr()
				:	_item(new _impl::_SmartPtr::Item)
			{
				_item->data = 0;
				_item->strong_refc.set(1);
			}

			StrongPtr(StrongPtr const& that)
				:	_item(that._item)
			{
				this->_item->strong_refc.inc_get();
			}

			template <typename U>
			StrongPtr(StrongPtr<U> const& that)
				:	_item(that._item)
			{
				static U* const u(0);
				static T* const t(u);

				this->_item->strong_refc.inc_get();
			}

			StrongPtr& operator=(StrongPtr const& that)
			{
				if (this != &that)
				{
					if (this->_item->strong_refc.dec_get() == 0)
					{
						delete (T*)this->_item->data;
						if (this->_item->feeble_refc.dec_get() == 0)
						{
							delete this->_item;
						}
					}
					this->_item = that._item;
					this->_item->strong_refc.inc_get();
				}
				return* this;
			}

			template <typename U>
			StrongPtr& operator=(StrongPtr<U> const& that)
			{
				static U* const u = 0;
				static T* const t = u;

				if (this != &that)
				{
					if (this->_item->strong_refc.dec_get() == 0)
					{
						delete (T*)this->_item->data;
						if (this->_item->feeble_refc.get() == 0)
						{
							delete this->_item;
						}
					}
					this->_item = that._item;
					this->_item->strong_refc.inc_get();
				}
				return* this;
			}




			StrongPtr(StrongPtr&& that)
				:	_item(that._item)
			{
				that._item = new _impl::StrongPtr::Item;
				that._item->data = 0;
				that._item->refc = 1;
			}

			template <typename U>
			StrongPtr(StrongPtr<U>&& that)
				:	_item(that._item)
			{
				static U* const u(0);
				static T* const t(u);

				that._item = new _impl::StrongPtr::Item;
				that._item->data = 0;
				that._item->refc = 1;
			}

			StrongPtr& operator=(StrongPtr&& that)
			{
				if (this != &that)
				{
					if (--this->_item->refc == 0)
					{
						delete (T*)this->_item->data;
						delete this->_item;
					}

					this->_item = that._item;

					that._item = new _impl::StrongPtr::Item;
					that._item->data = 0;
					that._item->refc = 1;
				}
				return* this;
			}

			template <typename U>
			StrongPtr& operator=(StrongPtr<U>&& that)
			{
				static U* const u = 0;
				static T* const t = u;

				if (this != &that)
				{
					if (--this->_item->refc == 0)
					{
						delete (T*)this->_item->data;
						delete this->_item;
					}

					this->_item = that._item;

					that._item = new _impl::StrongPtr::Item;
					that._item->data = 0;
					that._item->refc = 1;
				}
				return* this;
			}

			~StrongPtr()
			{
				if (this->_item->strong_refc.dec_get() == 0)
				{
					delete (T*)this->_item->data;
					if (this->_item->feeble_refc.get() == 0)
					{
						delete this->_item;
					}
				}
			}

			T* const operator->() const
			{
				return (T*)_item->data;
			}

			T& operator*() const
			{
				return *(T*)_item->data;
			}

			operator T* const() const
			{
				return (T*)_item->data;
			}

			template <typename U>
			StrongPtr<U> const try_cast() const
			{
				if (dynamic_cast<U*>((T*)_item->data))
				{
					++_item->refc;
					return StrongPtr<U>(_item);
				}
				else
				{
					return StrongPtr<U>();
				}
			}

	};

	template <typename T>
	inline Void swap(StrongPtr<T>& a, StrongPtr<T>& b)
	{
		swap(a._item, b._item);
	}

#endif //PTR_HPP
