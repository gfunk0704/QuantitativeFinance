#pragma once

#include "rootsolver.h"

namespace QuantitativeFinance
{
	template<class T>
	class IterativeSolver : public RootSolver
	{
	public:
		IterativeSolver(Size maxIteration, Real tol);
		IterativeSolver();
		RootFindingResult solve(const ScalarFunction1D f, Real guess);
		Real g(const ScalarFunction1D f, Real x, Real fx);
	};

	template<class T>
	inline IterativeSolver<T>::IterativeSolver(Size maxIteration, Real tol):
		RootSolver(maxIteration, tol)
	{}

	template<class T>
	inline IterativeSolver<T>::IterativeSolver() :
		RootSolver()
	{}

	template<class T>
	inline RootFindingResult IterativeSolver<T>::solve(const ScalarFunction1D f, Real guess)
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

	template<class T>
	inline Real IterativeSolver<T>::g(const ScalarFunction1D f, Real x, Real fx)
	{
		return static_cast<T*>(this)->implementG(f, x, fx);
	}
}