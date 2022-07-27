#pragma once

#include <boost/math/special_functions/owens_t.hpp>

#include "normaldistribution.h"
#include "steffensensolver.h"
#include "utility.h"

namespace QuantitativeFinance
{

	class SkewNormalDistribution : public NormalDistribution
	{
		Real delta_;
		Real pdfScalar_;
		static SteffensenSolver quantileSolver_;

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

		static SteffensenSolver& quantileSolver();
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
		return standardNormalCdf(z) - 2.0 * boost::math::owens_t(z, parameter("alpha"));
	}

	inline Real SkewNormalDistribution::quantile(Real p) const
	{
		auto objectFunction = [this, p](Real x) -> Real {return cdf(x) - p; };
		auto result = quantileSolver_.solve(objectFunction, mean());
		if (result.convergence == RootFindingResult::Convergence::MAX_ITER_REACH)
		{
			WARNING("iteration reaches limits");
		}
		return result.x;
	}

	inline Real SkewNormalDistribution::mean() const
	{
		static const Real meanScalar = std::sqrt(2.0 / PI);
		return parameter("mu") + parameter("sigma") * delta_ * meanScalar;
	}

	inline Real SkewNormalDistribution::var() const
	{
		static const Real varScalar = 2.0 / PI;
		return parameter("sigma") * parameter("sigma") * (1.0 - delta_ * delta_ * varScalar);
	}

	inline Real SkewNormalDistribution::mgf(Real phi) const
	{
		Real sigma = parameter("sigma");
		Real z1 = parameter("mu") * phi + 0.5 * sigma * sigma * phi * phi;
		Real z2 = delta_ * sigma * phi;
		return 2.0 * std::exp(z1) * standardNormalCdf(z2);
	}

	inline SteffensenSolver& SkewNormalDistribution::quantileSolver()
	{
		return quantileSolver_;
	}
}