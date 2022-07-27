#pragma once

#include "calendar.h"

namespace QuantitativeFinance
{
		class Instrument
		{
		public:
				Instrument(SharedPtr<Calendar> calendar);
				virtual Date expiryDate() const = 0;
		protected:
				SharedPtr<Calendar> calendar_;
		};

		inline Instrument::Instrument(SharedPtr<Calendar> calendar)
				:
				calendar_(calendar)
		{}
}