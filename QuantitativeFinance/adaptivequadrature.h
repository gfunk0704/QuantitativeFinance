#pragma once

#include <functional>

#include "constant.h"
#include "utility.h"

namespace QuantitativeFinance
{
	class AdaptiveQuadrature
	{		
	protected:
		Size functionCall_;
		Size maxFunctionCall_;
		Real tol_;
		
		void maxNumberValidility();
	public:
		AdaptiveQuadrature(Real tol, Size maxFunctionCall);
		AdaptiveQuadrature();
		virtual Real integral(const std::function<Real(Real)>& g, Real a, Real b) = 0;
	};
	inline AdaptiveQuadrature::AdaptiveQuadrature(Real tol, Size maxFunctionCall):
		tol_(tol),
		maxFunctionCall_(maxFunctionCall),
		functionCall_(0)
	{}

	inline AdaptiveQuadrature::AdaptiveQuadrature():
		AdaptiveQuadrature(1e-8, 2048)
	{}

	inline void AdaptiveQuadrature::maxNumberValidility()
	{
		ASSERT(functionCall_ > maxFunctionCall_, "max number of function call is reached");
	}

}