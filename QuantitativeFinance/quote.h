#pragma once

#include "observerpattern.h"
#include "valuedate.h"

namespace QuantitativeFinance
{
		template<class Instrument>
		class Quote
		{
		public:
				Quote(Real value, SharedPtr<Instrument> instrument);
				Real value() const;
				virtual void setValue(Real value);
				virtual Date expiryDate() const = 0;
		protected:
				Real value_;
				SharedPtr<Instrument> instrument_;
		};

		template<class Instrument>
		inline Quote<Instrument>::Quote(Real value, SharedPtr<Instrument> instrument)
				:
				value_(value),
				instrument_(instrument)
		{}

		template<class Instrument>
		inline Real Quote<Instrument>::value() const
		{
				return value_;
		}

		template<class Instrument>
		inline void Quote<Instrument>::setValue(Real value)
		{
				value_ = value;
		}
}