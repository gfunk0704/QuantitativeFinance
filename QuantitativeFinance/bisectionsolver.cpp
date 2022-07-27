#include "bisectionsolver.h"

namespace QuantitativeFinance
{
		RootFindingResult BisectionSolver::solve(const ScalarFunction1D f, Real a, Real b) const
		{
				Real fa = f(a);
				Real fb = f(b);
				Real lower, upper, mid, fLower, fUpper, fMid;
				Size t;

				validility(fa, fb);

				if (fa < fb)
				{
						lower = a;
						fLower = fa;
						upper = b;
						fUpper = fb;
				}
				else
				{
						lower = b;
						fLower = fb;
						upper = a;
						fUpper = fa;
				}

				for (t = 1; t <= maxIteration_; ++t)
				{
						mid = 0.5 * (lower + upper);
						fMid = f(mid);

						if (std::abs(fMid) < tol_)
						{
								RootFindingResult::Convergence convergence = RootFindingResult::Convergence::TOL_REACH;
								return RootFindingResult(convergence, t, mid, fMid);
						}

						if (fMid < 0)
						{
								fLower = fMid;
								lower = mid;
						}
						else
						{
								fUpper = fMid;
								upper = mid;
						}
				}
				RootFindingResult::Convergence convergence = RootFindingResult::Convergence::MAX_ITER_REACH;
				return RootFindingResult(convergence, t, mid, fMid);
		}
}