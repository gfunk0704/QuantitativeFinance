#pragma once

#include "finitedifference.h"

namespace QuantitativeFinance
{
		class CentralDifference : public FiniteDifference
		{
		public:
				CentralDifference(Real h);
				CentralDifference();
				Real evaluate(const ScalarFunction1D f, Real x) const override;
				Real evaluate(const ScalarFunction1D f, Real x, Real fx) const override;
				RealArray1D evaluate(const ScalarFunction f, RealArray1D x) const override;
				RealArray1D evaluate(const ScalarFunction f, RealArray1D x, Real fx) const override;
		};

		inline CentralDifference::CentralDifference(Real h) 
		:
				FiniteDifference(h)
		{}

		inline CentralDifference::CentralDifference() 
		:
				FiniteDifference()
		{}

		inline Real CentralDifference::evaluate(const ScalarFunction1D f, Real x) const
		{
				return (f(x + h_) - f(x - h_)) / (2.0 * h_);
		}

		inline Real CentralDifference::evaluate(const ScalarFunction1D f, Real x, Real fx) const
		{
				return evaluate(f, x);
		}

		inline RealArray1D CentralDifference::evaluate(const ScalarFunction f, RealArray1D x, Real fx) const
		{
				return evaluate(f, x);
		}
}