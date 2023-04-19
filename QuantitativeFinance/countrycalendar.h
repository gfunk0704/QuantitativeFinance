#pragma once

#include <set>

#include "calendar.h"
#include "currency.h"

namespace QuantitativeFinance
{
		class CountryCalendar : public Calendar
		{
		public:
				CountryCalendar(std::set<Date> addtionalHolidays = std::set<Date>());
				bool isHoliday(Date& date) const override;
				Date convertTenorToExpiryDate(Date origin, const Period& tenor) const override;
				virtual bool isWeekend(Date& date) const;
				virtual Currency countryCurrency() const = 0;
				virtual bool isNationalHoliday(Date& date) const = 0;
		};

		inline CountryCalendar::CountryCalendar(std::set<Date> addtionalHolidays)
				:
				Calendar(addtionalHolidays)
		{
		}

		inline bool CountryCalendar::isWeekend(Date& date) const
		{
				auto weekday = date.weekday();
				return (weekday == Weekday::SUN) || (weekday == Weekday::SAT);
		}
}