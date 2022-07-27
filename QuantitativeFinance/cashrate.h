#pragma once

#include "interestratequote.h"

namespace QuantitativeFinance
{
		template<class T>
		class CashRate : public InterestRateQuote<T>
		{
				
		public:
				CashRate(Period tenor, DayCount dayCount, Real value);
				std::function<Real(SharedPtr<T>)> setImpliedQuote(SharedPtr<T> termStructure) override;
		private:
				class CashRateImpliedQuote
				{
				public:
						CashRateImpliedQuote(CashRate* cash);
						Real operator()(SharedPtr<T> termStructure);
				private:
						Real tau_;
						Date startDate_;
						Date endDate_;
				}
		};
}