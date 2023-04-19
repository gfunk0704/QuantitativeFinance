#pragma once

#include "date.h"

namespace QuantitativeFinance
{
		enum class DayCount
		{
				ACTUAL_360,
				ACTUAL_365_FIXED,
				ACTUAL_ACTUAL_ISDA,
				THIRTY_360_EUROPEAN,
				THIRTY_360_ITALY
		};

		class DayCounter
		{
		public:
				DayCounter(DayCount dayCount);
				DayCount dayCount() const;
				Real operator()(const Date& startDate, const Date& endDate) const;
		private:
				DayCount dayCount_;
				std::function<Real(Date, Date)> counter_;

				static std::function<Real(Date, Date)>  createCounter(DayCount dayCount);
		};

		inline DayCounter::DayCounter(DayCount dayCount)
				:
				dayCount_(dayCount),
				counter_(createCounter(dayCount))
		{
		}

		inline DayCount DayCounter::dayCount() const
		{
				return dayCount_;
		}

		inline Real DayCounter::operator()(const Date& startDate, const Date& endDate) const
		{
				return counter_(startDate, endDate);
		}
}