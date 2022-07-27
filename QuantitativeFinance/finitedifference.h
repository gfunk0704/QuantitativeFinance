#pragma once

#include "constant.h"

namespace QuantitativeFinance
{
		class FiniteDifference
		{
		protected:
				Real h_;
		public:
				FiniteDifference(Real h);
				FiniteDifference();

				virtual Real evaluate(const ScalarFunction1D f, Real x) const = 0;
				virtual Real evaluate(const ScalarFunction1D f, Real x, Real fx) const  = 0;
				virtual RealArray1D evaluate(const ScalarFunction f, RealArray1D x) const  = 0;
				virtual RealArray1D evaluate(const ScalarFunction f, RealArray1D x, Real fx) const = 0;
		};

		inline FiniteDifference::FiniteDifference(Real h)
		:
				h_(h)
		{}

		inline FiniteDifference::FiniteDifference() :
				FiniteDifference(SQRT_EPSILON)
		{}
}