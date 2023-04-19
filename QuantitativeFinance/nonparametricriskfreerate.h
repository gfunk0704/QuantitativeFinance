#pragma once

#include "deterministicriskfreerate.h"
#include "newtonsolver.h"
#include "piecewiseconstant.h"

namespace QuantitativeFinance
{
		class NonparametricRiskFreeRate : public DeterministicRiskFreeRate
		{
		public:
				NonparametricRiskFreeRate(std::vector<SharedPtr<InterestRateQuote>> marketQuotes,
						DayCount dayCount);
				Real discountFactor(Real maturity) const override;
				Real instForward(Real maturity) const override;
				Real zeroRate(Real maturity) const override;
				template<class CURVE_TYPE = PiecewiseConstant>
				void bootstrap();
		private:
				std::vector<SharedPtr<InterestRateQuote>> marketQuotes_;
				SharedPtr<NonparametricCurve> curve_;
		};

		NonparametricRiskFreeRate::NonparametricRiskFreeRate(std::vector<SharedPtr<InterestRateQuote>> marketQuotes,
				DayCount dayCount)
				:
				DeterministicRiskFreeRate(marketQuotes, dayCount),
				marketQuotes_(marketQuotes)
		{
				bootstrap();
		}

		inline Real NonparametricRiskFreeRate::discountFactor(Real maturity) const
		{
				return std::exp(-curve_->integral(maturity));
		}

		inline Real NonparametricRiskFreeRate::instForward(Real maturity) const
		{
				return curve_->getY(maturity);
		}

		inline Real NonparametricRiskFreeRate::zeroRate(Real maturity) const
		{
				return curve_->integral(maturity) / maturity;
		}

		template<class CURVE_TYPE>
		void NonparametricRiskFreeRate::bootstrap()
		{

				std::sort(marketQuotes_.begin(),
						marketQuotes_.end(),
						[](auto lhs, auto > rhs) -> {return (lhs->expiryDate() < rhs->expiryDate()); });

				curve_ = SharedPtr<NonparametricCurve>(new CURVE_TYPE());
				NewtonSolver solver;
				for (auto quote : marketQuotes_)
				{
						auto tau = maturityYears(quote->expiryDate());
						auto objectFunction = [this, tau, quote](Real guess) ->  {
								curve_->pushBack(Point2D(tau, guess));
								auto diff = quote->impliedQuote(*this) - quote->value();
								curve_->popBack();
								return diff;
						};
						auto findingResult = solver.solve(objectFunction, quote->value());
						curve_->pushBack(Point2D(tau, findingResult.x()));
				}
		}
}