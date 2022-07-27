#pragma once

#include "iterativesolver.h"

namespace QuantitativeFinance
{
	class SteffensenSolver : public IterativeSolver
	{
	public:
		SteffensenSolver(Size maxIteration, Real tol);
		SteffensenSolver();

		Real g(const ScalarFunction1D f, Real x, Real fx) override;
	};

	inline SteffensenSolver::SteffensenSolver(Size maxIteration, Real tol):
		IterativeSolver(maxIteration, tol)
	{}

	inline SteffensenSolver::SteffensenSolver():
		IterativeSolver()
	{}

	inline Real SteffensenSolver::g(const ScalarFunction1D f, Real x, Real fx)
	{
		return (f(x + fx) - fx) / fx;
	}
}