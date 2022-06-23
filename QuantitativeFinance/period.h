#pragma once

#include "type.h"

namespace QuantitativeFinance
{
	enum class TimeUnit
	{
		DAYS, WEEKS, MONTHS, YEARS
	};

	class Period
	{
		using NumberType = std::int_fast32_t;

		NumberType number_;
		TimeUnit unit_;
	public:
		Period(NumberType number, TimeUnit unit);
		Integer number() const;
		TimeUnit unit() const;

		static Period days(NumberType number);
		static Period weeks(NumberType number);
		static Period months(NumberType number);
		static Period years(NumberType number);
	};

	inline Period::Period(NumberType number, TimeUnit unit):
		number_(number),
		unit_(unit)
	{}

	inline Period::NumberType Period::number() const
	{
		return number_;
	}

	inline TimeUnit Period::unit() const
	{
		return unit_;
	}

	inline Period Period::days(NumberType number)
	{
		return Period(number, TimeUnit::DAYS);
	}

	inline Period Period::weeks(NumberType number)
	{
		return Period(number, TimeUnit::WEEKS);
	}

	inline Period Period::months(NumberType number)
	{
		return Period(number, TimeUnit::MONTHS);
	}

	inline Period Period::years(NumberType number)
	{
		return Period(number, TimeUnit::YEARS);
	}
}