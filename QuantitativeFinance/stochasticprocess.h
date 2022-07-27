#pragma once

#include "parametricmodel.h"
namespace QuantitativeFinance
{
	class CharacteristicFunction;
	
	class StochasticProcess : ParametricModel
	{
	public:
		virtual std::shared_ptr<CharacteristicFunction> characteristicFunction(Real tau) = 0;
	};
}