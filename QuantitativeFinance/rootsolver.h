#pragma once

#include "constant.h"

namespace QuantitativeFinance
{
	struct RootFindingResult
	{
	public:
		enum class Convergence
		{
			TOL_REACH,
			MAX_ITER_REACH,
			NOT_BRACKETED
		};
		
		Convergence convergence;
		Size iteration;
		Real x;
		Real fx;

		inline RootFindingResult(Convergence convergence, Size iteration, Real x, Real fx):
			convergence(convergence),
			iteration(iteration),
			x(x),
			fx(fx)
		{}
	};

	class RootSolver
	{
	protected:
		Size maxIteration_;
		Real tol_;
	public:
		RootSolver(Size maxIteration, Real tol);
		RootSolver();
		
	};

	inline RootSolver::RootSolver(Size maxIteration, Real tol):
		maxIteration_(maxIteration),
		tol_(tol)
	{}

	inline RootSolver::RootSolver() :
		RootSolver(100, SQRT_EPSILON)
	{}
}