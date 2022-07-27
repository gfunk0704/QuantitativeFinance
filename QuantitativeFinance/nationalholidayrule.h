#pragma once

#include "date.h"

namespace QuantitativeFinance
{
	class NationalHolidayRule
	{
	public:
		virtual bool isNationalHoliday(Date& date) = 0;
	};
}