#pragma once

#include "deterministicriskfreerate.h"
#include "parametricmodel.h"

namespace QuantitativeFinance
{
		class ParametricRiskFreeRate : public DeterministicRiskFreeRate,
				public ParametricModel
		{
		public:
				ParametricRiskFreeRate(Size nParam,
						std::vector<SharedPtr<InterestRateQuote>> marketQuotes,
						DayCount dayCount)
						:
						ParametricModel(nParam),
						DeterministicRiskFreeRate(marketQuotes, dayCount)
				{
				}
		};
}