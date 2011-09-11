#ifndef SEQUENCE_HPP
	#define SEQUENCE_HPP

	#include "bool.hpp"
	#include "size.hpp"

	template <typename Sequence>
	struct IsSequenceForward
	{
		static Bool const value = false;
	};
	template <typename Iterator>
	struct IsIteratorForward
	{
		static Bool const value = false;
	};

	template <typename Sequence>
	struct IsSequenceBidirectional
	{
		static Bool const value = false;
	};
	template <typename Iterator>
	struct IsIteratorBidirectional
	{
		static Bool const value = false;
	};

	template <typename Sequence>
	struct IsSequenceRandomAccessable
	{
		static Bool const value = false;
	};
	template <typename Iterator>
	struct IsIteratorRandomAccessable
	{
		static Bool const value = false;
	};



	template <typename Seq>
	Size length(Seq const& seq);



#endif //SEQUENCE_HPP
