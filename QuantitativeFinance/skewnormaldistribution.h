#pragma once

#include "normaldistribution.h"

namespace QuantitativeFinance
{

	class SkewNormalDistribution : public NormalDistribution
	{
		Real delta_;
		Real pdfScalar_;

		void updateDelta();
		void updateCdfScalar();

	public:
		SkewNormalDistribution(Real mu, Real sigma, Real alpha);
		SkewNormalDistribution();

		List<String> parameterNames() const override;
		ParameterSpace parameterSpace() const override;
		void setParameter(Parameter par) override;
		Real cdf(Real x) const override;
		Real pdf(Real x) const override;
		Real quantile(Real x) const override;
		Real mean() const override;
		Real var() const override;
		Real mgf(Real phi) const override;

		static Real owenT(Real a, Real h);
	};

	inline SkewNormalDistribution::SkewNormalDistribution(
		Real mu, 
		Real sigma, 
		Real alpha
	):
		NormalDistribution(mu, sigma)
	{
		parameter_["alpha"] = alpha;
		updateDelta();
		updateCdfScalar();
	}


	inline SkewNormalDistribution::SkewNormalDistribution():
		SkewNormalDistribution(0.0, 1.0, 0.0)
	{}

	inline void SkewNormalDistribution::updateDelta()
	{
		Real alpha = parameter("alpha");
		delta_ = alpha / std::sqrt(1.0 + alpha * alpha);
	}

	inline void SkewNormalDistribution::updateCdfScalar()
	{
		pdfScalar_ = 2.0 / parameter("sigma");
	}

	inline List<String> SkewNormalDistribution::parameterNames() const
	{
		const static List<String> names = { "mu", "sigma" , "alpha"};
		return names;
	}

	inline ParameterSpace SkewNormalDistribution::parameterSpace() const
	{
		const static ParameterSpace spaces = { {"mu", Space::REAL}, {"sigma", Space::POSITIVE}, {"alpha", Space::REAL}};
		return spaces;
	}

	inline void SkewNormalDistribution::setParameter(Parameter par)
	{
		NormalDistribution::setParameter(par);
		updateDelta();
		updateCdfScalar();
	}

	inline Real SkewNormalDistribution::pdf(Real x) const
	{
		Real z = standerlization(x);
		return pdfScalar_ * standardNormalPdf(z) * 
			standardNormalCdf(parameter("alpha") * z);
	}

	inline Real SkewNormalDistribution::cdf(Real x) const
	{
		Real z = standerlization(x);
		return standardNormalCdf(z) - 2.0 * owenT(z, parameter("alpha"));
	}

}