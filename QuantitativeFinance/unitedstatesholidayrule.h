#pragma once

#include "nationalholidayrule.h"

namespace QuantitativeFinance
{
	class UnitedStatesHolidayRule : public NationalHolidayRule
	{
	public:
		UnitedStatesHolidayRule();
		bool isNationalHoliday(Date& date) override;
	};

	inline UnitedStatesHolidayRule::UnitedStatesHolidayRule()
	{}
}