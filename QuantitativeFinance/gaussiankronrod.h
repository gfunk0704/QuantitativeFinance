#pragma once

#include "adaptivequadrature.h"

// same as R's Gaussian-Kronrod rule
namespace QuantitativeFinance
{
	class GaussianKronrod : public AdaptiveQuadrature
	{
		Real adaptiveAlgorithm(const std::function<Real(Real)>& f, Real a, Real b, Real tol);
	public:
		GaussianKronrod(Real tol, Size maxFunctionCall);
		GaussianKronrod();
		Real integral(const std::function<Real(Real)>& f, Real a, Real b) override;
	};

	inline GaussianKronrod::GaussianKronrod(Real tol, Size maxFunctionCall):
		AdaptiveQuadrature(tol, maxFunctionCall)
	{}

	inline GaussianKronrod::GaussianKronrod():
		AdaptiveQuadrature()
	{}

	Real GaussianKronrod::integral(const std::function<Real(Real)>& f, Real a, Real b)
	{
		functionCall_ = 0;
		return adaptiveAlgorithm(f, a, b, tol_);
	}
}