#include "calendar.h"

namespace QuantitativeFinance
{
		Date Calendar::shiftNBusubessday(Date d, Size nDay, bool backward) const
		{
				std::function<void()> shiftOneDay;
				if (backward)
						shiftOneDay = [&d]() -> void {--d; };
				else
						shiftOneDay = [&d]() -> void {++d; };
				while (nDay > 0)
				{
						shiftOneDay();
						if (isBusinessday(d))
								--nDay;
				}
				return d;
		}
}