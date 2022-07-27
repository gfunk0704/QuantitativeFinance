#include "date.h"

namespace QuantitativeFinance
{
		Date::Date(Year yyyy, Month mm, Day dd) 
		:
				year_(yyyy),
				month_(mm),
				day_(dd),
				updateYmd_(true)
		{
				std::uint_fast32_t monthNumber = static_cast<Unsigned>(mm);
				yyyy -= monthNumber <= 2;
				SerialType era = (yyyy >= 0 ? yyyy : yyyy - 399) / 400;
				Unsigned yoe = static_cast<Unsigned>(yyyy - era * 400);                              // [0, 399]
				Unsigned doy = (153 * (monthNumber + (monthNumber > 2 ? -3 : 9)) + 2) / 5 + dd - 1;  // [0, 365]
				Unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;                                // [0, 146096]
				serialNumber_ = era * 146097 + static_cast<SerialType>(doe) - 719468;
		}

		Date Date::shiftMonths(SerialType n)
		{
				SerialType monthNumber = static_cast<SerialType>(month()) + n;
				Year yyyy = year();
				while (monthNumber > 12)
				{
						--yyyy;
						monthNumber -= 12;
				}
				while (monthNumber < 1)
				{
						++yyyy;
						monthNumber += 12;
				}
				Month mm = Month(monthNumber);
				Day dd = std::min(endOfMonth(yyyy, mm), day());
				return Date(yyyy, mm, dd);
		}

		void Date::update()
		{
				SerialType z = serialNumber_ + 719468;
				SerialType era = (z >= 0 ? z : z - 146096) / 146097;
				Unsigned doe = static_cast<unsigned>(z - era * 146097);                // [0, 146096]
				Unsigned yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;  // [0, 399]
				Unsigned doy = doe - (365 * yoe + yoe / 4 - yoe / 100);                // [0, 365]
				Unsigned mp = (5 * doy + 2) / 153;                                     // [0, 11]
				day_ = doy - (153 * mp + 2) / 5 + 1;                                   // [1, 31]
				month_ = Month((mp < 10) ? (mp + 3) : (mp - 9));                      // [1, 12]
				year_ = (static_cast<SerialType>(yoe) + era * 400) + (static_cast<Unsigned>(month_) <= 2);
				updateYmd_ = true;
		}

		Date Date::operator+(const Period& period)
		{
				SerialType number = period.number();
				switch (period.unit())
				{
				case TimeUnit::DAYS:
						return Date(serialNumber_ + number);
				case TimeUnit::WEEKS:
						return Date(serialNumber_ + 7 * number);
				case TimeUnit::MONTHS:
						return shiftMonths(number);
				case TimeUnit::YEARS:
						return shiftYears(number);
				default:
						throw("unknown period unit found");
				}
		}

		Day Date::endOfMonth(Year yyyy, Month mm)
		{
				switch (mm)
				{
				case Month::JAN:
				case Month::MAR:
				case Month::MAY:
				case Month::JUL:
				case Month::AUG:
				case Month::OCT:
				case Month::DEC:
						return 31;
				case Month::APR:
				case Month::JUN:
				case Month::SEP:
				case Month::NOV:
						return 30;
				case Month::FEB:
						return isLeap(yyyy) ? 29 : 28;
				}
		}
}