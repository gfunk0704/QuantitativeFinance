#pragma once

#include "iterativesolver.h"

namespace QuantitativeFinance
{
	class SteffensenSolver : public IterativeSolver<SteffensenSolver>
	{
	public:
		SteffensenSolver(Size maxIteration, Real tol);
		SteffensenSolver();

		Real implementG(const ScalarFunction1D f, Real x, Real fx);
	};

	inline SteffensenSolver::SteffensenSolver(Size maxIteration, Real tol):
		IterativeSolver<SteffensenSolver>(maxIteration, tol)
	{}

	inline SteffensenSolver::SteffensenSolver():
		IterativeSolver<SteffensenSolver>()
	{}

	inline Real SteffensenSolver::implementG(const ScalarFunction1D f, Real x, Real fx)
	{
		return (f(x + fx) - fx) / fx;
	}
}