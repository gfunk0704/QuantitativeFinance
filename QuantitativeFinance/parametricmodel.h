#pragma once

#include <unordered_map>;

#include "type.h"

namespace QuantitativeFinance
{
	enum class Space
	{
		MINUS_ONE_TO_ONE,
		POSITIVE,
		REAL
	};
	
	using Parameter = std::unordered_map<String, Real>;
	using ParameterSpace = std::unordered_map<String, Space>;

	class ParametricModel
	{
	protected:
		Parameter parameter_;
		ParametricModel(Parameter parameter);
	public:
		Real parameter(String name) const;
		virtual List<String> parameterNames() const = 0;
		virtual ParameterSpace parameterSpace() const = 0;
		virtual void setParameter(Parameter par);
	};

	inline ParametricModel::ParametricModel(Parameter parameter):
		parameter_(parameter)
	{}

	inline Real ParametricModel::parameter(String name) const
	{
		return parameter_.find(name)->second;
	}

	void ParametricModel::setParameter(Parameter par)
	{
		for (auto elem : par)
		{
			if (parameter_.count(elem.first))
				parameter_[elem.first] = elem.second;
		}
	}
}