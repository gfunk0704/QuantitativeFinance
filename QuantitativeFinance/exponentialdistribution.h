#pragma once

#include "constant.h"
#include "univariatedistribution.h"

namespace QuantitativeFinance
{
	class ExponentialDistribution : public ContinuousDistribution
	{
	public:
		ExponentialDistribution(Real lambda);
		ExponentialDistribution();

		List<String> parameterNames() const override;
		ParameterSpace parameterSpace() const override;
		void setParameter(Parameter par) override;
		Real cdf(Real x) const override;
		Real pdf(Real x) const override;
		Real quantile(Real x) const override;
		Real mean() const override;
		Real var() const override;
		Real mgf(Real phi) const override;
	};

	inline ExponentialDistribution::ExponentialDistribution(Real lambda) :
		ContinuousDistribution({ {"mu", lambda} })
	{}

	inline ExponentialDistribution::ExponentialDistribution() :
		ExponentialDistribution(1.0)
	{}
}