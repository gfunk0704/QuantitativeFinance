#pragma once

#include "parametricmodel.h"

namespace QuantitativeFinance
{
	class StochasticProcess
	{
	protected:
		Real initialValue_;
	public:
		Real& initialValue();
	};
}