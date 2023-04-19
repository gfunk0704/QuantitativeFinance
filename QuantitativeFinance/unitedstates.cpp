#include "unitedstates.h"

namespace QuantitativeFinance
{
		bool UnitedStatesCalendar::isNationalHoliday(Date& date) const
		{
				SerialType dd = date.day();
				Weekday wday = date.weekday();
				bool isMonday = wday == Weekday::MON;
				bool isFriday = wday == Weekday::FRI;

				switch (date.month())
				{
				case Month::JAN:
						//New Year's Day
						return (dd == 1 || (isMonday && dd == 2)) ||
								// Martin Luther King's birthday (third Monday in January)
								(isMonday && (dd >= 15 && dd <= 21));
				case Month::FEB:
						// Washington Birthday
						return isMonday && (dd >= 15 && dd <= 21);
				case Month::MAY:
						// Memorial Day
						return isMonday && dd >= 25;
				case Month::JUN:
						// Juneteenth 
						return (date.year() >= 2022) && (dd == 19 || (isMonday && dd == 20) || (isFriday && dd == 18));
				case Month::JUL:
						// Independence Day
						return (dd == 4) || (isMonday && dd == 5) || (isFriday && dd == 3);
				case Month::SEP:
						//Labor Day
						return isMonday && dd <= 7;
				case Month::OCT:
						// Columbus Day
						return isMonday && (dd >= 8 && dd <= 14);
				case Month::NOV:
						// Veterans Day
						return (dd == 11 || (isMonday && dd == 12) || (isFriday && dd == 10)) ||
								// Thanksgiving Day
								((dd >= 22 && dd <= 28) && wday == Weekday::THU);
				case Month::DEC:
						// Christmas
						return (dd == 25 || (isMonday && dd == 26) || (isFriday && dd == 24)) ||
								//New Year's Day
								(dd == 31 && wday == Weekday::FRI);
				default:
						return false;
				}
		}
}