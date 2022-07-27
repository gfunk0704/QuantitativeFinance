#pragma once

#include "finitedifference.h"

namespace QuantitativeFinance
{
		class ForwardDifference : public FiniteDifference
		{
		public:
				ForwardDifference(Real h);
				ForwardDifference();
				Real evaluate(const ScalarFunction1D f, Real x) const override;
				Real evaluate(const ScalarFunction1D f, Real x, Real fx) const override;
				RealArray1D evaluate(const ScalarFunction f, RealArray1D x) const override;
				RealArray1D evaluate(const ScalarFunction f, RealArray1D x, Real fx) const override;
		};

		inline ForwardDifference::ForwardDifference(Real h) 
		:
				FiniteDifference(h)
		{}

		inline ForwardDifference::ForwardDifference() 
		:
				FiniteDifference()
		{}

		inline Real ForwardDifference::evaluate(const ScalarFunction1D f, Real x) const
		{
				return evaluate(f, x, f(x));
		}

		inline Real ForwardDifference::evaluate(const ScalarFunction1D f, Real x, Real fx) const
		{
				return (f(x + h_) - fx) / h_;
		}

		inline RealArray1D ForwardDifference::evaluate(const ScalarFunction f, RealArray1D x) const
		{
				return evaluate(f, x, f(x));
		}
}