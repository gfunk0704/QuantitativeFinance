#pragma once

#include "parametricmodel.h"

namespace QuantitativeFinance
{
		template<typename T>
		class UnivariateDistribution : public ParametricModel
		{
		public:
				virtual Real cdf(T x) const = 0;
				virtual Real pdf(T x) const = 0;
				virtual T quantile(Real p) const = 0;
				virtual Real mean() const = 0;
				virtual Real var() const = 0;
		protected:
				UnivariateDistribution(Size nParam) : ParametricModel(nParam) {};
		};

		using ContinuousDistribution = UnivariateDistribution<Real>;
		using DiscreteDistribution = UnivariateDistribution<Natural>;
}