#ifndef LIST_HPP
	#define LIST_HPP

	#include "none.hpp"
	#include "void.hpp"
	#include "iterator.hpp"
	#include "sequence.hpp"

	template <typename Elem>
	class List;

	template <typename Elem>
	Void swap(List<Elem>*, List<Elem>*);

	template <typename Elem>
	Iterator<List<Elem>> head(List<Elem>&);
	template <typename Elem>
	Iterator<List<Elem>> first(List<Elem>&);
	template <typename Elem>
	Iterator<List<Elem>> last(List<Elem>&);
	template <typename Elem>
	Iterator<List<Elem>> tail(List<Elem>&);

	template <typename Elem>
	Iterator<List<Elem> const> head(List<Elem> const&);
	template <typename Elem>
	Iterator<List<Elem> const> first(List<Elem> const&);
	template <typename Elem>
	Iterator<List<Elem> const> last(List<Elem> const&);
	template <typename Elem>
	Iterator<List<Elem> const> tail(List<Elem> const&);

	template <typename Elem>
	class List
	{
		friend Void swap<Elem>(List<Elem>*, List<Elem>*);

		friend Iterator<List<Elem>> head<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> first<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> last<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> tail<Elem>(List<Elem>&);

		friend Iterator<List<Elem> const> head<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> first<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> last<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> tail<Elem>(List<Elem> const&);

		private:

			struct _Node
			{
				_Node* next;
				_Node* prev;
				Elem data;
			};

			_Node* _begin;
			_Node* _last;

		public:

			List();
			List(List const& that);
			List(List&& that);
			List& operator=(List const& that);
			List& operator=(List&& that);
			~List();

			template <typename Seq>
			List(Seq const& that, typename If<IsSequenceForward<Seq>, None>::Type = none);
			template <typename Seq>
			List(Seq&& that, typename If<IsSequenceForward<Seq>, None>::Type = none);

			template <typename Seq>
			typename If<IsSequenceForward<Seq>, List&>::Type operator=(Seq const& that);
			template <typename Seq>
			typename If<IsSequenceForward<Seq>, List&>::Type operator=(Seq&& that);

				//range based for support
			Iterator<List<Elem>> begin();
			Iterator<List<Elem>> end();

			Iterator<List<Elem> const> begin() const;
			Iterator<List<Elem> const> end() const;
	};

	template <typename Elem>
	struct IsSequenceForward<List<Elem>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsSequenceForward<List<Elem> const>
	{
		static Bool const value = true;
	};

	template <typename Elem>
	struct IsSequenceBidirectional<List<Elem>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsSequenceBidirectional<List<Elem> const>
	{
		static Bool const value = true;
	};



	template <typename Elem>
	class Iterator<List<Elem>>;

	template <typename Elem>
	Void swap(Iterator<List<Elem>>*, Iterator<List<Elem>>*);

	template <typename Elem>
	class Iterator<List<Elem>>
	{
		friend class List<Elem>;
		friend class Iterator<List<Elem> const>;

		friend Iterator<List<Elem>> head<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> first<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> last<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> tail<Elem>(List<Elem>&);

		friend Iterator<List<Elem> const> head<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> first<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> last<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> tail<Elem>(List<Elem> const&);

		public:

			Iterator();
			Iterator(Iterator const&);
			Iterator& operator=(Iterator const&);
			~Iterator();

			Elem& operator*() const;
			Elem* operator->() const;

			Iterator& operator++();
			Iterator operator++(int);
			Iterator& operator--();
			Iterator operator--(int);

			Bool operator==(Iterator const&);
			Bool operator==(Iterator<List<Elem> const> const&);
			Bool operator!=(Iterator const&);
			Bool operator!=(Iterator<List<Elem> const> const&);
	};

	template <typename Elem>
	struct IsIteratorForward<Iterator<List<Elem>>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsIteratorForward<Iterator<List<Elem>> const>
	{
		static Bool const value = true;
	};

	template <typename Elem>
	struct IsIteratorBidirectional<Iterator<List<Elem>>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsIteratorBidirectional<Iterator<List<Elem>> const>
	{
		static Bool const value = true;
	};



	template <typename Elem>
	class Iterator<List<Elem> const>;

	template <typename Elem>
	Void swap(Iterator<List<Elem> const>*, Iterator<List<Elem> const>*);

	template <typename Elem>
	class Iterator<List<Elem> const>
	{
		friend class List<Elem>;
		friend class Iterator<List<Elem>>;

		friend Iterator<List<Elem>> head<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> first<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> last<Elem>(List<Elem>&);
		friend Iterator<List<Elem>> tail<Elem>(List<Elem>&);

		friend Iterator<List<Elem> const> head<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> first<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> last<Elem>(List<Elem> const&);
		friend Iterator<List<Elem> const> tail<Elem>(List<Elem> const&);

		public:

			Iterator();
			Iterator(Iterator const&);
			Iterator& operator=(Iterator const&);
			~Iterator();

			Iterator(Iterator<List<Elem>> const&);

			Elem const& operator*() const;
			Elem const* operator->() const;

			Iterator& operator++();
			Iterator operator++(int);
			Iterator& operator--();
			Iterator operator--(int);

			Bool operator==(Iterator const&);
			Bool operator==(Iterator<List<Elem>> const&);
			Bool operator!=(Iterator const&);
			Bool operator!=(Iterator<List<Elem>> const&);
	};

	template <typename Elem>
	struct IsIteratorForward<Iterator<List<Elem> const>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsIteratorForward<Iterator<List<Elem> const> const>
	{
		static Bool const value = true;
	};

	template <typename Elem>
	struct IsIteratorBidirectional<Iterator<List<Elem> const>>
	{
		static Bool const value = true;
	};
	template <typename Elem>
	struct IsIteratorBidirectional<Iterator<List<Elem> const> const>
	{
		static Bool const value = true;
	};

	#include "list.inl"

#endif //LIST_HPP
