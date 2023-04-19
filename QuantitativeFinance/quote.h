#pragma once

#include "calendar.h"
#include "observer.h"
#include "valuedate.h"

namespace QuantitativeFinance
{

		class Quote : public Observer
		{
		public:
				Quote(Real value, SharedPtr<Calendar> calendar);
				SharedPtr<Calendar> calendar() const;
				Real value() const;
				void setValue(Real value);
				virtual Date expiryDate() const = 0;

		protected:
				Real value_;
				SharedPtr<Calendar> calendar_;
		};

		inline Quote::Quote(Real value, SharedPtr<Calendar> calendar)
				:
				Observer(&ValueDate::getInstance()),
				value_(value),
				calendar_(calendar)
		{
				update();
		}

		inline SharedPtr<Calendar> Quote::calendar() const
		{
				return calendar_;
		}

		inline Real Quote::value() const
		{
				return value_;
		}

		inline void Quote::setValue(Real value)
		{
				value_ = value;
		}
}