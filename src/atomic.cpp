#include "../hdr/atomic.hpp"

#ifdef __GNUC__
	//gcc

	Int32 Atomic<Int32>::get() const
	{
		return __sync_fetch_and_add(&_data, 0);
	}

	Int32 Atomic<Int32>::set(Int32 val)
	{
		return __sync_lock_test_and_set(&_data, val);
	}

	Int32 Atomic<Int32>::cas(Int32 val, Int32 cmp)
	{
		return __sync_val_compare_and_swap(&_data, cmp, val);
	}

	Int32 Atomic<Int32>::get_inc()
	{
		return __sync_fetch_and_add(&_data, 1);
	}

	Int32 Atomic<Int32>::get_dec()
	{
		return __sync_fetch_and_sub(&_data, 1);
	}

	Int32 Atomic<Int32>::get_add(Int32 val)
	{
		return __sync_fetch_and_add(&_data, val);
	}

	Int32 Atomic<Int32>::get_sub(Int32 val)
	{
		return __sync_fetch_and_sub(&_data, val);
	}

	Int32 Atomic<Int32>::inc_get()
	{
		return __sync_add_and_fetch(&_data, 1);
	}

	Int32 Atomic<Int32>::dec_get()
	{
		return __sync_sub_and_fetch(&_data, 1);
	}

	Int32 Atomic<Int32>::add_get(Int32 val)
	{
		return __sync_add_and_fetch(&_data, val);
	}

	Int32 Atomic<Int32>::sub_get(Int32 val)
	{
		return __sync_sub_and_fetch(&_data, val);
	}


	UInt32 Atomic<UInt32>::get() const
	{
		return __sync_fetch_and_add(&_data, 0);
	}

	UInt32 Atomic<UInt32>::set(UInt32 val)
	{
		return __sync_lock_test_and_set(&_data, val);
	}

	UInt32 Atomic<UInt32>::cas(UInt32 val, UInt32 cmp)
	{
		return __sync_val_compare_and_swap(&_data, cmp, val);
	}

	UInt32 Atomic<UInt32>::get_inc()
	{
		return __sync_fetch_and_add(&_data, 1);
	}

	UInt32 Atomic<UInt32>::get_dec()
	{
		return __sync_fetch_and_sub(&_data, 1);
	}

	UInt32 Atomic<UInt32>::get_add(UInt32 val)
	{
		return __sync_fetch_and_add(&_data, val);
	}

	UInt32 Atomic<UInt32>::get_sub(UInt32 val)
	{
		return __sync_fetch_and_sub(&_data, val);
	}

	UInt32 Atomic<UInt32>::inc_get()
	{
		return __sync_add_and_fetch(&_data, 1);
	}

	UInt32 Atomic<UInt32>::dec_get()
	{
		return __sync_sub_and_fetch(&_data, 1);
	}

	UInt32 Atomic<UInt32>::add_get(UInt32 val)
	{
		return __sync_add_and_fetch(&_data, val);
	}

	UInt32 Atomic<UInt32>::sub_get(UInt32 val)
	{
		return __sync_sub_and_fetch(&_data, val);
	}



	Int64 Atomic<Int64>::get() const
	{
		return __sync_fetch_and_add(&_data, 0);
	}

	Int64 Atomic<Int64>::set(Int64 val)
	{
		return __sync_lock_test_and_set(&_data, val);
	}

	Int64 Atomic<Int64>::cas(Int64 val, Int64 cmp)
	{
		return __sync_val_compare_and_swap(&_data, cmp, val);
	}

	Int64 Atomic<Int64>::get_inc()
	{
		return __sync_fetch_and_add(&_data, 1);
	}

	Int64 Atomic<Int64>::get_dec()
	{
		return __sync_fetch_and_sub(&_data, 1);
	}

	Int64 Atomic<Int64>::get_add(Int64 val)
	{
		return __sync_fetch_and_add(&_data, val);
	}

	Int64 Atomic<Int64>::get_sub(Int64 val)
	{
		return __sync_fetch_and_sub(&_data, val);
	}

	Int64 Atomic<Int64>::inc_get()
	{
		return __sync_add_and_fetch(&_data, 1);
	}

	Int64 Atomic<Int64>::dec_get()
	{
		return __sync_sub_and_fetch(&_data, 1);
	}

	Int64 Atomic<Int64>::add_get(Int64 val)
	{
		return __sync_add_and_fetch(&_data, val);
	}

	Int64 Atomic<Int64>::sub_get(Int64 val)
	{
		return __sync_sub_and_fetch(&_data, val);
	}


	UInt64 Atomic<UInt64>::get() const
	{
		return __sync_fetch_and_add(&_data, 0);
	}

	UInt64 Atomic<UInt64>::set(UInt64 val)
	{
		return __sync_lock_test_and_set(&_data, val);
	}

	UInt64 Atomic<UInt64>::cas(UInt64 val, UInt64 cmp)
	{
		return __sync_val_compare_and_swap(&_data, cmp, val);
	}

	UInt64 Atomic<UInt64>::get_inc()
	{
		return __sync_fetch_and_add(&_data, 1);
	}

	UInt64 Atomic<UInt64>::get_dec()
	{
		return __sync_fetch_and_sub(&_data, 1);
	}

	UInt64 Atomic<UInt64>::get_add(UInt64 val)
	{
		return __sync_fetch_and_add(&_data, val);
	}

	UInt64 Atomic<UInt64>::get_sub(UInt64 val)
	{
		return __sync_fetch_and_sub(&_data, val);
	}

	UInt64 Atomic<UInt64>::inc_get()
	{
		return __sync_add_and_fetch(&_data, 1);
	}

	UInt64 Atomic<UInt64>::dec_get()
	{
		return __sync_sub_and_fetch(&_data, 1);
	}

	UInt64 Atomic<UInt64>::add_get(UInt64 val)
	{
		return __sync_add_and_fetch(&_data, val);
	}

	UInt64 Atomic<UInt64>::sub_get(UInt64 val)
	{
		return __sync_sub_and_fetch(&_data, val);
	}

#else

	#error "atomic not implemented on this platform"

#endif
