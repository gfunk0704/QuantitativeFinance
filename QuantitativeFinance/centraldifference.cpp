#include "centraldifference.h"

namespace QuantitativeFinance
{
		RealArray1D CentralDifference::evaluate(const ScalarFunction f, RealArray1D x) const
		{
				RealArray1D xPlus = x;
				RealArray1D xMinus = x;
				RealArray1D gradient = RealArray1D::Zero(x.size());
				Real dominator = 2.0 * h_;
				for (Size i = 0; i < gradient.size(); ++i)
				{
						auto temp = x[i];
						xPlus[i] += h_;
						xMinus[i] -= h_;
						gradient[i] = (f(xPlus) - f(xMinus)) / dominator;
						xPlus[i] = temp;
						xMinus[i] = temp;
				}
				return gradient;
		}
}