#pragma once

#include <cmath>

#include "constant.h"
#include "univariatedistribution.h"

namespace QuantitativeFinance
{
		class Gaussian : public ContinuousDistribution
		{
		public:
				enum class CDFMethod
				{
						MARSAGLIA,
						PIECEWISE_LINEAR
				};

				enum class QuantileMethod
				{
						ABRAMOWITZ_AND_STEGUN,
						VOUTIER
				};

				Gaussian(Real mu = 0.0,
						Real sigma = 1.0,
						CDFMethod cdfMethod = CDFMethod::PIECEWISE_LINEAR,
						QuantileMethod inverseCdfMethod = QuantileMethod::VOUTIER);

				std::vector<String> paramNames() const override;
				std::vector<Real> paramLowerBound() const override;
				std::vector<Real> paramUpperBound() const override;
				void setCdf(CDFMethod method);
				void setQuantile(QuantileMethod method);
				std::pair<CDFMethod, QuantileMethod> numericalMethods() const;
				Real cdf(Real x) const override;
				Real pdf(Real x) const override;
				Real quantile(Real x) const override;
				Real mean() const override;
				Real var() const override;

		private:
				Real& mu_;
				Real& sigma_;
				std::pair<CDFMethod, QuantileMethod> numericalMethods_;
				std::function<Real(Real)> cdf_;
				std::function<Real(Real)> quantile_;

				Real standerlization(Real x) const;
				std::vector<Real> mapToParameterSpace(std::vector<Real> values) const override;

				static Real interpolateStandardGaussianCdf(Real z);
				static Real standardPdf(Real z);

				//List of CDFs:
				static Real marsagliaCdf(Real z);
				static Real piecewiseLinearCdf(Real z);

				//List of inverse CDFs
				static Real voutierQuantile(Real p);
				static Real  abramowitzStegunQuantile(Real p);
		};

		inline Gaussian::Gaussian(Real mu,
				Real sigma,
				CDFMethod cdfMethod,
				QuantileMethod inverseCdfMethod)
				:
				UnivariateDistribution(2),
				mu_(params_[0]),
				sigma_(params_[1])
		{
				params_[0] = mu;
				params_[1] = sigma;
				setCdf(cdfMethod);
				setQuantile(inverseCdfMethod);
		}

		inline std::vector<String> Gaussian::paramNames() const
		{
				return { "mu", "sigma" };
		}

		inline std::vector<Real> Gaussian::paramLowerBound() const
		{
				return { -INF, 0.0 };
		}

		inline std::vector<Real> Gaussian::paramUpperBound() const
		{
				return { INF, INF };
		}

		inline Real Gaussian::standerlization(Real x) const
		{
				return (x - mu_ / sigma_);
		}

		inline Real Gaussian::cdf(Real x) const
		{
				return cdf_(standerlization(x));
		}

		inline Real Gaussian::pdf(Real x) const
		{
				return standardPdf(standerlization(x));
		}

		inline Real Gaussian::quantile(Real p) const
		{
				return mu_ + sigma_ * quantile_(p);
		}

		inline Real Gaussian::mean() const
		{
				return mu_;
		}

		inline Real Gaussian::var() const
		{
				return sigma_ * sigma_;
		}

		inline Real Gaussian::standardPdf(Real z)
		{
				static const Real pdfCoef = 1.0 / std::sqrt(2.0 * PI);
				return pdfCoef * std::exp(-0.5 * z * z);
		}

		inline std::vector<Real> Gaussian::mapToParameterSpace(std::vector<Real> values) const
		{
				values[1] = std::exp(values[1]);
				return values;
		}


}