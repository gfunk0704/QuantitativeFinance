#include "centraldifference.h"

namespace QuantitativeFinance
{
	RealArray1D CentralDifference::evaluate(const ScalarFunction f, RealArray1D x)
	{
		RealArray1D xPlus = x;
		RealArray1D xMinus = x;
		RealArray1D gradient = RealArray1D::Zero(x.size());
		for (Size i = 0; i < gradient.size(); ++i)
		{
			xPlus[i] += h_;
			xMinus[i] -= h_;
			gradient[i] = (f(xPlus) - f(xMinus)) / h_;
			xPlus[i] -= h_;
			xMinus[i] += h_;
		}
		return gradient;
	}
}