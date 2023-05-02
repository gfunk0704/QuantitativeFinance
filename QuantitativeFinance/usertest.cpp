#include <iomanip>

#include "gaussian.h"




using namespace QuantitativeFinance;

void demo()
{
        std::cout << "\nShow that the NormalCDFInverse function is accurate at \n"
                << "0.05, 0.15, 0.25, ..., 0.95 and at a few extreme values.\n\n";

        double p[] =
        {
            0.0000001,
            0.00001,
            0.001,
            0.05,
            0.15,
            0.25,
            0.35,
            0.45,
            0.55,
            0.65,
            0.75,
            0.85,
            0.95,
            0.999,
            0.99999,
            0.9999999
        };

        // Exact values computed by Mathematica.
        double exact[] =
        {
            -5.199337582187471,
            -4.264890793922602,
            -3.090232306167813,
            -1.6448536269514729,
            -1.0364333894937896,
            -0.6744897501960817,
            -0.38532046640756773,
            -0.12566134685507402,
             0.12566134685507402,
             0.38532046640756773,
             0.6744897501960817,
             1.0364333894937896,
             1.6448536269514729,
             3.090232306167813,
             4.264890793922602,
             5.199337582187471
        };

        double maxerror = 0.0;
        int numValues = sizeof(p) / sizeof(double);
        std::cout << "p, exact CDF inverse, computed CDF inverse, diff\n\n";
        std::cout << std::setprecision(7);
        Gaussian gaussian;
        for (int i = 0; i < numValues; ++i)
        {
                double computed = gaussian.quantile(p[i]);
                double error = exact[i] - computed;
                std::cout << p[i] << ", " << exact[i] << ", "
                        << computed << ", " << error << "\n"; if (fabs(error) > maxerror)
                        maxerror = fabs(error);
        }

        std::cout << "\nMaximum error: " << maxerror << "\n\n";
}

int main()
{
		demo();
		return 0;
}