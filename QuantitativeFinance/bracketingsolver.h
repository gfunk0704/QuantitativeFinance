#pragma once

#include "rootsolver.h"
#include "utility.h"

namespace QuantitativeFinance
{
	class BracketingSolver : public RootSolver
	{
	protected:
		void validility(Real fa, Real fb);
	public:
		BracketingSolver(Size maxIteration, Real tol);
		BracketingSolver();
		virtual RootFindingResult solve(const ScalarFunction1D f, Real a, Real b) = 0;
	};

	inline BracketingSolver::BracketingSolver(Size maxIteration, Real tol):
		RootSolver(maxIteration, tol)
	{}

	inline BracketingSolver::BracketingSolver():
		RootSolver()
	{}

	inline void BracketingSolver::validility(Real fa, Real fb)
	{
		ASSERT((fa * fb < 0), " f() values at end points not of opposite sign");
	}
}