#pragma once

#include "daycount.h"
#include "valuedate.h"

namespace QuantitativeFinance
{
		class InterestRateTermStructure
		{
		public:
				InterestRateTermStructure(DayCount dayCount);
				virtual Real discountFactor(Real maturity) const = 0;
				Real discountFactor(const Date& maturity) const;
				virtual Real instForward(Real maturity) const = 0;
				Real instForward(const Date& maturity) const;
				virtual Real zeroRate(Real maturity) const = 0;
				Real zeroRate(const Date& maturity) const;
		protected:
				DayCounter dayCounter_;
				Date referenceDate_;

				Real maturityYears(const Date& maturity) const;
		};

		inline InterestRateTermStructure::InterestRateTermStructure(DayCount dayCount)
				:
				dayCounter_(dayCount)
		{
		}

		inline Real InterestRateTermStructure::discountFactor(const Date& maturity) const
		{
				return discountFactor(maturityYears(maturity));
		}

		inline Real InterestRateTermStructure::instForward(const Date& maturity) const
		{
				return instForward(maturityYears(maturity));
		}

		inline Real InterestRateTermStructure::zeroRate(const Date& maturity) const
		{
				return zeroRate(maturityYears(maturity));
		}

		inline Real InterestRateTermStructure::maturityYears(const Date& maturity) const
		{
				return dayCounter_(ValueDate::getInstance().get(), maturity);
		}
}