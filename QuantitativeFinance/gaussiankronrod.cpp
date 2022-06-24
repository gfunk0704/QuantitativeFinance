#include "gaussiankronrod.h"

namespace QuantitativeFinance
{
    static const Real gaussWeights[4] = {
        0.417959183673469,
        0.381830050505119,
        0.279705391489277,
        0.129484966168870
    };

    static const Real kronrodWeights[8] = {
            0.209482141084728,
            0.204432940075298,
            0.190350578064785,
            0.169004726639267,
            0.140653259715525,
            0.104790010322250,
            0.063092092629979,
            0.022935322010529
    };

    static const Real points[8] = {
        0.000000000000000,
        0.207784955007898,
        0.405845151377397,
        0.586087235467691,
        0.741531185599394,
        0.864864423359769,
        0.949107912342758,
        0.991455371120813
    };

	Real GaussianKronrod::adaptiveAlgorithm(
		const std::function<Real(Real)>& f,
		Real a,
		Real b,
        Real tol
	)
	{
        maxNumberValidility();
        Real halfInterval = 0.5 * (b - a);
        Real mid = 0.5 * (a + b);
        Real gauss = 0.0;
        Real kronrod = 0.0;
        Real value = f(mid);
        gauss = value * gaussWeights[0];
        kronrod = value * kronrodWeights[0];
        for (Size i = 1; i < 4; ++i)
        {
            Size kronrodIndex = i * 2;
            Real pointScalar = halfInterval * points[kronrodIndex];
            Real fSum = f(mid + pointScalar) + f(mid - pointScalar);
            gauss += fSum * gaussWeights[i];
            kronrod += fSum * kronrodWeights[kronrodIndex];
        }
        for (Size i = 1; i < 8; i += 2)
        {
            Real pointScalar = halfInterval * points[i];
            kronrod += (f(mid - pointScalar) + f(mid + pointScalar)) * kronrodWeights[i];
        }

        gauss *= halfInterval;
        kronrod *= halfInterval;
        functionCall_ += 15;

        if (std::fabs(gauss - kronrod) < tol)
        {
            return kronrod;
        }
        else
        {
            return adaptiveAlgorithm(f, a, mid, 0.5 * tol) +
                adaptiveAlgorithm(f, mid, b, 0.5 * tol);
        }
	}
}