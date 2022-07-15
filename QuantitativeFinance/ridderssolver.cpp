#include "ridderssolver.h"

namespace QuantitativeFinance
{
	RootFindingResult RiddersSolver::solve(const ScalarFunction1D f, Real a, Real b)
	{
		Real fa = f(a);
		Real fb = f(b);
		Real c, fc, x, fx;
		Size t;
		validility(fa, fb);


		for (Size t = 1; t <= maxIteration_; ++t)
		{
			c = 0.5 * (a + b);
			fc = f(c);
		}
	}
}