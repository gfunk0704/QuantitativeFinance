#pragma once

#include "daycount.h"
#include "interestratetermstructure.h"
#include "quote.h"

namespace QuantitativeFinance
{
		class InterestRateQuote : public Quote
		{
		public:
				InterestRateQuote(Real value, Period tenor, Natural spotLag, SharedPtr<Calendar> calendar);
				Real impliedQuote(SharedPtr<InterestRateTermStructure> termStructure) const;
				virtual Real impliedQuote(InterestRateTermStructure& termStructure) const;
				Date spotDate() const;
		protected:
				Period tenor_;
				Natural spotLag_;
				Date spotDate_;
				virtual void update() override;
		};

		inline InterestRateQuote::InterestRateQuote(Real value,
				Period tenor,
				Natural spotLag,
				SharedPtr<Calendar> calendar)
				:
				Quote(value, calendar),
				tenor_(tenor),
				spotLag_(spotLag)
		{
		}

		inline Date InterestRateQuote::spotDate() const
		{
				return spotDate_;
		}

		inline void InterestRateQuote::update()
		{
				spotDate_ = calendar_->spotDate(spotLag_);
		}

		inline Real InterestRateQuote::impliedQuote(SharedPtr<InterestRateTermStructure> termStructure) const
		{
				return impliedQuote(*termStructure);
		}
}
