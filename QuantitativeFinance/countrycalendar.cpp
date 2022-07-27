#include "countrycalendar.h"

namespace QuantitativeFinance
{
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