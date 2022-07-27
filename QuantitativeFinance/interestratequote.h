#pragma once

#include "daycount.h"
#include "period.h"
#include "quote.h"

namespace QuantitativeFinance
{
		class InterestRateQuote : public Quote
		{
		public:
				InterestRateQuote(Real value);
				virtual Real impliedQuote() const = 0;
		};

		inline InterestRateQuote::InterestRateQuote(Real value)
				:
				Quote(value)
		{}
}