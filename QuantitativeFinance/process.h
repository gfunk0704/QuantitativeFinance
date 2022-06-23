#pragma once

#include "parametricmodel.h"

namespace QuantitativeFinance
{
	class Process : public ParametricModel
	{
	protected:
		Real stateVariable_;
		Process(Parameter parameter, Real stateVariable);
		Process(Parameter parameter);
	public:
		Real& stateVariable();
	};

	inline Process::Process(Parameter parameter, Real stateVariable) :
		ParametricModel(parameter),
		stateVariable_(stateVariable)
	{}

	inline Process::Process(Parameter parameter):
		Process(parameter, 0.0)
	{}

	inline Real& Process::stateVariable()
	{
		return stateVariable_;
	}
}