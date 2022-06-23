#pragma once

#include "process.h"

namespace QuantitativeFinance
{
	class TimeHomogeneousProcess : public Process
	{
	public:
		TimeHomogeneousProcess(Real stateVariable);
		TimeHomogeneousProcess();

		List<String> parameterNames() const override;
		ParameterSpace parameterSpace() const override;
	};

	inline TimeHomogeneousProcess::TimeHomogeneousProcess(Real stateVariable) :
		Process({ {"omega", 0.0}, {"a", 0.0}, {"b", 0.0}, {"c", 0.0} }, stateVariable)
	{}

	inline TimeHomogeneousProcess::TimeHomogeneousProcess():
		TimeHomogeneousProcess(0.0)
	{}

	constexpr List<String> TimeHomogeneousProcess::parameterNames() const
	{
		return { "omega", "a", "b", "c" };
	}

	constexpr ParameterSpace TimeHomogeneousProcess::parameterSpace() const
	{
		return { {"omega", Space::POSITIVE}, {"a", Space::POSITIVE}, {"b", Space::POSITIVE}, {"c", Space::REAL} };
	}
}