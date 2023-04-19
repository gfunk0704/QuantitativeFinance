#pragma once

#include "type.h"

namespace QuantitativeFinance
{
		using CurrencyHierarchy = std::uint_fast8_t;

		enum class Currency
		{
				USD,
				JPY,
				UNKNOWN
		};

		inline CurrencyHierarchy getCurrencyHierarchy(Currency ccy)
		{
				switch (ccy)
				{
				case Currency::USD:
						return 10;
				case Currency::JPY:
						return 1;
				default:
						return 0;
				}
		}

}