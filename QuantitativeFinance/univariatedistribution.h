#pragma once

#include "parametricmodel.h"

namespace QuantitativeFinance
{
	template<typename T>
	class UnivariateDistribution : public ParametricModel
	{
	protected:
		UnivariateDistribution(Parameter parameter);
	public:
		virtual Real cdf(T x) const = 0;
		virtual Real pdf(T x) const = 0;
		virtual T quantile(Real p) const = 0;
		virtual Real mean() const = 0;
		virtual Real var() const = 0;
		virtual Real mgf(Real phi) const = 0;
	};

	template<typename T>
	inline UnivariateDistribution<T>::UnivariateDistribution(Parameter parameter) :
		UnivariateDistribution(parameter)
	{}

	using ContinuousDistribution = UnivariateDistribution<Real>;
	using DiscreteDistribution = UnivariateDistribution<Natural>;
}