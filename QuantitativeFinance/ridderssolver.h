#pragma once

#include "bracketingsolver.h"

namespace QuantitativeFinance
{
	class RiddersSolver : public BracketingSolver
	{
	public:
		RiddersSolver(Size maxIteration, Real tol);
		RiddersSolver();

		RootFindingResult solve(const ScalarFunction1D f, Real a, Real b) override;
	};

	inline RiddersSolver::RiddersSolver(Size maxIteration, Real tol) :
		BracketingSolver(maxIteration, tol)
	{}

	inline 	RiddersSolver::RiddersSolver() :
		BracketingSolver()
	{}
}