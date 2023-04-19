#pragma once

#include "interestratetermstructure.h"
#include "interestratequote.h"


namespace QuantitativeFinance
{
		class DeterministicRiskFreeRate : public InterestRateTermStructure
		{
		public:
				DeterministicRiskFreeRate(std::vector<SharedPtr<InterestRateQuote>> marketQuotes,
						DayCount dayCount);
				Real maxTime() const;
				Real minTime() const;
		protected:
				std::vector<SharedPtr<InterestRateQuote>> marketQuotes_;
				Real maxTime_;
				Real minTime_;
				
				void setTime();
		};

		inline DeterministicRiskFreeRate::DeterministicRiskFreeRate(std::vector<SharedPtr<InterestRateQuote>> marketQuotes,
				DayCount dayCount)
				:
				InterestRateTermStructure(dayCount),
				marketQuotes_(marketQuotes)
		{
				setTime();
		}

		inline Real DeterministicRiskFreeRate::maxTime() const
		{
				return maxTime_;
		}
		
		inline Real DeterministicRiskFreeRate::minTime() const
		{
				return minTime_;
		}
}