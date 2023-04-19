#pragma once

#include "forwarddifference.h"
#include "iterativesolver.h"

namespace QuantitativeFinance
{
		class NewtonSolver : public IterativeSolver
		{
				std::shared_ptr<FiniteDifference> derivative_;
		public:
				NewtonSolver(Size maxIteration, Real tol, std::shared_ptr<FiniteDifference> derivative);
				NewtonSolver();

				Real g(const ScalarFunction1D f, Real x, Real fx) const override;
		};

		inline NewtonSolver::NewtonSolver(Size maxIteration,
				Real tol,
				std::shared_ptr<FiniteDifference> derivative)
				:
				IterativeSolver(maxIteration, tol),
				derivative_(derivative)
		{}

		inline NewtonSolver::NewtonSolver()
				:
				IterativeSolver(),
				derivative_(std::shared_ptr<FiniteDifference>(new ForwardDifference()))
		{}

		inline Real NewtonSolver::g(const ScalarFunction1D f, Real x, Real fx) const
		{
				return derivative_->evaluate(f, x, fx);
		}
}