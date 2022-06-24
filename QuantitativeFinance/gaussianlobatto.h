#pragma once

#include "adaptivequadrature.h"
#include "constant.h"
#include "utility.h"

namespace QuantitativeFinance
{
	class GaussianLobatto : public AdaptiveQuadrature
	{
		Real  adaptiveAlgorithm(const std::function<Real(Real)>& f, Real a, Real b, Real fa, Real fb, Real is);
	public:
		GaussianLobatto(Real tol, Size maxFunctionCall);
		GaussianLobatto();
		Real integral(const std::function<Real(Real)>& f, Real a, Real b) override;
	};

	

	inline GaussianLobatto::GaussianLobatto(Real tol, Size maxFunctionCall) :
		AdaptiveQuadrature(tol, maxFunctionCall)
	{}

	inline GaussianLobatto::GaussianLobatto() :
		AdaptiveQuadrature()
	{}
}