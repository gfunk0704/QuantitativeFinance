#pragma once

#include <set>
#include "date.h"

namespace QuantitativeFinance
{
		class Calendar
		{
		public:
				Calendar(std::set<Date> additionalHolidays = std::set<Date>());

				bool isBusinessday(const Date& date) const;
				Date shiftNBusubessday(Date d, Size nDay, bool backward) const;
				virtual bool isHoliday(const Date& date) const;
				virtual Date convertTenorToExpiryDate(Date origin, const Period& tenor) const = 0;
		protected:
				std::set<Date> additionalHolidays_;
		};

		inline Calendar::Calendar(std::set<Date> additionalHolidays)
				:
				additionalHolidays_(additionalHolidays)
		{}

		inline bool Calendar::isHoliday(const Date& date) const
		{
				return additionalHolidays_.find(date) != additionalHolidays_.end();
		}

		inline bool Calendar::isBusinessday(const Date& date) const
		{
				return !isHoliday(date);
		}
}