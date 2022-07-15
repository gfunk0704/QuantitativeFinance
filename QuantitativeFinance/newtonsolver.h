#pragma once

#include "forwarddifference.h"
#include "iterativesolver.h"

namespace QuantitativeFinance
{
	class NewtonSolver : public IterativeSolver<NewtonSolver>
	{
		std::shared_ptr<FiniteDifference> derivative_;
	public:
		NewtonSolver(Size maxIteration, Real tol, std::shared_ptr<FiniteDifference> derivative);
		NewtonSolver();

		Real evaluateG(const ScalarFunction1D f, Real x, Real fx);
	};

	inline NewtonSolver::NewtonSolver(
		Size maxIteration, 
		Real tol, 
		std::shared_ptr<FiniteDifference> derivative
	) :
		IterativeSolver<NewtonSolver>(maxIteration, tol),
		derivative_(derivative)
	{}

	inline NewtonSolver::NewtonSolver() :
		IterativeSolver<NewtonSolver>(),
		derivative_(std::shared_ptr<FiniteDifference>(new ForwardDifference()))
	{}

	inline Real NewtonSolver::evaluateG(const ScalarFunction1D f, Real x, Real fx)
	{
		return derivative_->evaluate(f, x, fx);
	}
}