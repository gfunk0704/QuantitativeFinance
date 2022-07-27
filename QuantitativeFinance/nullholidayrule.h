#pragma once

#include "nationalholidayrule.h"

namespace QuantitativeFinance
{
	class NullHolidayRule : public NationalHolidayRule
	{
	public:
		NullHolidayRule();
		bool isNationalHoliday(Date& date) override;
	};

	inline NullHolidayRule::NullHolidayRule()
	{}

	inline bool NullHolidayRule::isNationalHoliday(Date& date)
	{
		return false;
	}
}