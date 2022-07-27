#include "iterativesolver.h"

namespace QuantitativeFinance
{
		inline RootFindingResult IterativeSolver::solve(const ScalarFunction1D f, Real guess) const
		{
				Size t;
				Real x = guess;
				Real fx = f(x);
				Real preX, preFx;
				for (t = 0; t <= maxIteration_; ++t)
				{
						if (std::abs(fx) < tol_)
						{
								RootFindingResult::Convergence convergence = RootFindingResult::Convergence::TOL_REACH;
								return RootFindingResult(convergence, t, x, fx);
						}
						preX = x;
						preFx = fx;
						x = preX - fx / g(f, preX, preFx);
						fx = f(x);
				}
				RootFindingResult::Convergence convergence = RootFindingResult::Convergence::MAX_ITER_REACH;
				return RootFindingResult(convergence, t, x, fx);
		}
}