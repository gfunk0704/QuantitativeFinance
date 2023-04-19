#pragma once

#include "date.h"
#include "observer.h"
#include "singleton.h"
#include "utility.h"

namespace QuantitativeFinance
{
		class ValueDate : public Singleton<ValueDate>,
				public Observable
		{
		public:
				void set(Date d);
				Date get() const;
		private:
				Date valueDate_ = Date::NullDate();
				friend class  Singleton<ValueDate>;
				ValueDate() = default;
		};

		inline void ValueDate::set(Date d)
		{
				valueDate_ = d;
				notisfyAll();
		}

		inline Date ValueDate::get() const
		{
				ASSERT(valueDate_ != Date::NullDate(), "value date is not set up yet");
				return valueDate_;
		}
}