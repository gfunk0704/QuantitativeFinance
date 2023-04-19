#include "countrycalendar.h"

namespace QuantitativeFinance
{
		bool CountryCalendar::isHoliday(Date& date) const
		{
				if (isWeekend(date))
						return true;
				else if (Calendar::isHoliday(date))
						return true;
				else
						return  isNationalHoliday(date);
		}

		Date CountryCalendar::convertTenorToExpiryDate(Date origin, const Period& tenor) const
		{
				auto expiryDate = origin + tenor;

				if (isBusinessday(expiryDate))
						return expiryDate;

				auto backward = Date::endOfMonth(expiryDate) &&
						(tenor.unit() == TimeUnit::MONTHS || tenor.unit() == TimeUnit::YEARS);

				return shiftNBusubessday(expiryDate, 1, backward);
		}
}