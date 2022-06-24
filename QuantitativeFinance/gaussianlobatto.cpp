#include "gaussianlobatto.h"

namespace QuantitativeFinance
{
	static const Real alpha = sqrt(2.0 / 3.0);
	static const Real beta = 1.0 / sqrt(5.0);

	Real GaussianLobatto::adaptiveAlgorithm(
		const std::function<Real(Real)>& f,
		Real a,
		Real b,
		Real fa,
		Real fb,
		Real is)
	{
		maxNumberValidility();
		Real m = 0.5 * (a + b);
		Real h = 0.5 * (b - a);
		Real alphaH = alpha * h;
		Real betaH = beta * h;
		Real mll = m - alphaH; 
		Real ml = m - betaH; 
		Real mr = m + betaH; 
		Real mrr = m + alphaH;
		Real fmll = f(mll);
		Real fml = f(ml); 
		Real fm = f(m);
		Real fmr = f(mr); 
		Real fmrr = f(mrr);
		functionCall_ += 5;
		Real mlmrSum = fml + fmr;
		Real fafbSum = fa + fb;
		Real i2 = (h / 6.0) * (fafbSum + 5.0 * mlmrSum);
		Real i1  = (h / 1470.0) * (77 * fafbSum + 432.0 * (fmll + fmrr) + 625.0 * mlmrSum + 672.0 * fm);
		Real dist = is + (i1 - i2);
		if ((dist == is) ||
			(mll <= a) ||
			(b <= mrr))
		{
			return i1;
		}
		else
		{
			return adaptiveAlgorithm(f, a, mll, fa, fmll, is)
				+ adaptiveAlgorithm(f, mll, ml, fmll, fml, is)
				+ adaptiveAlgorithm(f, ml, m, fml, fm, is)
				+ adaptiveAlgorithm(f, m, mr, fm, fmr, is)
				+ adaptiveAlgorithm(f, mr, mrr, fmr, fmrr, is)
				+ adaptiveAlgorithm(f, mrr, b, fmrr, fb, is);
		}
	}

	Real GaussianLobatto::integral(
		const std::function<Real(Real)>& f,
		Real a,
		Real b
		)
	{
		Real m = 0.5 * (a + b);
		Real h = 0.5 * (b - a);
		Real alphaH = alpha * h;
		Real betaH = beta * h;
		Real x1H = 0.942882415695480 * h;
		Real x2H = 0.641853342345781 * h;
		Real x3H = 0.236383199662150 * h;
		Real y1 = f(a);
		Real y2 = f(m - x1H);
		Real y3 = f(m - alphaH);
		Real y4 = f(m - x2H);
		Real y5 = f(m - betaH);
		Real y6 = f(m - x3H);
		Real y7 = f(m);
		Real y8 = f(m + x3H);
		Real y9 = f(m + betaH);
		Real y10 = f(m + x2H);
		Real y11 = f(m + alphaH);
		Real y12 = f(m + x1H);
		Real y13 = f(b);
		Real i2 = (h / 6) * (y1 + y13 + 5 * (y5 + y9));
		Real i1 = (h / 1470.0) * (77.0 * (y1 + y13) + 
			432.0 * (y3 + y11) + 625.0 * (y5 + y9) + 672.0 * y7);
		Real is = h * (
			0.0158271919734802 * (y1 + y13) +
			0.0942738402188500 * (y2 + y12) + 
			0.155071987336585 * (y3 + y11) + 
			0.188821573960182 * (y4 + y10) + 
			0.199773405226859 * (y5 + y9) + 
			0.224926465333340 * (y6 + y8) +
			0.242611071901408 * y7
			);
		Real s = (is < 0)? -1.0 : 1.0;
		Real erri1 = std::abs(i1 - is);
		Real erri2 = std::abs(i2 - is);
		Real r = (erri2 == 0.0) ? 1.0 : (erri1 / erri2);
		is = s * abs(is) * tol_ / EPSILON;
		if (is == 0)
			is = b - a;
		functionCall_ = 13;
		return adaptiveAlgorithm(f, a, b, y1, y13, is);
	}
}