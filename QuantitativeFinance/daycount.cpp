#include "daycount.h"

namespace QuantitativeFinance
{
		static Real actualActualISDA(Date startDate, Date endDate)
		{
				auto year1 = startDate.year();
				auto year2 = endDate.year();
				auto dominator1 = Date::isLeap(year1) ? 366.0 : 365.0;
				auto dominator2 = Date::isLeap(year2) ? 366.0 : 365.0;
				auto years = year2 - year1 - 1;
				years += (Date(year1 + 1, Month::JAN, 1) - startDate) / dominator1;
				years += (endDate - Date(year2, Month::JAN, 1)) / dominator2;
				return years;
		}

		static struct Thirty360
		{
		public:
				Thirty360(std::function<Day(Date&)> adjustDay)
						:
						adjustDay_(adjustDay)
				{
				}

				Real operator()(Date startDate, Date endDate)
				{
						auto d1 = adjustDay_(startDate);
						auto d2 = adjustDay_(endDate);
						auto yearPart = Real(endDate.year() - startDate.year()) * 360.0;
						auto monthPart = Real(SerialType(endDate.month()) - SerialType(startDate.month())) * 30.0;
						return (yearPart + monthPart + Real(d2 - d1)) / 360.0;
				}
		private:
				std::function<Day(Date&)> adjustDay_;
		};

		inline Day adjustDayEuropean(Date& d)
		{
				auto days = d.day();
				return (days > 30) ? 30 : days;
		}

		inline Day adjustDayItaly(Date& d)
		{
				auto days = d.day();
				auto maxValue = (d.month() == Month::FEB) ? 28 : 30;
				return (days > maxValue) ? 30 : days;
		}

		std::function<Real(Date, Date)> DayCounter::createCounter(DayCount dayCount)
		{
				Real dominator;
				switch (dayCount)
				{
				case DayCount::ACTUAL_360:
				case DayCount::ACTUAL_365_FIXED:
						dominator = (dayCount == DayCount::ACTUAL_360) ? 360.0 : 365.0;
						return [dominator](Date startDate, Date endDate) -> Real {return (endDate - startDate) / dominator; };
				case DayCount::ACTUAL_ACTUAL_ISDA:
						return actualActualISDA;
				case DayCount::THIRTY_360_EUROPEAN:
						return Thirty360(adjustDayEuropean);
				case DayCount::THIRTY_360_ITALY:
						return Thirty360(adjustDayItaly);
				default:
						throw std::runtime_error("unknown day count convention found;");
				}
		}
}