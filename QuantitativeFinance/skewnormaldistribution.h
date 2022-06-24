#pragma once

#include "normaldistribution.h"

namespace QuantitativeFinance
{
	class SkewNormalDistribution : public NormalDistribution
	{
		Real delta_;
	public:
		SkewNormalDistribution(Real mu, Real sigma, Real alpha);
		SkewNormalDistribution();

		virtual List<String> parameterNames() const override;
		virtual ParameterSpace parameterSpace() const override;
		virtual void setParameter(Parameter par) override;
		virtual Real cdf(Real x) const override;
		virtual Real pdf(Real x) const override;
		virtual Real quantile(Real x) const override;
		virtual Real mean() const override;
		virtual Real var() const override;
		virtual Real mgf(Real phi) const override;
	};
}