#ifndef META_IF_HPP
	#define META_IF_HPP

	#include "bool.hpp"

	namespace meta
	{
		namespace _impl
		{
			namespace _If
			{
				template <Bool condition, typename TrueMetaType, typename... OptionalFalseMetaType>
				struct If;
				template <typename TrueMetaType>
				struct If<true, TrueMetaType> : public TrueMetaType
				{
				};
				template <typename TrueMetaType>
				struct If<false, TrueMetaType>
				{
				};
				template <typename TrueMetaType, typename FalseMetaType>
				struct If<true, TrueMetaType, FalseMetaType> : public TrueMetaType
				{
				};
				template <typename TrueMetaType, typename FalseMetaType>
				struct If<false, TrueMetaType, FalseMetaType> : public FalseMetaType
				{
				};
			}
		}

		template <typename ConditionMetaValue, typename TrueMetaType, typename... OptionalFalseMetaType>
		struct If;
		template <typename ConditionMetaValue, typename TrueMetaType>
		struct If<ConditionMetaValue, TrueMetaType> : public _impl::_If::If<ConditionMetaValue::value, TrueMetaType>
		{
		};
		template <typename ConditionMetaValue, typename TrueMetaType, typename FalseMetaType>
		struct If<ConditionMetaValue, TrueMetaType, FalseMetaType> : public _impl::_If::If<ConditionMetaValue::value, TrueMetaType, FalseMetaType>
		{
		};
	}

#endif //META_IF_HPP
