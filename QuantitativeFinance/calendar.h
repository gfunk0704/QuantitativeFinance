#pragma once

#include <set>
#include "valuedate.h"

namespace QuantitativeFinance
{
		class Calendar
		{
		public:
				Calendar(std::set<Date> additionalHolidays = std::set<Date>());

				bool isBusinessday(Date& date) const;
				Date shiftNBusubessday(Date d, Size nDay, bool backward) const;
				virtual bool isHoliday(Date& date) const;
				virtual Date convertTenorToExpiryDate(Date origin, const Period& tenor) const = 0;
				virtual Date spotDate(Date origin, Natural spotLag) const = 0;
				Date spotDate(Natural spotLag) const;
		protected:
				std::set<Date> additionalHolidays_;
		};

		inline Calendar::Calendar(std::set<Date> additionalHolidays)
				:
				additionalHolidays_(additionalHolidays)
		{
		}

		inline bool Calendar::isHoliday(Date& date) const
		{
				return additionalHolidays_.find(date) != additionalHolidays_.end();
		}

		inline bool Calendar::isBusinessday(Date& date) const
		{
				return !isHoliday(date);
		}

		inline 	Date Calendar::spotDate(Natural spotLag) const
		{
				return spotDate(ValueDate::getInstance().get(), spotLag);
		}

}