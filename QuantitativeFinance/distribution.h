#pragma once

#include "parametricmodel.h"

namespace QuantitativeFinance
{
	class ContinuousDistribution : public ParametricModel
	{
	protected:
		ContinuousDistribution(Parameter parameter);
	public:
		virtual Real cdf(Real x) const = 0;
		virtual Real pdf(Real x) const  = 0;
		virtual Real quantile(Real p) const  = 0;
		virtual Real mean() const = 0;
		virtual Real var() const = 0;
		virtual Real mgf(Real phi) const = 0;
	};

	inline ContinuousDistribution::ContinuousDistribution(Parameter parameter):
		ParametricModel(parameter)
	{}

	class DiscreteDistribution : public ParametricModel
	{
	protected:
		DiscreteDistribution(Parameter parameter);
	public:
		virtual Real cdf(Natural x) const  = 0;
		virtual Real pmf(Natural x) const = 0;
		virtual Real quantile(Real p) const = 0;
		virtual Real mean() const = 0;
		virtual Real median() const = 0;
		virtual Real var() const = 0;
		virtual Real mgf(Real phi) const = 0;
	};

	inline DiscreteDistribution::DiscreteDistribution(Parameter parameter) :
		ParametricModel(parameter)
	{}
}