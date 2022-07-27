#pragma once

#include "calendar.h"
#include "interestratetermstructure.h"
#include "instrument.h"

namespace QuantitativeFinance
{
		class LinearInterestRateInstrument : public Instrument
		{
		public:
				LinearInterestRateInstrument(Natural spotLag, Period tenor);
				Date expiryDate() const override;
				virtual Real impliedQuote(SharedPtr<InterestRateTermStructure> termStructure) const = 0;
		protected:
				Date expiryDate_;
		};

		inline Date LinearInterestRateInstrument::expiryDate() const
		{
				return expiryDate_;
		}
}