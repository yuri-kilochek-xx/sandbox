#ifndef REVERSE_HPP
	#define REVERSE_HPP

	#include "iterator.hpp"

	template <typename Sequence>
	class Reverse;

	template <typename Sequence>
	class Iterator<Reverse<Sequence>>
	{
		friend class Reverse<Sequence>;
		friend class Iterator<const Reverse<Sequence>>;
		private:

			Iterator<Sequence> _orig;

			Iterator(Iterator<Sequence> const& that)
				: _orig(that)
			{

			}

		public:

			typedef typename Iterator<Sequence>::Type Type;

			Iterator()
				: _orig()
			{

			}
			Iterator(Iterator const& that)
				: _orig(that._orig)
			{

			}
			Iterator& operator=(Iterator const& that)
			{
				this->_orig = that._orig;
				return *this;
			}
			~Iterator()
			{

			}

			Type& operator*() const
			{
				return _orig.operator*();
			}
			Type* operator->() const
			{
				return _orig.operator->();
			}

			Iterator& operator++()
			{
				--_orig;
				return *this;
			}
			Iterator operator++(int)
			{
				Iterator temp(*this);
				++(*this);
				return temp;
			}


			Iterator& operator--()
			{
				++_orig;
				return *this;
			}
			Iterator operator--(int)
			{
				Iterator temp(*this);
				--(*this);
				return temp;
			}

			Bool operator==(Iterator const& that) const
			{
				return this->_orig == that._orig;
			}
			Bool operator==(Iterator<const Reverse<Sequence>> const& that) const
			{
				return this->_orig == that._orig;
			}

			Bool operator!=(Iterator const& that) const
			{
				return this->_orig != that._orig;
			}
			Bool operator!=(Iterator<const Reverse<Sequence>> const& that) const
			{
				return this->_orig != that._orig;
			}
	};

	template <typename Sequence>
	class Iterator<const Reverse<Sequence>>
	{
		friend class Reverse<Sequence>;
		friend class Iterator<Reverse<Sequence>>;
		private:

			Iterator<Sequence> _orig;

			Iterator(Iterator<Sequence> const& that)
				: _orig(that)
			{

			}

		public:

			typedef typename Iterator<Sequence>::Type const Type;

			Iterator()
				: _orig()
			{

			}
			Iterator(Iterator const& that)
				: _orig(that._orig)
			{

			}
			Iterator& operator=(Iterator const& that)
			{
				this->_orig = that._orig;
				return *this;
			}
			~Iterator()
			{

			}

			Iterator(Iterator<Reverse<Sequence>> const& that)
				: _orig(that._orig)
			{

			}


			Type& operator*() const
			{
				return _orig.operator*();
			}
			Type* operator->() const
			{
				return _orig.operator->();
			}

			Iterator& operator++()
			{
				--_orig;
				return *this;
			}
			Iterator operator++(int)
			{
				Iterator temp(*this);
				++(*this);
				return temp;
			}


			Iterator& operator--()
			{
				++_orig;
				return *this;
			}
			Iterator operator--(int)
			{
				Iterator temp(*this);
				--(*this);
				return temp;
			}

			Bool operator==(Iterator const& that) const
			{
				return this->_orig == that._orig;
			}
			Bool operator==(Iterator<Reverse<Sequence>> const& that) const
			{
				return this->_orig == that._orig;
			}

			Bool operator!=(Iterator const& that) const
			{
				return this->_orig != that._orig;
			}
			Bool operator!=(Iterator<Reverse<Sequence>> const& that) const
			{
				return this->_orig != that._orig;
			}

	};


	template <typename Sequence>
	Reverse<Sequence> reverse(Sequence&&);

	template <typename Sequence>
	class Reverse
	{
		friend Reverse<Sequence> reverse<Sequence>(Sequence&&);
		private:

			Sequence& _sequence;

			Reverse(Sequence& sequence)
				: _sequence(sequence)
			{

			}

			Reverse(Reverse const& that)
				: _sequence(that._sequence)
			{

			}

		public:

			Iterator<Reverse> front()
			{
				return Iterator<Reverse>(_sequence.end());
			}
			Iterator<Reverse> begin()
			{
				return Iterator<Reverse>(_sequence.last());
			}
			Iterator<Reverse> last()
			{
				return Iterator<Reverse>(_sequence.begin());
			}
			Iterator<Reverse> end()
			{
				return Iterator<Reverse>(_sequence.front());
			}

			Iterator<const Reverse> front() const
			{
				return Iterator<const Reverse>(_sequence.end());
			}
			Iterator<const Reverse> begin() const
			{
				return Iterator<const Reverse>(_sequence.last());
			}
			Iterator<const Reverse> last() const
			{
				return Iterator<const Reverse>(_sequence.begin());
			}
			Iterator<const Reverse> end() const
			{
				return Iterator<const Reverse>(_sequence.front());
			}

	};

	template <typename Sequence>
	inline Reverse<Sequence> reverse(Sequence&& sequence)
	{
		return Reverse<Sequence>(sequence);
	}

#endif //REVERSE_HPP
