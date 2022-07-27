#pragma once

#include "constant.h"
#include "univariatedistribution.h"

namespace QuantitativeFinance
{
		class Gaussian : public ContinuousDistribution,
				                      public ParametricModel
		{
		public:
				Gaussian(Real mu = 0.0,
								  Real sigma = 1.0);

				std::vector<String> paramNames() const override;
				std::vector<Real> paramLowerBound() const override;
				std::vector<Real> paramUpperBound() const override;

				Real cdf(Real x) const override;
				Real pdf(Real x) const override;
				Real quantile(Real x) const override;
				Real mean() const override;
				Real var() const override;

				static Real standardGaussianPdf(Real z);
				static Real standardGaussianCdf(Real z);
				static Real standardGaussianQuantile(Real p);
		protected:
				Real& mu_;
				Real& sigma_;
				Real standerlization(Real x) const;
				std::vector<Real> mapToParameterSpace(std::vector<Real> values) const override;
		private:
				static Real interpolateStandardGaussianCdf(Real z);
		};

		inline Gaussian::Gaussian(Real mu, Real sigma)
				 :
				ParametricModel(),
				mu_(params_[0]),
				sigma_(params_[1])
		{
				params_[0] = mu;
				params_[1] = sigma;
		}

		inline std::vector<String> Gaussian::paramNames() const
		{
				return {"mu", "sigma"};
		}

		inline std::vector<Real> Gaussian::paramLowerBound() const
		{
				return {-INF, 0.0};
		}

		inline std::vector<Real> Gaussian::paramUpperBound() const
		{
				return {INF, INF};
		}

		inline Real Gaussian::standerlization(Real x) const
		{
				return (x - mu_ / sigma_);
		}

		inline Real Gaussian::cdf(Real x) const
		{
				return standardGaussianCdf(standerlization(x));
		}

		inline Real Gaussian::pdf(Real x) const
		{
				return standardGaussianPdf(standerlization(x));
		}

		inline Real Gaussian::quantile(Real p) const
		{
				return mu_ + sigma_ * standardGaussianQuantile(p);
		}

		inline Real Gaussian::mean() const
		{
				return mu_;
		}

		inline Real Gaussian::var() const
		{
				return sigma_ * sigma_;
		}

		inline Real Gaussian::standardGaussianPdf(Real z)
		{
				static const Real pdfCoef = 1.0 / std::sqrt(2.0 * PI);
				return pdfCoef * std::exp(-0.5 * z * z);
		}

		inline std::vector<Real> Gaussian::mapToParameterSpace(std::vector<Real> values) const
		{
				values[1] = std::exp(values[1]);
				return values;
		}

		inline Real Gaussian::standardGaussianCdf(Real z)
		{
				return (z > 0.0) ?
						interpolateStandardGaussianCdf(z) :
						(1.0 - interpolateStandardGaussianCdf(-z));
		}
}