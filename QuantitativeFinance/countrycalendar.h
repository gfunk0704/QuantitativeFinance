#pragma once

#include <set>

#include "calendar.h"

namespace QuantitativeFinance
{
		class CountryCalendar : public Calendar
		{
		protected:
				std::function<bool(const Date&)> rule_;
				std::set<Weekday> weekend_;
				CountryCalendar(std::function<bool(const Date&)> rule,
						std::set<Weekday> weekend = { Weekday::SAT, Weekday::SUN },
						std::set<Date> addtionalHolidays = std::set<Date>());
		public:
				bool isHoliday(const Date& date) const override;
				Date convertTenorToExpiryDate(Date origin, const Period& tenor) const override;
		};

		inline CountryCalendar::CountryCalendar(std::function<bool(const Date&)> rule,
				std::set<Weekday> weekend,
				std::set<Date> addtionalHolidays)
				:
				Calendar(addtionalHolidays),
				rule_(rule), weekend_(weekend)
		{}

		inline bool CountryCalendar::isHoliday(const Date& date) const
		{
				if (weekend_.find(date.weekday()) != weekend_.end())
						return true;
				return rule_(date) || Calendar::isHoliday(date);
		}
}