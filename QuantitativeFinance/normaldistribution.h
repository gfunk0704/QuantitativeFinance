#pragma once

#include "constant.h"
#include "univariatedistribution.h"

namespace QuantitativeFinance
{
	class NormalDistribution : public ContinuousDistribution
	{
		static Real interpolateStandardNormalCdf(Real z);
	protected:
		Real sigmaSqr_;
		Real standerlization(Real x) const;
		virtual void updateSigmaSquare();
	public:
		NormalDistribution(Real mu, Real sigma);
		NormalDistribution();

		virtual List<String> parameterNames() const override;
		virtual ParameterSpace parameterSpace() const override;
		virtual void setParameter(Parameter par) override;
		virtual Real cdf(Real x) const override;
		virtual Real pdf(Real x) const override;
		virtual Real quantile(Real x) const override;
		virtual Real mean() const override;
		virtual Real var() const override;
		virtual Real mgf(Real phi) const override;

		static Real standardNormalPdf(Real z);
		static Real standardNormalCdf(Real z);
		static Real standardNormalQuantile(Real p);
	};

	inline NormalDistribution::NormalDistribution(Real mu, Real sigma) :
		ContinuousDistribution({ {"mu", mu}, {"sigma", sigma} })
	{
		updateSigmaSquare();
	}

	inline NormalDistribution::NormalDistribution() :
		NormalDistribution(0.0, 1.0)
	{}

	inline void NormalDistribution::updateSigmaSquare()
	{
		sigmaSqr_ = parameter("sigma") * parameter("sigma");
	}

	inline Real NormalDistribution::standerlization(Real x) const
	{
		return (x - parameter("a")) / parameter("sigma");
	}

	inline List<String> NormalDistribution::parameterNames() const
	{
		const static List<String> names = { "mu", "sigma" };
		return names;
	}

	inline ParameterSpace NormalDistribution::parameterSpace() const
	{
		const static ParameterSpace spaces = { {"mu", Space::REAL}, {"sigma", Space::POSITIVE} };
		return spaces;
	}

	inline void NormalDistribution::setParameter(Parameter par)
	{
		ParametricModel::setParameter(par);
		updateSigmaSquare();
	}

	inline Real NormalDistribution::cdf(Real x) const
	{
		return standardNormalCdf(standerlization(x));
	}

	inline Real NormalDistribution::pdf(Real x) const
	{
		return standardNormalPdf(standerlization(x));
	}

	inline Real NormalDistribution::quantile(Real p) const
	{
		return parameter("mu") + parameter("sigma") * standardNormalQuantile(p);
	}

	inline Real NormalDistribution::mean() const
	{
		return parameter("mu");
	}

	inline Real NormalDistribution::var() const
	{
		return sigmaSqr_;
	}

	inline Real NormalDistribution::mgf(Real phi) const
	{

	}

	inline Real NormalDistribution::standardNormalPdf(Real z)
	{
		static const Real pdfCoef = 1.0 / std::sqrt(2.0 * PI);
		return pdfCoef * std::exp(-0.5 * z * z);
	}

	inline Real NormalDistribution::standardNormalCdf(Real z)
	{
		return (z > 0.0) ?
			interpolateStandardNormalCdf(z) :
			(1.0 - interpolateStandardNormalCdf(-z));
	}
}