#pragma once

#include "finitedifference.h"

namespace QuantitativeFinance
{
	class CentralDifference : public FiniteDifference
	{
	public:
		CentralDifference(Real h);
		CentralDifference();
		Real evaluate(const ScalarFunction1D f, Real x) override;
		Real evaluate(const ScalarFunction1D f, Real x, Real fx) override;
		RealArray1D evaluate(const ScalarFunction f, RealArray1D x) override;
		RealArray1D evaluate(const ScalarFunction f, RealArray1D x, Real fx) override;
	};

	inline CentralDifference::CentralDifference(Real h) :
		FiniteDifference(h)
	{}

	inline CentralDifference::CentralDifference() :
		FiniteDifference()
	{}

	inline Real CentralDifference::evaluate(const ScalarFunction1D f, Real x)
	{
		return (f(x + h_) - f(x - h_)) / h_;
	}

	inline Real CentralDifference::evaluate(const ScalarFunction1D f, Real x, Real fx)
	{
		return evaluate(f, x);
	}

	inline RealArray1D CentralDifference::evaluate(const ScalarFunction f, RealArray1D x, Real fx)
	{
		return evaluate(f, x);
	}
}