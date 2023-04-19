#pragma once

#include "countrycalendar.h"

namespace QuantitativeFinance
{
		class WeekendOnlyCalendar : public CountryCalendar
		{
		public:
				WeekendOnlyCalendar(std::set<Date> additionalHolidays = std::set<Date>());
				bool isNationalHoliday(Date& date) const override;
				Currency countryCurrency() const override;
		private:
				Currency ccy_;
		};

		inline WeekendOnlyCalendar::WeekendOnlyCalendar(std::set<Date> additionalHolidays)
				:
				CountryCalendar(additionalHolidays)
		{
		}

		inline bool WeekendOnlyCalendar::isNationalHoliday(Date& date) const
		{
				return false;
		}

		inline Currency WeekendOnlyCalendar::countryCurrency() const
		{
				return Currency::UNKNOWN;
		}
}