#ifndef ARRAY_HPP
	#define ARRAY_HPP




	namespace _impl
	{
		namespace Array
		{
			template <typename T, Size ts, Size index = 0>
			struct VariadicConstructor
			{
				template <typename... Rest>
				static Void exec(T* t, T&& head, Rest&&... rest)
				{
					t[index] = static_cast<T&&>(head);
					VariadicConstructor<T, ts, index+1>::exec(t, rest...);
				}
				template <typename... Rest>
				static Void exec(T* t, T const& head, Rest&&... rest)
				{
					t[index] = head;
					VariadicConstructor<T, ts, index+1>::exec(t, rest...);
				}
			};
			template <typename T, Size ts>
			struct VariadicConstructor<T, ts, ts>
			{
				template <typename... Rest>
				static Void exec(T* t)
				{

				}
			};
		}
	}




	template <typename, Size = 1>
	class Array;


	template <typename T>
	Void swap(Array<T>&, Array<T>&);



	template <typename T>
	class Array<T, 1>
	{
		friend Void swap<T>(Array<T>&, Array<T>&);

		private:

			Size _size;
			T* _data;

		public:

			class View
			{
				private:

					Array* _array;
					T* _begin;
					T* _end;

				public:



			};


			Array()
				:	_size(0)
				,	_data(0)
			{

			}

			Array(Array const& that)
				: _size(that._size)
				, _data(new T[that._size])
			{
				for (Size i = 0; i < this->_size; ++i)
					this->_data[i] = that._data[i];
			}

			Array(Array&& that)
				: _size(that._size)
				, _data(that._data)
			{
				that._size = 0;
				that._data = 0;;
			}

			Array& operator=(Array that)
			{
				swap(*this, that);
				return *this;
			}

			Array& operator=(Array&& that)
			{
				if (this != &that)
				{
					this->_size = that._size;
					this->_data = that._data;
					that._size = 0;
					that._data = 0;
				}
				return *this;
			}

			virtual ~Array()
			{
				delete [] _data;
			}

			explicit Array(Size const s0)
				: _size(s0)
				, _data(new T[s0])
			{

			}

			explicit Array(Size const s0, T const& item)
				: _size(s0)
				, _data(new T[s0])
			{
				for (Size i = 0; i < _size; ++i)
					_data[i] = item;
			}

			Size const size() const
			{
				return _size;
			}

			Void size(Size const s0)
			{
				Array temp;
				temp._size = s0;
				temp._data = new T[s0];
				Size const min_size = min(temp._size, this->_size);
				for (Size i = 0; i < min_size; ++i)
					temp._data[i] = this->_data[i];
				swap(*this, temp);
			}

			T& operator[](Size const index)
			{
				return _data[index];
			}

			T const& operator[](Size const index) const
			{
				return _data[index];
			}

	};

	template <typename T>
	Void swap(Array<T>& a, Array<T>& b)
	{
		swap(a._size, b._size);
		swap(a._data, b._data);
	}

	template <typename Head, typename... Rest>
	Array<Head> const array(Head&& head, Rest&&... rest)
	{
		return Array<Head, sizeof...(Rest)+1>(static_cast<Head&&>(head), static_cast<Rest&&>(rest)...);
	}



#endif //ARRAY_HPP
