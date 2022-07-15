#pragma once

#include "bracketingsolver.h"

namespace QuantitativeFinance
{
	class BisectionSolver : public BracketingSolver
	{
	public:
		BisectionSolver(Size maxIteration, Real tol);
		BisectionSolver();

		RootFindingResult solve(const ScalarFunction1D f, Real a, Real b) override;
	};

	inline BisectionSolver::BisectionSolver(Size maxIteration, Real tol):
		BracketingSolver(maxIteration, tol)
	{}

	inline 	BisectionSolver::BisectionSolver():
		BracketingSolver()
	{}
}