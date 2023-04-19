#pragma once

#include "interestratequote.h"

namespace QuantitativeFinance
{
		class CashRateQuote : public InterestRateQuote
		{
		public:
				CashRateQuote(Real value, Period tenor, Natural spotLag, DayCount dayCount, SharedPtr<Calendar> calendar);
				DayCounter dayCounter() const;
				Date expiryDate() const override;
				Real impliedQuote(InterestRateTermStructure& termStructure) const override;
		private:
				Real calcuationPeriod_;
				DayCounter dayCounter_;
				Date expiryDate_;

				void update() override;
		};

		inline CashRateQuote::CashRateQuote(Real value,
				Period tenor,
				Natural spotLag,
				DayCount dayCount,
				SharedPtr<Calendar> calendar)
				:
				InterestRateQuote(value, tenor, spotLag, calendar),
				dayCounter_(dayCount)
		{
		}

		inline DayCounter CashRateQuote::dayCounter() const
		{
				return dayCounter_;
		}

		inline Date CashRateQuote::expiryDate() const
		{
				return expiryDate_;
		}

		inline Real CashRateQuote::impliedQuote(InterestRateTermStructure& termStructure) const
		{
				auto spotDiscount = termStructure.discountFactor(spotDate_);
				auto expiryDiscount = termStructure.discountFactor(expiryDate_);
				return (spotDiscount / expiryDiscount - 1.0) / calcuationPeriod_;
		}

		inline void CashRateQuote::update()
		{
				InterestRateQuote::update();
				expiryDate_ = calendar_->convertTenorToExpiryDate(spotDate_, tenor_);
				calcuationPeriod_ = dayCounter_(spotDate_, expiryDate_);
		}
}