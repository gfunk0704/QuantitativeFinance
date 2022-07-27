#pragma once

#include "observerpattern.h"
#include "parametricmodel.h"
#include "yieldtermstructure.h"

namespace QuantitativeFinance
{
		class VirtualHestonModel : public ParametricModel
		{
		public:
				VirtualHestonModel(SharedPtr<YieldTermStructure> rd);
				Real initialValue() const;
				virtual Real setInitialValue(Real value);
				virtual std::vector<String> paramNames() const override;
				virtual std::vector<Real> paramLowerBound() const override;
				virtual std::vector<Real> paramUpperBound() const override;
		};

		
}