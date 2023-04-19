#include "deterministicriskfreerate.h"

namespace QuantitativeFinance
{
		void DeterministicRiskFreeRate::setTime()
		{
				std::sort(marketQuotes_.begin(),
								marketQuotes_.end(),
								[](auto& lhs, auto& rhs) -> bool{return lhs->expiryDate() < rhs->expiryDate();});
				minTime_ = maturityYears(marketQuotes_.front()->expiryDate());
				maxTime_ = maturityYears(marketQuotes_.back()->expiryDate());
		}
}