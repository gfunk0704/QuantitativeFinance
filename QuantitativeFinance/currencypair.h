#pragma once

#include "currency.h"

namespace QuantitativeFinance
{
	class CurrencyPair
	{
		Currency ccy1_;
		Currency ccy2_;
	public:
		CurrencyPair(Currency ccy1, Currency ccy2);
		Currency ccy1() const;
		Currency ccy2() const;
		Currency dominantCcy() const;
	};

	inline CurrencyPair::CurrencyPair(Currency ccy1, Currency ccy2):
		ccy1_(ccy1),
		ccy2_(ccy2)
	{}

	inline Currency CurrencyPair::ccy1() const
	{
		return ccy1_;
	}

	inline Currency CurrencyPair::ccy2() const
	{
		return ccy2_;
	}

	inline Currency CurrencyPair::dominantCcy() const
	{
		return (ccy1_ > ccy2_) ? ccy1_ : ccy2_;
	}
}