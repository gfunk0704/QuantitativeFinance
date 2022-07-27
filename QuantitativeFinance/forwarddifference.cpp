#include "forwarddifference.h"

namespace QuantitativeFinance
{
		RealArray1D ForwardDifference::evaluate(const ScalarFunction f, RealArray1D x, Real fx) const
		{
				RealArray1D gradient = RealArray1D::Zero(x.size());
				for (Size i = 0; i < gradient.size(); ++i)
				{
						x[i] += h_;
						gradient[i] = (f(x) - fx) / h_;
						x[i] -= h_;
				}
				return gradient;
		}
}