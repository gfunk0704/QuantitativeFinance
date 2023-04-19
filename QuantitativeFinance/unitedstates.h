#pragma once

#include  "countrycalendar.h"

namespace QuantitativeFinance
{
		class UnitedStatesCalendar : public CountryCalendar
		{
		public:
				UnitedStatesCalendar(std::set<Date> additionalHolidays = std::set<Date>());
				bool isNationalHoliday(Date& date) const override;
				Currency countryCurrency() const;
		};

		inline UnitedStatesCalendar::UnitedStatesCalendar(std::set<Date> additionalHolidays)
				:
				CountryCalendar(additionalHolidays)
		{
		}

		inline Currency UnitedStatesCalendar::countryCurrency() const
		{
				return Currency::USD;
		}
}