#pragma once

#include "rootsolver.h"

namespace QuantitativeFinance
{
		class IterativeSolver : public RootSolver
		{
		public:
				IterativeSolver(Size maxIteration, Real tol);
				IterativeSolver();
				RootFindingResult solve(const ScalarFunction1D f, Real guess) const;
				virtual Real g(const ScalarFunction1D f, Real x, Real fx) const = 0;
		};

		inline IterativeSolver::IterativeSolver(Size maxIteration, Real tol)
				:
				RootSolver(maxIteration, tol)
		{}

		inline IterativeSolver::IterativeSolver()
				:
				RootSolver()
		{}
}