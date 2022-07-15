#pragma once

#include "finitedifference.h"

namespace QuantitativeFinance
{
	class ForwardDifference : public FiniteDifference
	{
	public:
		ForwardDifference(Real h);
		ForwardDifference();
		Real evaluate(const ScalarFunction1D f, Real x) override;
		Real evaluate(const ScalarFunction1D f, Real x, Real fx) override;
		RealArray1D evaluate(const ScalarFunction f, RealArray1D x) override;
		RealArray1D evaluate(const ScalarFunction f, RealArray1D x, Real fx) override;
	};

	inline ForwardDifference::ForwardDifference(Real h):
		FiniteDifference(h)
	{}

	inline ForwardDifference::ForwardDifference():
		FiniteDifference()
	{}

	inline Real ForwardDifference::evaluate(const ScalarFunction1D f, Real x)
	{
		return evaluate(f, x, f(x));
	} 

	inline Real ForwardDifference::evaluate(const ScalarFunction1D f, Real x, Real fx)
	{
		return (f(x + h_) - fx) / h_;
	}

	inline RealArray1D ForwardDifference::evaluate(const ScalarFunction f, RealArray1D x)
	{
		return evaluate(f, x, f(x));
	}
}