#pragma once

#include "interestratetermstructure.h"
#include "interestratequote.h"
#include "piecewiseconstant.h"

namespace QuantitativeFinance
{
		class DeterministicRiskFreeRate : public InterestRateTermStructure
		{
		public:
				DeterministicRiskFreeRate(SharedPtr<InterestRateQuote> marketQuotes,
						DayCount dayCount,
						SharedPtr<NonparametricCurve> curve = SharedPtr<NonparametricCurve>(new PiecewiseConstant()));
				virtual Real discountFactor(Real maturity) const override;
				virtual Real instForward(Real maturity) const override;
				virtual Real zeroRate(Real maturity) const override;
		private:
				SharedPtr<NonparametricCurve> curve_;
				void bootstrap(SharedPtr<InterestRateQuote> marketQuotes);
		};

		DeterministicRiskFreeRate::DeterministicRiskFreeRate(SharedPtr<InterestRateQuote> marketQuotes,
				DayCount dayCount,
				SharedPtr<NonparametricCurve> curve)
				:
				InterestRateTermStructure(dayCount),
				curve_(curve)
		{
				curve_->clear();
				bootstrap(marketQuotes);
		}
}