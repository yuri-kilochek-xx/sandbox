#ifndef FILTER_HPP
	#define FILTER_HPP

	#include "iterator.hpp"
	#include "cast.hpp"
	#include "del_ref.hpp"

	template <typename Sequence, typename Pred>
	class Filter;


	template <typename Sequence, typename Pred>
	class Iterator<Filter<Sequence, Pred>>
	{
		friend class Filter<Sequence, Pred>;
		friend class Iterator<const Filter<Sequence, Pred>>;
		private:

			Iterator<Sequence> _orig;
			Pred _pred;

			Iterator(Iterator<Sequence> const& orig, Pred pred)
				: _orig(orig)
				, _pred(pred)
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
				, _pred(that._pred)
			{

			}
			Iterator& operator=(Iterator const& that)
			{
				this->_orig = that._orig;
				this->_pred = that._pred;
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
				do
					++_orig;
				while (!_pred(*_orig));
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
				do
					--_orig;
				while (!_pred(*_orig));
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
			Bool operator==(Iterator<const Filter<Sequence, Pred>> const& that) const
			{
				return this->_orig == that._orig;
			}

			Bool operator!=(Iterator const& that) const
			{
				return this->_orig != that._orig;
			}
			Bool operator!=(Iterator<const Filter<Sequence, Pred>> const& that) const
			{
				return this->_orig != that._orig;
			}
	};

	template <typename Sequence, typename Pred>
	class Iterator<const Filter<Sequence, Pred>>
	{
		friend class Filter<Sequence, Pred>;
		friend class Iterator<Filter<Sequence, Pred>>;
		private:

			Iterator<Sequence> _orig;
			Pred _pred;

			Iterator(Iterator<Sequence> const& that, Pred pred)
				: _orig(that)
				, _pred(pred)
			{

			}

		public:

			typedef typename Iterator<Sequence>::Type const Type;

			Iterator()
				: _orig()
				, _pred()
			{

			}
			Iterator(Iterator const& that)
				: _orig(that._orig)
				, _pred(that._pred)
			{

			}
			Iterator& operator=(Iterator const& that)
			{
				this->_orig = that._orig;
				this->_pred = that._pred;
				return *this;
			}
			~Iterator()
			{

			}

			Iterator(Iterator<Filter<Sequence, Pred>> const& that)
				: _orig(that._orig)
				, _pred(that._pred)
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
				do
					++_orig;
				while(!_pred(*_orig));
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
				do
					--_orig;
				while(!_pred(*_orig));
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
			Bool operator==(Iterator<Filter<Sequence, Pred>> const& that) const
			{
				return this->_orig == that._orig;
			}

			Bool operator!=(Iterator const& that) const
			{
				return this->_orig != that._orig;
			}
			Bool operator!=(Iterator<Filter<Sequence, Pred>> const& that) const
			{
				return this->_orig != that._orig;
			}

	};


	template <typename Sequence, typename Pred>
	Filter<typename DelRef<Sequence>::Type, Pred> filter(Sequence&&, Pred);

	template <typename Sequence, typename Pred>
	class Filter
	{
		friend Filter<Sequence, Pred> filter<Sequence, Pred>(Sequence&&, Pred);
		//private:
		public:

			Sequence& _sequence;
			Pred _pred;

			Filter(Sequence& sequence, Pred pred)
				: _sequence(sequence)
				, _pred(pred)
			{

			}

			Filter(Filter const& that)
				: _sequence(that._sequence)
				, _pred(that._pred)
			{

			}

		public:

			Iterator<Filter> front()
			{
				return Iterator<Filter>(_sequence.front(), _pred);
			}
			Iterator<Filter> begin()
			{
				return Iterator<Filter>(_sequence.begin(), _pred);
			}
			Iterator<Filter> last()
			{
				return Iterator<Filter>(_sequence.last(), _pred);
			}
			Iterator<Filter> end()
			{
				return Iterator<Filter>(_sequence.end(), _pred);
			}

			Iterator<const Filter> front() const
			{
				return Iterator<const Filter>(_sequence.front(), _pred);
			}
			Iterator<const Filter> begin() const
			{
				return Iterator<const Filter>(_sequence.begin(), _pred);
			}
			Iterator<const Filter> last() const
			{
				return Iterator<const Filter>(_sequence.last(), _pred);
			}
			Iterator<const Filter> end() const
			{
				return Iterator<const Filter>(_sequence.end(), _pred);
			}

	};


	template <typename Sequence, typename Pred>
	inline Filter<typename DelRef<Sequence>::Type, Pred> filter(Sequence&& sequence, Pred pred)
	{
		return Filter<typename DelRef<Sequence>::Type, Pred>(sequence, pred);
	}

#endif //FILTER_HPP
